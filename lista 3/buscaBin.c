#include <stdio.h>
#include <stdlib.h>

void merge(int V[], long long int l, long long int meio, long long int r)
{
    int *R = malloc(sizeof(int) * (r - l + 1));
    long long int i = l, j = meio + 1, k = 0;

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

void mergeSort(int V[], long long int l, long long int r)
{
    if (l >= r)
        return;
    long long int meio = (l + r) / 2;
    mergeSort(V, l, meio);
    mergeSort(V, meio + 1, r);
    merge(V, l, meio, r);
}

long long int binarySearch(int arr[], long long int l, long long int r, int x)
{
    if (r >= l)
    {
        long long int mid = l + (r - l) / 2;

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
    long long int m, n;

    scanf("%lld %lld", &n, &m);

    int *arr = malloc(sizeof(int) * n);

    for (long long int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    for (long long int i = 0; i < n; i++)
        printf("%d\n", arr[i]);

    for (long long int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%lld\n", binarySearch(arr, 0, n, x));
    }

    return 0;
}