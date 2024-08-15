#include <sstream>
#include <string.h>
#include <vector>
#include <iostream>
#include "main.h"

using namespace std;

void log(string texto)
{
    cout << texto << endl;
}
void linha()
{
    cout << "----------------------------------------------------------------------------" << endl;
}

void inverteString(char nome[])
{
    // Opção 1 para contar o tamanho do array
    // int tamanho = sizeof(nome) / sizeof(nome[0]);

    // Opção 2 - usando um for
    //  int tamanho;
    //  for (tamanho = 0; nome[tamanho]; tamanho++){}

    // Opção 3
    int tamanho = strlen(nome);

    std::stringstream ss;
    ss << "O tamanho do array é " << tamanho;
    log(ss.str());

    cout << "Nome original: " << nome << " | Nome invertido: ";
    for (int i = tamanho - 1; i >= 0; i--)
    {
        cout << nome[i];
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    inverterNome();

    exemploTamanhoVetor();

    exemploPercorrendoVetorDeChars();

    exemploUsandoVetorDeCharComoString();

    log("Exemplo: Vetor simples int[]");
    int vetor[4] = {1, 2, 3, 4};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    for (int i = 0; i < tamanho; i++)
    {
        cout << vetor[i] << endl;
    }
    linha();

    return 0;
}
void exemploPercorrendoVetorDeChars()
{
    log("Percorrendo o vetor de chars");
    char nome[] = {'m', 'a', 'r', 'c', 'o', 's', '\0'};
    int i = 0;
    while (nome[i])
    {
        cout << nome[i];
        i++;
    }
    cout << endl;
    linha();
}

void exemploUsandoVetorDeCharComoString()
{
    log("Exemplo: Usando um vetor de char como string");
    char nome2[] = "Silva";
    int i = 0;    
    while (nome2[i] != '\0')
        cout << nome2[i++];
    cout << endl;
    linha();
}

void exemploTamanhoVetor()
{
    log("Exemplo: Tamanho vetor");
    char vetorC[6] = {'1', '2', '3', '4', '5'};
    cout << "Tamanho em bityes de um array de char[5] -> " << sizeof(vetorC) << endl;
    linha();
}

void inverterNome()
{
    log("Exemplo: Inverter um texto");
    char nome3[] = "Rafael";
    inverteString(nome3);
    linha();
} // Exemplo 1
//  int main(int argc, char *argv[])
//  {
//      int vetor[100];

//     for (int i = 0; i < 100; i++)
//     {
//         vetor[i] = i;
//     }

//     for (int i = 0; i < 100; i++)
//     {
//         cout << vetor[i] << endl;
//     }

//     return 0;
// }
