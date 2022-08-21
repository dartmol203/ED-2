/*
#include <stdlib.h>
#include <stdio.h>

typedef struct item
{
    int key, value;
} item;

void merge(item V[], int l, int meio, int r)
{
    item *R = malloc(sizeof(item) * (r - l + 1));
    int i = l, j = meio + 1, k = 0;

    while (i <= meio && j <= r)
    {
        if (V[i].value <= V[j].value)
            R[k++] = V[i++];
        else
            R[k++] = V[j++];
    }

    while (i <= meio)
        R[k++] = V[i++];
    while (j <= r)
        R[k++] = V[j++];

    k = 0;
    for (i = l; i <= r; i++)
        V[i] = R[k++];
    free(R);
}

void mergeSort(item V[], int l, int r)
{
    if (l >= r)
        return;
    int meio = (l + r) / 2;
    mergeSort(V, l, meio);
    mergeSort(V, meio + 1, r);
    merge(V, l, meio, r);
}
int main()
{

    char entrada[101];

    while (scanf(" %s", entrada) != EOF)
    {
        item tb[130];

        for (int i = 0; i < 130; i++)
        {
            tb[i].key = i;
            tb[i].value = 0;
        }

        int i = 0;
        while (entrada[i] != '\0')
        {
            tb[entrada[i]].value++;
            i++;
        }

        mergeSort(tb, 0, 129);

        for (int i = 30; i < 129; i++)
        {
            if (tb[i].value != 0)
                printf("%d %d\n", tb[i].key, tb[i].value);
        }
        printf("%d %d\n\n", tb[129].key, tb[129].value);
    }

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

#define ull unsigned long long
#define min(a, b) (a < b ? a : b)
#define max(a, b) (b < a ? a : b)
// #define Item unsigned
#define key(x) (x)
#define less(a, b) (a.v == b.v ? a.k < b.k : a.v < b.v)
#define swap(a, b)  \
    {               \
        Item t = a; \
        a = b;      \
        b = t;      \
    }
#define cmpswap(a, b) \
    if (less(b, a))   \
    swap(a, b)

typedef struct
{
    int k, v;
} Item;

int partition(Item *v, int l, int r)
{
    Item pivot = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (less(v[k], pivot))
        {
            swap(v[k], v[j]);
            j++;
        }
    swap(v[j], v[r]);
    return j;
}

void quicksortM3(Item *v, int l, int r)
{
    if (r - l <= 32)
        return;

    swap(v[(l + r) / 2], v[r - 1]);
    cmpswap(v[l], v[r - 1]);
    cmpswap(v[l], v[r]);
    cmpswap(v[r - 1], v[r]);

    int m = partition(v, l, r);
    quicksortM3(v, l, m - 1);
    quicksortM3(v, m + 1, r);
}

void insertionsort(Item *v, int l, int r)
{
    for (int i = l + 1, j; i <= r; i++)
    {
        Item t = v[i];
        for (j = i; j > 0 && less(t, v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = t;
    }
}

void quicksort(Item *v, int l, int r)
{
    quicksortM3(v, l, r);
    insertionsort(v, l, r);
}

int main()
{
    char s[1010];
    while (scanf(" %s", s) == 1)
    {
        int fr[130];
        Item v[130];

        for (int i = 0; i < 130; i++)
            fr[i] = 0;

        for (int i = 0; s[i] != '\0'; i++)
            fr[s[i]]++;
        int k = 0;
        for (int i = 0; i < 130; i++)
            if (fr[i])
                v[k++] = (Item){.k = i, .v = fr[i]};
        quicksort(v, 0, k - 1);
        for (int i = 0; i < k; i++)
            printf("%d %d\n", v[i].k, v[i].v);
        printf("\n");
    }

    return 0;
}