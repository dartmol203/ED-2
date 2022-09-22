#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct lista
{
    int dado;
    struct lista *prox;
};

typedef struct lista Lista;

struct fila
{
    Lista *inicio;
    Lista *fim;
};

typedef struct fila Fila;

Fila *cria_fila()
{
    Fila *f = malloc(sizeof(Fila));

    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void enfileira(Fila *f, int x)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->dado = x;
    novo->prox = NULL;

    if (f->fim == NULL)
    {
        f->inicio = novo;
    }
    else
    {
        f->fim->prox = novo;
    }

    f->fim = novo;
}

int desenfileira(Fila *f)
{
    Lista *aux;
    int v;

    if (f->inicio == NULL)
    {
        return -1;
    }

    aux = f->inicio;
    v = aux->dado;
    f->inicio = aux->prox;

    if (f->inicio == NULL)
        f->fim = NULL;

    free(aux);

    return v;
}

int queueEmpty(Fila *f)
{

    if (f->inicio == NULL)
    {
        return 1;
    }

    return 0;
}

int main()
{

    Fila *fila = cria_fila();

    enfileira(fila, 7);
    enfileira(fila, 47);
    enfileira(fila, 3);
    enfileira(fila, 2);
    enfileira(fila, 9);
    enfileira(fila, 5);

    while (!queueEmpty(fila))
    {

        printf("%d ", desenfileira(fila));
    }

    printf("%d ", desenfileira(fila));

    return 0;
}