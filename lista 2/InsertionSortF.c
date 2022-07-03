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

void insertionsort(int *v, int l, int r)
{
    for (int i = r; i > l; i--)
        CMPEXCH(v[i - 1], v[i]);

    for (int i = l + 2; i <= r; i++)
    {
        int j = i;
        int tmp = v[j];
        while (LESS(tmp, v[j - 1]))
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = tmp;
    }
}

int main()
{

    int vet[50000], qnt = 0, i;

    while (scanf(" %d", &vet[qnt]) != EOF)
    {
        qnt++;
    }

    insertionsort(vet, 0, qnt - 1);

    for (i = 0; i < qnt - 1; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("%d\n", vet[i]);

    return 0;
}