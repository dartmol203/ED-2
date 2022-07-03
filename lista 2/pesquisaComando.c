#include <stdio.h>
#include <stdlib.h>

typedef struct instrucao
{
    int num;
    char nome[16];
} instrucao;

#define LESS(A, B) (A.num < B.num)
#define EXCH(A, B)       \
    {                    \
        instrucao t = B; \
        B = A;           \
        A = t;           \
    }
#define CMPEXCH(A, B)   \
    {                   \
        if (LESS(B, A)) \
            EXCH(A, B); \
    }

void insertionsort(instrucao *v, int l, int r)
{
    for (int i = r; i > l; i--)
        CMPEXCH(v[i - 1], v[i]);

    for (int i = l + 2; i <= r; i++)
    {
        int j = i;
        instrucao tmp = v[j];
        while (LESS(tmp, v[j - 1]))
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = tmp;
    }
}

int binarySearch(instrucao arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid].num == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid].num > x)
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

    int qnt, numBuscado, achei;

    scanf(" %d", &qnt);

    instrucao *salva = malloc(sizeof(instrucao) * (qnt + 1));

    for (int i = 0; i < qnt; i++)
        scanf(" %d %s", &salva[i].num, salva[i].nome);

    insertionsort(salva, 0, qnt);

    while (scanf("%d", &numBuscado) != EOF)
    {
        achei = binarySearch(salva, 0, qnt, numBuscado);
        if (achei == -1)
        {
            printf("undefined");
        }
        else
        {
            int i = 0;
            while (salva[achei].nome[i] != '\0')
            {
                printf("%c", salva[achei].nome[i]);
                i++;
            }
        }
        printf("\n");
    }

    return 0;
}