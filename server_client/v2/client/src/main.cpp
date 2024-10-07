#include <iostream>
#include <cstring>
#include <vector>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "csv/csv_reader.h"

namespace csv_client
{
    



#define PORT 8080

// Função para serializar uma string
std::vector<uint8_t> serialize_string(const std::string& str) {
    std::vector<uint8_t> buffer;

    // Adicionar o tamanho da string (4 bytes - int)
    int length = str.size();
    buffer.insert(buffer.end(), reinterpret_cast<uint8_t*>(&length), reinterpret_cast<uint8_t*>(&length) + sizeof(int));

    // Adicionar os bytes da string
    buffer.insert(buffer.end(), str.begin(), str.end());

    return buffer;
}

void log(const std::string &msg, const int &offset){
    std::cout << msg << offset << std::endl;
}
void log(const std::string &msg){
    std::cout << msg << std::endl;
}
void increment_offset(int &offset, int value){

    std::cout << "Offset original: " << offset << std::endl;
    offset+=value;
    std::cout << "Offset final: " << offset << std::endl;
}

// Função para desserializar uma string
std::string deserialize_string(const std::vector<uint8_t>& buffer, int& offset) {
    // Pegar o tamanho da string (4 bytes)
    int length = *reinterpret_cast<const int*>(&buffer[offset]);
    log("deserialize length: ", length);
    increment_offset(offset, sizeof(int));

    // Pegar a string
    std::string str(buffer.begin() + offset, buffer.begin() + offset + length);
    increment_offset(offset, length);

    log("deserialize str: " + str);

    return str;
}

void receive_csv_data(std::vector<uint8_t> total_buffer) {
    
    // Primeiro, ler o tamanho do payload
    int offset = 0;
    int payload_size = *reinterpret_cast<int*>(&total_buffer[offset]);
    std::cout << "Tamanho payload: " << payload_size << std::endl;
    increment_offset(offset, sizeof(int));
    

    int num_fields = *reinterpret_cast<int*>(&total_buffer[offset]);
    std::cout << "Número de campos: " << num_fields << std::endl;
    increment_offset(offset, sizeof(int));    

    // Desserializar cada campo
    for (int i = 0; i < num_fields; i++) {        
        std::string field = deserialize_string(total_buffer, offset);
        std::cout << "Campo " << i + 1 << ": " << field << std::endl;        
    }

}

// Função para enviar uma linha CSV genérica
void send_csv_data(int sock, const std::vector<std::string>& fields) {
    std::vector<uint8_t> buffer;

    // Criar o header: número de campos
    int num_fields = fields.size();
    buffer.insert(buffer.end(), reinterpret_cast<uint8_t*>(&num_fields), reinterpret_cast<uint8_t*>(&num_fields) + sizeof(int));

    // Serializar cada campo e adicionar ao buffer
    for (const std::string& field : fields) {
        std::vector<uint8_t> serialized_field = serialize_string(field);
        buffer.insert(buffer.end(), serialized_field.begin(), serialized_field.end());
    }

    // Adicionar o tamanho total do payload (como header)
    int payload_size = buffer.size();
    std::vector<uint8_t> total_buffer;
    total_buffer.insert(total_buffer.end(), reinterpret_cast<uint8_t*>(&payload_size), reinterpret_cast<uint8_t*>(&payload_size) + sizeof(int));

    // Adicionar o buffer completo (header + payload)
    total_buffer.insert(total_buffer.end(), buffer.begin(), buffer.end());


    log("Total buffer:", total_buffer.size());
    for (int i = 0; i < total_buffer.size(); i++) {          
        std::cout << i << " :" << total_buffer[i] << std::endl;        
    }

    // Enviar os dados ao servidor
    //send(sock, total_buffer.data(), total_buffer.size(), 0);
    //std::cout << "Dados CSV enviados ao servidor" << std::endl;
    receive_csv_data(total_buffer);
}

} // namespace name

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;

    csv_client::csv::csv_reader::CsvReader reader;
    reader.openFile();
    

    

    exit(0);

    // Linha CSV genérica
    std::vector<std::string> csv_data = {
        "150000", "2016-01-01", "Chris Riley", "trailhead9.ub20k5i9t8ou@example.com"
    };

    // Criar socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "Erro ao criar socket" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Converter o endereço IP de string para binário
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cout << "Endereço inválido ou não suportado" << std::endl;
        return -1;
    }

    // Conectar ao servidor
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Conexão falhou" << std::endl;
        return -1;
    }

    // Enviar linha CSV como dados binários
    csv_client::send_csv_data(sock, csv_data);

    // Fechar o socket
    close(sock);

    return 0;
}

