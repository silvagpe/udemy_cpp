#include <iostream>
#include <string.h>

using namespace std;

class Pessoa
{

private:
    /* data */

public:
    char nome[100];
    char cpf[20];
    int idade;
};


int getIdade(Pessoa pessoas[], const char* nome){

    int tam = sizeof(pessoas);

    for (int i = 0; i < tam; i++)
    {
        if (strcmp(nome, pessoas[i].nome) == 0){
            return pessoas[i].idade;
        }
    }
    
    return -1;

}

void exemplo3()
{
    Pessoa pessoas[3] = {
        {"Silva", "1111111", 10},
        {"Silva 2", "2222222", 20},
        {"Silva 3", "333333", 30}};

    cout << "Exemplo 3 - Nome: " << pessoas[0].nome << " cpf: " << pessoas[0].cpf << " idade: " << pessoas[0].idade << endl;
    cout << "Exemplo 3 - Nome: " << pessoas[1].nome << " cpf: " << pessoas[1].cpf << " idade: " << pessoas[1].idade << endl;
    cout << "Exemplo 3 - Nome: " << pessoas[2].nome << " cpf: " << pessoas[2].cpf << " idade: " << pessoas[2].idade << endl;


    int idade = getIdade(pessoas, "Silva 3");
    cout << "Idade Silva 3: " << idade << endl;
    
    idade = getIdade(pessoas, "nao existe");
    cout << "Idade de nao existe: " << idade << endl;
}

void exemplo2()
{
    Pessoa p1 = {"Silva", "123123", 20};

    cout << "Exemplo 2 - Nome: " << p1.nome << " cpf: " << p1.cpf << " idade: " << p1.idade << endl;
}

void exemplo1()
{
    // Inicialização por proriedades
    Pessoa p1;
    strcpy(p1.nome, "Rafael");
    strcpy(p1.cpf, "12345678901");
    p1.idade = 30;

    cout << "Exemplo 1 - Nome: " << p1.nome << " cpf: " << p1.cpf << " idade: " << p1.idade << endl;
}

int main(int argc, char const *argv[])
{
    exemplo1();
    exemplo2();
    exemplo3();
    return 0;
}
