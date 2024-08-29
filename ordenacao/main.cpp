#include <iostream>
#include <string.h>
#define MAX_CARROS 10

using namespace std;

class Carro
{
public:
    char nome[100];
    double preco;
};

void ordenacao(Carro carros[MAX_CARROS], int length){

    for (int i = 0; i < length; i++)
    {
        for (int j = i+1; j < length; j++)
        {
            int comp = strcmp(carros[i].nome, carros[j].nome);
            if (comp > 0){
                Carro aux = carros[i];
                carros[i] = carros[j];
                carros[j] = aux;
            }
        }        
    }
}

int main(int argc, char const *argv[])
{
    Carro carros[MAX_CARROS];
    int countCarros = 0;

    // while (true)
    // {
    //     cout << "Digite o nome de um carro: ";
    //     cin >> carros[countCarros].nome;
    //     cout << "Digite o preco: ";
    //     cin >> carros[countCarros].preco;
    //     countCarros++;
        
    //     cout<< "Deseja continuar? <S>im ou <N>ao: " << endl;
    //     char resp;
    //     cin >> resp;
    //     if (resp != 's') break;

    // }
    strcpy(carros[0].nome, "fusca");
    carros[0].preco = 10;
    strcpy(carros[1].nome, "camaro");
    carros[1].preco = 100;
    strcpy(carros[2].nome, "audi");
    carros[2].preco = 120;

    countCarros = 3;

    cout << endl;
    cout << "Lista original de carros: " << endl;

    for (int i = 0; i < countCarros; i++)
    {
        cout << i << " - " << carros[i].nome << " preço: " << carros[i].preco << endl;
    }
    
    cout << endl;
    cout << "Lista ordenada de carros: " << endl;

    ordenacao(carros, countCarros);
    for (int i = 0; i < countCarros; i++)
    {
        cout << i << " - " << carros[i].nome << " preço: " << carros[i].preco << endl;
    }

    return 0;
}
