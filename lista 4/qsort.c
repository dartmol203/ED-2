#include <stdio.h>
#include <stdlib.h>

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

int separa(int *v, int l, int r)
{
    int c = v[r]; // pivô
    int t, j = l;
    for (int k = l; /*A*/ k < r; ++k)
        if (v[k] <= c)
        {
            t = v[j], v[j] = v[k], v[k] = t;
            ++j;
        }
    t = v[j], v[j] = v[r], v[r] = t;
    return j;

    return j;
}

void quickSort(int *v, int l, int r)
{
    if (r <= l)
        return;

    CMPEXCH(v[(l + r) / 2], v[r]);
    CMPEXCH(v[l], v[(l + r) / 2]);
    CMPEXCH(v[r], v[(l + r) / 2]);

    int j = separa(v, l, r);
    quickSort(v, l, j - 1);
    quickSort(v, j + 1, r);
}

int main()
{

    int qnt, vet[100000];
    scanf("%d", &qnt);

    for (int i = 0; i < qnt; i++)
    {
        scanf("%d", &vet[i]);
    }

    quickSort(vet, 0, qnt - 1);

    for (int i = 0; i < qnt - 1; i++)
        printf("%d ", vet[i]);

    printf("%d\n", vet[qnt - 1]);

    return 0;
}