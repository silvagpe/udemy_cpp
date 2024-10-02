#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

// Função para desserializar uma string
std::string deserialize_string(const std::vector<uint8_t>& buffer, int& offset) {
    // Pegar o tamanho da string (4 bytes)
    int length = *reinterpret_cast<const int*>(&buffer[offset]);
    offset += sizeof(int);

    // Pegar a string
    std::string str(buffer.begin() + offset, buffer.begin() + offset + length);
    offset += length;

    return str;
}

// Função para receber e desserializar os dados CSV
void receive_csv_data(int client_socket) {
    // Primeiro, ler o tamanho do payload
    int payload_size;
    read(client_socket, &payload_size, sizeof(int));

    // Ler o payload completo
    std::vector<uint8_t> buffer(payload_size);
    read(client_socket, buffer.data(), payload_size);

    int offset = 0;

    // Ler o número de campos
    int num_fields = *reinterpret_cast<int*>(&buffer[offset]);
    offset += sizeof(int);

    std::cout << "Número de campos: " << num_fields << std::endl;

    // Desserializar cada campo
    for (int i = 0; i < num_fields; i++) {
        std::string field = deserialize_string(buffer, offset);
        std::cout << "Campo " << i + 1 << ": " << field << std::endl;
    }
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Criar socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Falha ao criar socket");
        exit(EXIT_FAILURE);
    }

    // Configurar o endereço do servidor
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Associar socket à porta
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Falha no bind");
        exit(EXIT_FAILURE);
    }

    // Escutar por conexões
    if (listen(server_fd, 3) < 0) {
        perror("Falha no listen");
        exit(EXIT_FAILURE);
    }

    // Aceitar a conexão do cliente
    if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Falha no accept");
        exit(EXIT_FAILURE);
    }

    // Receber e processar os dados CSV do cliente
    receive_csv_data(client_socket);

    // Fechar o socket
    close(client_socket);
    close(server_fd);

    return 0;
}
