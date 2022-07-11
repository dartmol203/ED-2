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

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

int main()
{

    int qntNum;

    scanf("%d", &qntNum);
    int *vet = malloc(sizeof(int) * qntNum);
    for (int i = 0; i < qntNum; i++)
        scanf("%d", &vet[i]);

    mergeSort(vet, 0, qntNum - 1);

    int x;

    while (scanf("%d", &x) != EOF)
    {
        x = binarySearch(vet, 0, qntNum, x);
        if (x == -1)
            printf("nao\n");
        else
            printf("sim\n");
    }

    return 0;
}