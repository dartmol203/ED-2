#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int dado;
    struct cell *prox;
} cell;

cell *cria_pilha()
{
    cell *novo = malloc(sizeof(cell));
    novo->prox = NULL;
    return novo;
}

int empilha(cell *topo, int numero)
{

    cell *novo = malloc(sizeof(cell));
    if (novo == NULL)
    {
        return 0;
    }

    novo->dado = numero;
    novo->prox = topo->prox;
    topo->prox = novo;
    return 1;
}

int desempilha(cell *topo, int *num)
{
    if (topo->prox == NULL)
    {
        return 0;
    }

    cell *descarte = topo->prox;
    *num = descarte->dado;
    topo->prox = descarte->prox;
    free(descarte);

    return 1;
}

int main()
{

    int soma = 0, num = 1, qntnum = 0, nums[100000], limSoma;

    cell *pilha = cria_pilha();

    while (num != 0)
    {
        scanf("%d", &num);
        if (num != 0)
        {
            nums[qntnum] = num;
            qntnum++;
        }
    }

    scanf("%d", &limSoma);

    for (int i = 0; i < qntnum; i++)
    {
        soma += nums[i];
        if (soma > limSoma)
        {
            empilha(pilha, nums[i]);
            soma = 0;
        }
    }

    while (desempilha(pilha, &soma))
    {
        printf("%d\n", soma);
    }

    return 0;
}