#include <stdio.h>
#include <stdlib.h>

void merge(int V[], int l, int meio, int r)
{
    int *R = malloc(sizeof(int) * (r - l + 1));
    int i = l, j = meio + 1, k = 0;

    while (i <= meio && j <= r)
    {
        if (V[i] <= V[j])
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

void mergeSort(int V[], int l, int r)
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

    int qnt = 0, vet[100000];
    while (scanf("%d", &vet[qnt]) != EOF)
    {
        qnt++;
    }

    mergeSort(vet, 0, qnt - 1);

    for (int i = 0; i < qnt; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}