#include <sstream>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

void log(string texto)
{
    cout << texto << endl;
}

template <typename... Args>
void log(Args... args)
{
    // Usando "fold expression" (C++17) para expandir os argumentos
    (std::cout << ... << args) << std::endl;
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

    log("O tamanho do array e: ", tamanho);

    cout << "Nome original: " << nome << " | Nome invertido: ";
    for (int i = tamanho - 1; i >= 0; i--)
    {
        cout << nome[i];
    }
    cout << endl;
}

void exemploDeVetorSimples()
{
    log("Exemplo: Vetor simples int[]");
    int vetor[4] = {1, 2, 3, 4};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    for (int i = 0; i < tamanho; i++)
    {
        cout << vetor[i] << endl;
    }
    linha();
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
}

void testeSeOValorDaStringENumerico(char valor)
{

    if (isalpha(valor))
    {
        log("caracter alfabetico");
    }
    else
    {
        log("caracter numerico");
    }
}

void testeSeEUmDigito(char valor)
{

    if (isdigit(valor))
    {
        log("O valor '", valor, "' e um digito");
    }
    else
    {
        log("O valor '", valor, "' nao e um digito");
    }
}

void testeSeEMaiuscula(char valor)
{

    if (isupper(valor))
    {
        log("O valor '", valor, "' esta em caixa alta");
    }
    else
    {
        log("O valor '", valor, "' nao esta em caixa alta");
    }
}

void testeSeStringsSaoIguais(char valor[], char valor2[])
{

    if (strcmp(valor, valor2) == 0)
    {
        log("O valor1 e igual ao valor2");
    }
    else
    {
        log("O valor1 e diferente do valor2");
    }
}

void testaSeUmaStringExisteEmOutra()
{

    char str1[100], str2[100];
    log("Digite a primeira string");
    cin >> str1;
    log("Digite a segunda string");
    cin >> str2;

    if (strstr(str1, str2))
    {
        log("E uma substring");
    }
    else
    {
        log("Nao e uma substring");
    }
}

int main(int argc, char *argv[])
{
    inverterNome();

    exemploTamanhoVetor();

    exemploPercorrendoVetorDeChars();

    exemploUsandoVetorDeCharComoString();

    exemploDeVetorSimples();

    testeSeOValorDaStringENumerico('a');
    testeSeOValorDaStringENumerico('1');

    testeSeEUmDigito('a');
    testeSeEUmDigito('2');

    testeSeEMaiuscula('A');
    testeSeEMaiuscula('b');

    testeSeStringsSaoIguais("Rafael", "Rafael");
    testeSeStringsSaoIguais("Rafael", "Rafael2");
    
    //testaSeUmaStringExisteEmOutra();

    return 0;
}

// Exemplo 1
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
