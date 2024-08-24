#include <iostream>
#include <string.h>

using namespace std;

//o typedef permite que você instancie um objeto da estrutura sem precisar usar a palavra struct:
typedef struct Pessoa
{
    char nome[100];
    int idade;
    int numSorte;

    // Construtor padrão
    Pessoa() : idade(0), numSorte(0) {
        strcpy(this->nome, "");
    }

    Pessoa(char nome[100], int idade){
        strcpy(this->nome, nome);
        this->idade = idade;
        this->numSorte = 0;  // Inicializando numSorte para evitar valores indeterminados
    }

    //Protótipo do construtor
    Pessoa(int idade, int numSorte);

    void setIdade(int idade){
        this->idade = idade;
    }

    int getIdade(){
        return this->idade;
    }

} t_pessoa;

//Essa expressão permite separar o código do construtor da classe 
//Aviso!!! Essa abordagem só funciona para classes ou structs sem a paravra chave typedef
Pessoa::Pessoa(int idade, int numSorte){
    this->idade = idade;
    this->numSorte = numSorte;
}

void exemplo1()
{
    t_pessoa p;

    strcpy(p.nome, "silva");
    p.idade = 40;

    cout << "Nome: " << p.nome << endl;
    cout << "Idade: " << p.idade << endl;

    p.setIdade(41);
    cout << "GetIdade: " << p.getIdade() << endl;

    Pessoa p2("teste", 2);
    cout << "Pessoa 2 nome: " << p2.nome << " idade: " << p2.getIdade() << endl;

    Pessoa pSorte(10, 15);
    cout << "Pessoa sorte. Idade: " << pSorte.getIdade() << " numSorte: " << p2.numSorte << endl;

}

void exemplo2_Ponteiros()
{
    t_pessoa pessoas[100];
    t_pessoa* p;

    p = &pessoas[0];

    pessoas[0].idade = 10;
    pessoas[1].idade = 11;
    pessoas[2].idade = 12;

    cout << p->idade << endl;    
    cout << (p+1)->idade << endl;    
    cout << (p+2)->idade << endl;    
}


int main(int argc, char const *argv[])
{
    exemplo1();
    exemplo2_Ponteiros();
    return 0;
}
