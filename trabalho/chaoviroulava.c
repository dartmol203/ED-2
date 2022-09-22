#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

typedef struct coord
{
    int x;
    int y;
} coord;

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

    grafo->qntA++;
}

/*
void GRAPHbfs(Grafo_t G, int s)
{
    int cnt = 0;
    for (int v = 0; v < G->qntV; ++v)
        pre[v] = -1;

    Fila *fila;

    fila = cria_fila();

    pre[s] = cnt++;
    enfileira(fila, s);

    while (!queueEmpty(fila))
    {
        int saida = desenfileira(fila);
        for (link a = G->vet[saida]; a != NULL; a = a->prox)
        {
            int t = a->dest;
            if (pre[t] == -1)
            {
                enfileira(fila, t);
                pre[t] = cnt++;
            }
        }
        printf("%d \n", pre[1]);
    }
}
*/
void graphDist(Grafo_t g, int origem)
{
    int max = g->qntV;

    for (int i = 0; i < g->qntV; i++)
    {
        pre[i] = max;
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
                pre[a->dest] = pre[saida] + 1;
                enfileira(fila, w);
            }
        }
    }
}

double dist(coord P1, coord P2)
{
    double X, Y;

    X = P2.x - P1.x;
    Y = P2.y - P1.y;
    X = pow(X, 2);
    Y = pow(Y, 2);

    return sqrt(X + Y);
}

int main()
{
    int d, n;

    scanf(" %d", &d);
    scanf(" %d", &n);

    coord *pontos = malloc(sizeof(coord) * n);

    Grafo_t grafo;

    grafo = grafoinit(n);

    for (int i = 0; i < n; i++)
        scanf("%d %d ", &pontos[i].x, &pontos[i].y);

    if (d >= dist(pontos[0], pontos[1]))
    {
        printf("1\n");
    }
    else
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (d >= dist(pontos[i], pontos[j]))
                {

                    novaAresta(grafo, i, j);
                }
            }
        }
        printf("\topa bom? %d\t", pre[1]);
        graphDist(grafo, 0);
        printf("uiui\n");

        for (int i = 0; i < grafo->qntV; i++)
        {
            printf("%d \n", pre[i]);
        }

        if (pre[1] == grafo->qntV + 30)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", pre[1]);
        }
    }

    return 0;
}
