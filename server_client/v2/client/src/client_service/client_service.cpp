#include <arpa/inet.h>
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>

class ClientService
{
private:
    int sock = 0;
    int port = 0;
    struct sockaddr_in serv_addr;
    std::filesystem::path file_path;

    int start_connection()
    {    
        // Criar socket
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            std::cout << "Erro ao criar socket" << std::endl;
            return -1;
        }

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(this->port);

        // Converter o endereço IP de string para binário
        if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
        {
            std::cout << "Endereço inválido ou não suportado" << std::endl;
            return -1;
        }

        // Conectar ao servidor
        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
            std::cout << "Conexão falhou" << std::endl;
            return -1;
        }
    }

    // Função para serializar uma string
    std::vector<uint8_t> serialize_string(const std::string &str)
    {
        std::vector<uint8_t> buffer;

        // Adicionar o tamanho da string (4 bytes - int)
        int length = str.size();
        buffer.insert(buffer.end(), reinterpret_cast<uint8_t *>(&length), reinterpret_cast<uint8_t *>(&length) + sizeof(int));

        // Adicionar os bytes da string
        buffer.insert(buffer.end(), str.begin(), str.end());

        return buffer;
    }

    // Função para enviar uma linha CSV genérica
    void send_csv_data(int sock, const std::vector<std::string> &fields)
    {
        std::vector<uint8_t> buffer;

        // Criar o header: número de campos
        int num_fields = fields.size();
        buffer.insert(buffer.end(), reinterpret_cast<uint8_t *>(&num_fields), reinterpret_cast<uint8_t *>(&num_fields) + sizeof(int));

        // Serializar cada campo e adicionar ao buffer
        for (const std::string &field : fields)
        {
            std::vector<uint8_t> serialized_field = serialize_string(field);
            buffer.insert(buffer.end(), serialized_field.begin(), serialized_field.end());
        }

        // Adicionar o tamanho total do payload (como header)
        int payload_size = buffer.size();
        std::vector<uint8_t> total_buffer;
        total_buffer.insert(total_buffer.end(), reinterpret_cast<uint8_t *>(&payload_size), reinterpret_cast<uint8_t *>(&payload_size) + sizeof(int));

        // Adicionar o buffer completo (header + payload)
        total_buffer.insert(total_buffer.end(), buffer.begin(), buffer.end());

        // Enviar os dados ao servidor
        send(sock, total_buffer.data(), total_buffer.size(), 0);
        std::cout << "Dados CSV enviados ao servidor" << std::endl;
    }    

public:
    ClientService(int port, std::filesystem::path file);
    ~ClientService();

    void send_data(){
        // Linha CSV genérica
        std::vector<std::string> csv_data = {
            "150000", "2016-01-01", "Chris Riley", "trailhead9.ub20k5i9t8ou@example.com"};
    }
};

ClientService::ClientService(int port, std::filesystem::path file)
{
    this->port = port;
    this->file_path = file;
}

ClientService::~ClientService()
{
}