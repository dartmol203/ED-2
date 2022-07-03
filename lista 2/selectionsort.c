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

void ordenaSelection(int vet[], int l, int r)
{
    int i, j;
    for (i = 0; i < r - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < r; j++)
        {
            if (LESS(vet[j], vet[min]))
                min = j;
        }
        EXCH(vet[min], vet[i]);
    }
}

int main()
{

    int vet[1000], qnt = 0, i;

    while (scanf(" %d", &vet[qnt]) != EOF)
    {
        qnt++;
    }

    ordenaSelection(vet, 0, qnt);

    for (i = 0; i < qnt - 1; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("%d\n", vet[i]);

    return 0;
}