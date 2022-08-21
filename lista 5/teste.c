#include <stdio.h>
#include <stdlib.h>

int main()
{

    int inicio, fim, vet[100000], cont = 0, contaux;

    scanf(" %d %d", &inicio, &fim);

    while (scanf(" %d", &vet[cont++]) != EOF)
        ;

    if (fim - inicio != 0)
    {
        for (int i = inicio; i <= fim; i++)
        {
            printf("%d\n", i);
            contaux = 0;
            for (int j = 0; j < cont; j++)
            {

                for (int k = 1; k < 10000; k++)
                    rand_r(&i);
                int x = rand_r(&i) % 256;
                printf("%d ", x);
                if (x == vet[j])
                {
                    contaux++;
                }
                else
                {
                    break;
                }
            }
            printf("\n%d %d\n", cont, contaux);
            if (cont == contaux)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    else
    {
        printf("%d\n", inicio);
    }

    return 0;
}