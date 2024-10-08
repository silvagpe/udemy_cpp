#include <iostream>

using namespace std;

void exemploDeConstantes()
{
    const int vet[] = {1, 2, 3};
    const int *p1 = &vet[0];
    int const *p2 = &vet[1];

    int *const p3 = new int[3];

    //Esse exemplo não permite nem alterar o valor nem o ponteiro
    const char* const p4 = "Silva";

    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;

    *p3 = 1;
    *(p3 + 1) = 2;
    *(p3 + 2) = 3;

    cout << "P3:" << endl;
    cout << *p3 << endl;
    cout << *(p3 + 1) << endl;
    cout << *(p3 + 2) << endl;

    *p3 = 10;
    cout << "Valor modificado: " << *p3 << endl;
    
    cout << "Valor p4: " << *(p4+1) << endl;

}

int main(int argc, char const *argv[])
{
    exemploDeConstantes();
    return 0;
}
