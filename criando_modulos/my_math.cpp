/*Modulo de funções matemáticas */

int fatorial(int n)
{
    int fat = 1;
    for (int i = 0; i < n; i++)
    {
        fat = fat * (i + 1);
    }
    return fat;
}

int area_quadrado(int lado)
{
    return lado * lado;
}

int area_retangulo(int lado, int base)
{
    return lado * base;
}
