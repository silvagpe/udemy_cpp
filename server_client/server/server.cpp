#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char *hello = "Hello from server";

    // Criar o socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Falha ao criar socket");
        exit(EXIT_FAILURE);
    }

    // Forçar o socket a se reutilizar
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Falha no setsockopt");
        exit(EXIT_FAILURE);
    }

    // Definir o endereço do servidor
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind o socket ao endereço e porta
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Falha no bind");
        exit(EXIT_FAILURE);
    }

    // Escutar por conexões
    if (listen(server_fd, 3) < 0) {
        perror("Falha no listen");
        exit(EXIT_FAILURE);
    }

    // Aceitar a conexão
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("Falha no accept");
        exit(EXIT_FAILURE);
    }

    // Ler mensagem do cliente
    read(new_socket, buffer, 1024);
    std::cout << "Mensagem do cliente: " << buffer << std::endl;

    // Enviar resposta ao cliente
    send(new_socket, hello, strlen(hello), 0);
    std::cout << "Mensagem enviada ao cliente" << std::endl;

    // Fechar o socket
    close(new_socket);
    close(server_fd);
    return 0;
}
