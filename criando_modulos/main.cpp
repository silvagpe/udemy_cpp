#include "my_math.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

    int n = 5;

    cout << "Fatorial de " << n << ": " << fatorial(n) << endl;
    cout << "Area quadrado é de " << n << ": " << area_quadrado(n) << endl;
    cout << "Area retangulo de 5x2 é de " << n << ": " << area_retangulo(5,2) << endl;

    return 0;
}
