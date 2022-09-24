#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 33911
static int pre[3001];

struct Fila
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};

// Cria Fila
struct Fila *criaFila(unsigned capacity)
{
    struct Fila *Fila = (struct Fila *)malloc(sizeof(struct Fila));
    Fila->capacity = capacity;
    Fila->front = Fila->size = 0;

    Fila->rear = capacity - 1;
    Fila->array = (int *)malloc(
        Fila->capacity * sizeof(int));
    return Fila;
}

// Pergunta se esta vazia
int filaVazia(struct Fila *Fila)
{
    return (Fila->size == 0);
}

// Enfileira
void enfileira(struct Fila *Fila, int item)
{
    Fila->rear = (Fila->rear + 1) % Fila->capacity;
    Fila->array[Fila->rear] = item;
    Fila->size = Fila->size + 1;
    return;
}

// Desinfileira
int desenfileira(struct Fila *Fila)
{
    int item = Fila->array[Fila->front];
    Fila->front = (Fila->front + 1) % Fila->capacity;
    Fila->size = Fila->size - 1;
    return item;
}

typedef struct Nome
{
    int numVertice;
    char name[26];
} Nome;

Nome ht[SIZE];

void iniciaHt()
{
    for (int i = 0; i < SIZE; i++)
        ht[i].numVertice = -1;
}

int hashUniversal(char *string)
{

    unsigned int hash = 0;

    for (int i = 0; string[i] != '\0'; i++)
        hash += string[i] * (i + 1) * 20014447 / 1000;

    return hash % SIZE;
}

void insereHt(Nome novo)
{

    int pos = hashUniversal(novo.name);
    while (ht[pos].numVertice != -1)
    {
        pos = (pos + 2) % SIZE;
    }

    ht[pos] = novo;
}

int buscaHt(Nome encontra)
{

    int pos = hashUniversal(encontra.name);

    while (ht[pos].numVertice != -1)
    {
        if (strcmp(encontra.name, ht[pos].name) == 0)
        {
            return ht[pos].numVertice;
        }
        else
        {
            pos = (pos + 2) % SIZE;
        }
    }

    return -1;
}

typedef struct no *link;

struct no
{
    int dest;
    link prox;
};

typedef struct grafo_t *Grafo_t;

struct grafo_t
{
    link *vet;
    int qntV;
    int qntA;
};

Grafo_t grafoinit(int v)
{
    Grafo_t grafo = malloc(sizeof(grafo));

    grafo->qntV = v;
    grafo->qntA = 0;

    grafo->vet = malloc(v * sizeof(link));

    for (int i = 0; i < v; i++)
        grafo->vet[i] = NULL;

    return grafo;
}

static link novono(int dest, link prox)
{
    link novo = malloc(sizeof(link));
    novo->dest = dest;
    novo->prox = prox;

    return novo;
}

void novaAresta(Grafo_t grafo, int origem, int dest)
{
    /*
    for (link a = grafo->vet[origem]; a != NULL; a = a->prox)
    {

        if (a->dest == dest)
        {
            return;
        }
    }
    */

    grafo->vet[origem] = novono(dest, grafo->vet[origem]);
    grafo->vet[dest] = novono(origem, grafo->vet[dest]);

    grafo->qntA += 2;
}

void graphDist(Grafo_t g, int origem)
{

    for (int i = 0; i < g->qntV; i++)
    {
        pre[i] = -1;
    }

    pre[origem] = 0;

    struct Fila *fila = criaFila(g->qntV);
    enfileira(fila, origem);

    while (!filaVazia(fila))
    {
        int saida = desenfileira(fila);
        for (link a = g->vet[saida]; a != NULL; a = a->prox)
        {
            int w = a->dest;
            if (pre[w] == -1)
            {
                // printf("%d\n", pre[saida]);
                pre[a->dest] = pre[saida] + 1;
                enfileira(fila, w);
            }
        }
    }
}

int main()
{
    Nome origem, destino;
    iniciaHt();

    scanf(" %s %s", origem.name, destino.name);

    int qntP, qntA;

    scanf("%d %d ", &qntP, &qntA);

    Nome entrada1, entrada2, aux;

    Grafo_t grafo = grafoinit(qntP);

    for (int i = 0; i < qntP; i++)
    {
        scanf(" %s", aux.name);
        aux.numVertice = i;
        insereHt(aux);
    }

    for (int i = 0; i < qntA; i++)
    {
        scanf(" %s %s", entrada1.name, entrada2.name);
        int v1 = buscaHt(entrada1);
        int v2 = buscaHt(entrada2);
        if (v1 * v2 == 1)
            break;

        novaAresta(grafo, v1, v2);
    }

    graphDist(grafo, buscaHt(origem));

    printf("%d\n", pre[buscaHt(destino)]);

    return 0;
}