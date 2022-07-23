// Código não foi produzido por mim.

#include <stdlib.h>
#include <stdio.h>
typedef int Item;
#define less(A, B) ((A) < (B))
#define lesseq(A, B) ((A) <= (B))
#define exch(A, B)  \
    {               \
        Item T = A; \
        A = B;      \
        B = T;      \
    }
#define cmpexch(A, B)   \
    {                   \
        if (less(B, A)) \
            exch(A, B); \
    }

int separa(Item *v, int l, int r)
{
    int i = l - 1, j = r;
    Item c = v[r];

    for (;;)
    {
        while (less(v[++i], c))
            ;
        while (less(c, v[--j]))
            if (i == j)
                break;
        if (i >= j)
            break;
        exch(v[i], v[j]);
    }

    exch(v[i], v[r]);
    return i;
}

void quickSelect(Item *v, int l, int r, int p)
{
    int j = separa(v, l, r);
    if (j == p)
        return;
    else if (j < p)
    {
        quickSelect(v, j + 1, r, p);
    }
    else
    {
        quickSelect(v, l, j - 1, p);
    }
}

void quickSort(Item *v, int l, int r)
{
    if (l >= r)
        return;
    cmpexch(v[(l + r) / 2], v[r]);
    cmpexch(v[l], v[(l + r) / 2]);
    cmpexch(v[r], v[(l + r) / 2]);

    int j = separa(v, l, r);
    quickSort(v, l, j - 1);
    quickSort(v, j + 1, r);
}

int main()
{
    int n, p, x;
    scanf("%d %d %d", &n, &p, &x);

    Item *v = malloc(sizeof(Item) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    int inicio = x * p, fim = inicio + x;
    if (fim >= n)
        fim = n - 1;

    quickSelect(v, 0, n - 1, inicio);
    quickSelect(v, inicio, n - 1, fim);
    quickSort(v, inicio, fim);

    int fimP = (fim + 1 == n) ? fim + 1 : fim;
    for (int i = inicio; i < fimP; i++)
    {
        printf("%d\n", v[i]);
    }
    free(v);
    return 0;
}