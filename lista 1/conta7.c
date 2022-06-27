#include <stdio.h>

long int conta7(long int entrada)
{
    if (entrada == 0)
    {
        return 0;
    }
    else
    {
        if (entrada % 10 == 7)
        {
            return 1 + conta7(entrada / 10);
        }
        else
        {
            return 0 + conta7(entrada / 10);
        }
    }
}

int main()
{

    long int entrada;

    scanf("%ld", &entrada);

    entrada = conta7(entrada);

    printf("%d\n", entrada);

    return 0;
}