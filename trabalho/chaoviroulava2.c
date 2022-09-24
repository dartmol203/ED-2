#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int passo;
#define origem 0
#define destino 1

// Estrutura de coordenadas
typedef struct Item
{
    int x;
    int y;
} Item;

Item hash[3100];

// Estrutura do link
typedef struct no *link;

struct no
{
    int v;
    link prox;
} no;

// Estrutura do Grafo
typedef struct graph
{
    int V, E;
    link *adj;
} graph;

// Estrutura da Edge
typedef struct Edge
{
    int u;
    int w;
} Edge;

// Retorna Edge
Edge EDGE(int u, int w)
{
    return (Edge){u, w};
}

link new (int v, link prox)
{
    link x = malloc(sizeof(link));

    x->v = v;
    x->prox = prox;

    return x;
}

int distanciaEuclidiana(int x1, int x2, int y1, int y2)
{
    // double quadradoX = (x1-x2);
    // double quadradoY = (y1-y2);
    double distancia = hypot((x1 - x2), (y1 - y2));
    return distancia <= (double)passo;
}

void graphInsertE(graph *G, int u, int v)
{

    G->adj[u] = new (v, G->adj[u]);
    G->adj[v] = new (u, G->adj[v]);
    G->E++;

    return;
}

graph *graphInit(int v)
{
    graph *G = malloc(sizeof(graph));
    G->V = v;
    G->E = 0;
    G->adj = malloc(v * sizeof(link));

    for (int i = 0; i < v; i++)
    {
        G->adj[i] = NULL;
    }

    return G;
}

// IMPLEMENTAÇÃO DE FILA

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

// Pergunta se está vazia
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

void graphSearch(graph *G, int s, int *dist)
{
    int infinito = G->V;

    for (int i = 0; i < G->V; i++)
    {
        dist[i] = infinito;
    }

    dist[s] = 0;

    struct Fila *f = criaFila(G->V);
    enfileira(f, s);

    while (!filaVazia(f))
    {
        int v = desenfileira(f);
        for (link a = G->adj[v]; a != NULL; a = a->prox)
        {
            int w = a->v;
            if (dist[w] == infinito)
            {
                dist[w] = dist[v] + 1;
                enfileira(f, w);
            }
        }
    }
}

int main(void)
{
    int n;
    scanf("%d", &passo);
    scanf("%d", &n);

    graph *grafo = graphInit(n);

    int x, y;

    for (int i = 0; i < grafo->V; i++)
    {
        scanf("%d %d", &x, &y);

        hash[i].x = x;
        hash[i].y = y;
    }

    for (int i = 0; i < grafo->V; i++)
    {
        for (int j = i + 1; j < grafo->V; j++)
        {
            if (distanciaEuclidiana(hash[i].x, hash[j].x, hash[i].y, hash[j].y))
            {
                graphInsertE(grafo, i, j);
            }
        }
    }

    /*
    for(int i = 0; i < n; i++){
        printf("%d\n\n", i);
        for(link t = grafo->adj[i]; t != NULL; t = t->prox){
            printf("-> %d\n", t->v);
        }
        printf("\n");
    }
    */

    int *dist = malloc(n * sizeof(int));

    graphSearch(grafo, origem, dist);

    if (dist[destino] != grafo->V)
    {
        printf("%d\n", dist[destino]);
        return 0;
    }

    printf("-1\n");

    return 0;
}