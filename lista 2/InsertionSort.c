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

void insertionsortSlow(int *v, int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        int j = i;
        for (j = i; j > l; j--)
            CMPEXCH(v[j - 1], v[j]);
    }
}

int main()
{

    int vet[1000], qnt = 0, i;

    while (scanf(" %d", &vet[qnt]) != EOF)
    {
        qnt++;
    }

    insertionsortSlow(vet, 0, qnt - 1);

    for (i = 0; i < qnt - 1; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("%d\n", vet[i]);

    return 0;
}