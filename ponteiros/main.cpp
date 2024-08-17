#include <iostream>

using namespace std;

void exemplo_simples_de_ponteiro()
{
    // Variável simples;
    int var = 10;
    // Definição de um ponteiro
    int *pvar;
    // Atribuir o pontairo para a marcação da memória de var;
    pvar = &var;

    // Imprime o valor de var porque o ponteiro de var está apontando para o mesmo lugar da memória de var
    cout << *pvar << endl;

    // Imprime o valor da variável var
    cout << var << endl;
}

void exemplo_de_passagem_de_valor_por_ponteiro_passagem_por_valor(int n)
{
    n = 20;
}

void exemplo_de_passagem_de_valor_por_ponteiro_passagem_por_referencia(int *n)
{
    *n = 20;
}

void exemplo_de_passagem_de_valor_por_ponteiro()
{

    // Variável simples;
    int var = 10;
    // Definição de um ponteiro
    int *pvar;
    // Atribuir o pontairo para a marcação da memória de var;
    pvar = &var;

    // Exemplo de passagem por valor (cópia)
    exemplo_de_passagem_de_valor_por_ponteiro_passagem_por_valor(var);

    // Imprime o valor da variável var
    cout << var << endl;

    // Exemplo de passagem por referência
    // Opção 1: passando o ponteiro
    //  exemplo_de_passagem_de_valor_por_ponteiro_passagem_por_referencia(pvar);
    // Opção 2: passando a referência da variável
    exemplo_de_passagem_de_valor_por_ponteiro_passagem_por_referencia(&var);

    // Imprime o valor da variável var
    cout << var << endl;
}

void exemplo_de_ponteiro_2()
{
    int array[] = {99, 2, 3, 4, 5};

    // Ponteiro para a posição 0 da memória do array
    int *parray = &array[0];

    // Mostra o valor na posição 1 do array
    cout << "Valor do array: " << array[1] << endl;

    // Mostra o valor da posição 0 + 1 do array
    cout << "Valor do ponteiro na posicao 1: " << *(parray + 1) << endl;

    // Exemplo sem o uso dos () ocorre a operação matemática, pega-se o valor da posição zero e adiciona 10
    cout << "Sem uso dos () nesse caso ocorre a opração matematica : " << *parray + 10 << endl;
}

void invertendoUmaStringComPonteiros()
{
    char nome[] = "SilvaSi";
    int tam = strlen(nome);
    char *p = &nome[tam - 1];
    char *pini = &nome[0];

    while (true)
    {
        cout << *p;
        if (p == pini)
            break;

        p--;
    }

    cout << endl;
}

int myStrLen(char *str){
    int tam = 0;
    while (*str != '\0')
    {
        str++;
        tam++;
    }

    return tam;
}

char* myContact(char *val1, char *val2){
    int tam1 = myStrLen(val1);
    int tam2 = myStrLen(val2);

    char *resultado = new char[tam1+tam2];
    //Criar um ponteiro para o resultado e fazer com que o ponteira preencha o resutlado
    char *pResult = resultado;
    while (*val1 != '\0')
    {
        *pResult = *val1;
        pResult++;
        val1++;
    }

    while (*val2 != '\0')
    {
        *pResult = *val2;
        pResult++;
        val2++;
    }
    *pResult= '\0';

    return resultado;
}

void exemploContactenarStrings(){

    char *nome = "Rafael";
    char *sobreNome = "Silva";

    cout << "Resultado :" << myContact(nome, sobreNome) << "\n";
}


int main(int argc, char const *argv[])
{
    exemplo_simples_de_ponteiro();
    exemplo_de_passagem_de_valor_por_ponteiro();
    exemplo_de_ponteiro_2();
    invertendoUmaStringComPonteiros();
    exemploContactenarStrings();

    /* code */
    return 0;
}
