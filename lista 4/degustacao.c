#include <stdio.h>
#include <stdlib.h>

typedef struct seq
{

    int qnt;
    char caracter;
    int pos;

} seq;

void mergePos(seq V[], int l, int meio, int r)
{
    seq *R = malloc(sizeof(seq) * (r - l + 1));
    int i = l, j = meio + 1, k = 0;

    while (i <= meio && j <= r)
    {
        if (V[i].pos >= V[j].pos)
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

void mergeSortPos(seq V[], int l, int r)
{
    if (l >= r)
        return;
    int meio = (l + r) / 2;
    mergeSortPos(V, l, meio);
    mergeSortPos(V, meio + 1, r);
    mergePos(V, l, meio, r);
}

void mergeSize(seq V[], int l, int meio, int r)
{
    seq *R = malloc(sizeof(seq) * (r - l + 1));
    int i = l, j = meio + 1, k = 0;

    while (i <= meio && j <= r)
    {
        if (V[i].qnt <= V[j].qnt)
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

void mergeSortSize(seq V[], int l, int r)
{
    if (l >= r)
        return;
    int meio = (l + r) / 2;
    mergeSortSize(V, l, meio);
    mergeSortSize(V, meio + 1, r);
    mergeSize(V, l, meio, r);
}

int main()
{
    int i = 0;

    char *entrada = malloc(sizeof(char) * 100001);

    seq *saida = malloc(sizeof(seq) * 100001);

    scanf("%s", entrada);

    char atual = entrada[i];
    int contador = 1, seqIni = 0, qntEnt = 0;
    i++;
    while (entrada[i] != '\0')
    {
        if (entrada[i] == atual)
        {
            contador++;
        }
        else
        {
            saida[qntEnt].caracter = atual;
            saida[qntEnt].pos = seqIni;
            saida[qntEnt].qnt = contador;
            qntEnt++;
            contador = 1;
            atual = entrada[i];
            seqIni = i;
        }
        i++;
    }
    saida[qntEnt].caracter = atual;
    saida[qntEnt].pos = seqIni;
    saida[qntEnt].qnt = contador;
    qntEnt++;

    mergeSortPos(saida, 0, qntEnt - 1);
    mergeSortSize(saida, 0, qntEnt - 1);

    for (int i = qntEnt - 1; i >= 0; i--)
        printf("%d %c %d\n", saida[i].qnt, saida[i].caracter, saida[i].pos);

    return 0;
}