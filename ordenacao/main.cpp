#include <iostream>
#define MAX_CARROS 10

using namespace std;

class Carro
{
public:
    char nome[100];
    double preco;
};

void

int main(int argc, char const *argv[])
{
    Carro carros[MAX_CARROS];
    int countCarros = 0;

    while (true)
    {
        cout << "Digite o nome de um carro: ";
        cin >> carros[countCarros].nome;
        cout << "Digite o preco: ";
        cin >> carros[countCarros].preco;
        countCarros++;
        
        cout<< "Deseja continuar? <S>im ou <N>ao: " << endl;
        char resp;
        cin >> resp;
        if (resp != 's') break;

    }
    cout << endl;
    cout << "Lista original de carros: " << endl;

    for (int i = 0; i < countCarros; i++)
    {
        cout << i << " - " << carros[i].nome << " preço: " << carros[i].preco << endl;
    }
    
    cout << endl;
    cout << "Lista ordenada de carros: " << endl;

    return 0;
}
