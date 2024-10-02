#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    const char *hello = "Hello from client";
    char buffer[1024] = {0};

    // Criar o socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "Erro ao criar socket" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Converter o endereço IP do servidor para o formato correto
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cout << "Endereço inválido ou não suportado" << std::endl;
        return -1;
    }

    // Conectar ao servidor
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Conexão falhou" << std::endl;
        return -1;
    }

    // Enviar mensagem ao servidor
    send(sock, hello, strlen(hello), 0);
    std::cout << "Mensagem enviada ao servidor" << std::endl;

    // Receber resposta do servidor
    read(sock, buffer, 1024);
    std::cout << "Mensagem do servidor: " << buffer << std::endl;

    // Fechar o socket
    close(sock);
    return 0;
}
