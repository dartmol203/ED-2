#include <stdio.h>

#define LESS(A, B) (A < B)
#define EXCH(A, B) \
    {              \
        int t = B; \
        B = A;     \
        A = t;     \
    }
#define CMPEXCH(A, B)   \
    {                   \
        if (LESS(B, A)) \
            EXCH(A, B); \
    }

void ordenaBubble(int vet[], int l, int r)
{
    int i, j;
    for (i = 0; i < r - 1; i++)
    {
        for (j = 0; j < r - 1; j++)
        {
            CMPEXCH(vet[j], vet[j + 1]);
        }
    }
}

int main()
{

    int vet[1000], qnt = 0, i;

    while (scanf(" %d", &vet[qnt]) != EOF)
    {
        qnt++;
    }

    ordenaBubble(vet, 0, qnt);

    for (i = 0; i < qnt - 1; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("%d\n", vet[i]);

    return 0;
}