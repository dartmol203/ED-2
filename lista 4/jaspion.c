#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dic
{
    char jap[81];
    char ptbr[81];
} dic;

#define LESS(A, B) (strcmp(A.jap, B.jap))
#define EXCH(A, B) \
    {              \
        dic t = B; \
        B = A;     \
        A = t;     \
    }
#define CMPEXCH(A, B)   \
    {                   \
        if (LESS(B, A)) \
            EXCH(A, B); \
    }

int separa(dic *v, int l, int r)
{
    dic c = v[r], t; // pivô
    int j = l;
    for (int k = l; /*A*/ k < r; ++k)
        if (strcmp(v[k].jap, c.jap))
        {
            t = v[j], v[j] = v[k], v[k] = t;
            ++j;
        }
    t = v[j], v[j] = v[r], v[r] = t;
    return j;
}
void quickSort(dic *v, int l, int r)
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

int binarySearch(dic arr[], int l, int r, char *x)
{
    if (r >= l)
    {
        int mid = l + r / 2;

        // If the element is present at the middle
        // itself
        if (strcmp(x, arr[mid].jap) == 0)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (strcmp(x, arr[mid].jap) < 0)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int main()
{

    int qntIns, qntDic, qntVer;
    scanf(" %d", &qntIns);
    char entrada[81], p;

    for (int i = 0; i < qntIns; i++)
    {
        scanf(" %d %d", &qntDic, &qntVer);
        dic *palavras = malloc(sizeof(dic) * qntDic);
        for (int j = 0; j < qntDic; j++)
        {
            scanf(" %[^\n]", palavras[j].jap);
            scanf(" %[^\n]", palavras[j].ptbr);
        }
        quickSort(palavras, 0, qntDic - 1);

        /*
        for (int j = 0; j < qntDic; j++)
            printf("%s %s\n", palavras[j].jap, palavras[j].ptbr);
        */
        for (int j = 0; j < qntVer; j++)
        {
            int busca;
            while (scanf(" %s%c", entrada, &p) == 2)
            {
                busca = binarySearch(palavras, 0, qntDic, entrada);
                if (busca != -1)
                    printf("%s", palavras[busca].ptbr);
                else
                    printf("%s", entrada);
                printf("%c", p);
                if (p == '\n')
                    break;
            }
        }
    }

    return 0;
}