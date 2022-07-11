#include <stdio.h>
#include <stdlib.h>

int qntFinal = 0;

int uniq(int *arr, int n)
{
    int *tmp = malloc(sizeof(int) * n);
    int j = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            tmp[j++] = arr[i];
        }
    }

    tmp[j++] = arr[n - 1];

    for (int i = 0; i < j; i++)
    {
        arr[i] = tmp[i];
    }
    free(tmp);
    return j;
}

int *intercala2(int *v1, int l1, int r1, int *v2, int l2, int r2)
{
    int *vM = malloc(sizeof(int) * (r1 + r2));
    int ci = 0;

    while (l1 < r1 && l2 < r2)
    {

        if (v1[l1] < v2[l2])
            vM[ci++] = v1[l1++];
        else
            vM[ci++] = v2[l2++];

        qntFinal++;
    }

    while (l1 < r1)
    {
        vM[ci++] = v1[l1++];
        qntFinal++;
    }

    while (l2 < r2)
    {
        vM[ci++] = v2[l2++];
        qntFinal++;
    }

    return vM;
}

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
    int qntNum, qntAux = 0, vet[140000], vetAux[140000], *saida;
    scanf("%d", &qntNum);

    for (int i = 0; i < qntNum; i++)
        scanf("%d", &vet[i]);

    mergeSort(vet, 0, qntNum - 1);

    qntNum = uniq(vet, qntNum);

    if (qntNum % 2 != 0)
    {
        vet[qntNum] = 1000000000;
        qntNum++;
    }

    for (int i = 0; i < qntNum; i = i + 2)
    {
        vetAux[qntAux++] = vet[i] + vet[i + 1];
    }

    mergeSort(vetAux, 0, qntAux - 1);

    /* for (int i = 0; i < qntNum; i++)
        printf("%d ", vet[i]);
    printf("\n");

    for (int i = 0; i < qntAux; i++)
        printf("%d ", vetAux[i]);
    printf("\n"); */

    saida = intercala2(vet, 0, qntNum, vetAux, 0, qntAux);
    qntFinal = uniq(saida, qntFinal);

    for (int i = 0; i < qntFinal; i = i + 4)
        printf("%d\n", saida[i]);

    printf("Elementos: %d\n", qntFinal);

    return 0;
}