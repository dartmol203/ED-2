#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell
{
    char dado[101];
    struct cell *prox;
} cell;

cell *cria_pilha()
{
    cell *novo = malloc(sizeof(cell));
    novo->prox = NULL;
    return novo;
}

int empilha(cell *topo, char str[101])
{

    cell *novo = malloc(sizeof(cell));
    if (novo == NULL)
    {
        return 0;
    }

    strcpy(novo->dado, str);
    novo->prox = topo->prox;
    topo->prox = novo;
    return 1;
}

int desempilha(cell *topo, char str[101])
{
    if (topo->prox == NULL)
    {
        return 0;
    }

    cell *descarte = topo->prox;
    strcpy(str, descarte->dado);
    topo->prox = descarte->prox;
    free(descarte);

    return 1;
}

int main()
{

    int sucesso;
    char entrada[101], saida[101];

    cell *pilha = cria_pilha();

    while (scanf(" %s", entrada) != EOF)
    {
        if (entrada[0] == 'd')
        {
            sucesso = desempilha(pilha, saida);
            if (sucesso)
            {
                printf("%s\n", saida);
            }
            else
            {
                printf("NULL\n");
            }
        }
        else if (entrada[0] == 'i')
        {

            scanf(" %[^\n]s", entrada);
            empilha(pilha, entrada);
        }
    }

    return 0;
}