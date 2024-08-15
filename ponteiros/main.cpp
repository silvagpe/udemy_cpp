#include <iostream>

using namespace std;


void exemplo_simples_de_ponteiro(){
    //Variável simples;
    int var = 10;
    //Definição de um ponteiro
    int *pvar;
    //Atribuir o pontairo para a marcação da memória de var;
    pvar = &var;

    //Imprime o valor de var porque o ponteiro de var está apontando para o mesmo lugar da memória de var
    cout << *pvar <<endl;

    //Imprime o valor da variável var
    cout << var << endl;

}

void exemplo_de_passagem_de_valor_por_ponteiro_passagem_por_valor(int n){
    n = 20;
}

void exemplo_de_passagem_de_valor_por_ponteiro_passagem_por_referencia(int *n){
    *n = 20;
}

void exemplo_de_passagem_de_valor_por_ponteiro(){

    //Variável simples;
    int var = 10;
    //Definição de um ponteiro
    int *pvar;
    //Atribuir o pontairo para a marcação da memória de var;
    pvar = &var;

    //Exemplo de passagem por valor (cópia)
    exemplo_de_passagem_de_valor_por_ponteiro_passagem_por_valor(var);

    //Imprime o valor da variável var
    cout << var << endl;

    //Exemplo de passagem por referência 
    //Opção 1: passando o ponteiro
    // exemplo_de_passagem_de_valor_por_ponteiro_passagem_por_referencia(pvar);
    //Opção 2: passando a referência da variável
    exemplo_de_passagem_de_valor_por_ponteiro_passagem_por_referencia(&var);

    //Imprime o valor da variável var
    cout << var << endl;

}

void exemplo_de_ponteiro_usando_new(){}

int main(int argc, char const *argv[])
{
    exemplo_simples_de_ponteiro();
    exemplo_de_passagem_de_valor_por_ponteiro();
    /* code */
    return 0;
}
