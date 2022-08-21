/*
#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    unsigned long long int atual, anterior, prox;
    int visitado;
} item;

typedef struct ht_t
{
    int tam;
    cabeca *vet;

} ht_t;

typedef struct cabeca
{
    int qnt;
    no *prox;

} cabeca;

typedef struct no
{
    item valor;
    no *prox;

} no;

cabeca *pilha;

void inicia_ht(ht_t *ht, int tam)
{
    ht->tam = tam;
    ht->vet = malloc(sizeof(cabeca) * tam);
    for (int i = 0; i < tam; i++)
    {
        cria_pillha(&ht->vet[i]);
    }
}

int hash(item x, int tam)
{
    int h = x.atual % tam;
    return h;
}

void insere_ht(ht_t *ht, item entrada)
{
    entrada.visitado = 0;

    empilhaLista(&ht->vet[hash(entrada, ht->tam)], entrada);
}

int buscaHt(ht_t *ht, item buscado)
{

    item x = buscaLisca(&ht->vet[hash(buscado, ht->tam)], buscado);

    if (x.visitado == -1)
    {
        return -1;
    }

    empilha(pilha, x);

    return 0;
}

void cria_pillha(cabeca *cab)
{
    cab->qnt = 0;
    cab->prox = NULL;

    return 0;
}

void empilha(cabeca *cab, item valor)
{

    no *novo = malloc(sizeof(no));

    valor.visitado++;

    novo->valor = valor;
    novo->prox = cab->prox;
    cab->prox = novo;
    cab->qnt++;

    return 1;
}

void empilhaLista(cabeca *cab, item valor)
{

    no *novo = malloc(sizeof(no));

    novo->valor = valor;
    novo->prox = cab->prox;
    cab->prox = novo;
    cab->qnt++;

    return 1;
}

item buscaLisca(cabeca *cab, item buscado)
{
    item ret;
    ret.visitado = -1;
    int try = 0;
    no *proximo = cab->prox;

    while (proximo != NULL && try < cab->qnt)
    {
        if (proximo->valor.atual == buscado.atual)
        {
            return proximo->valor;
        }
        proximo = proximo->prox;
        try++;
    }

    return ret;
}

item desempilha(cabeca *cab)
{

    item retorno;

    if (cab->prox == NULL)
    {
        retorno.visitado = -1;
        return retorno;
    }
    no *saida = cab->prox;

    cab->prox = saida->prox;

    retorno = saida->valor;

    retorno.visitado++;
    cab->qnt--;
    free(saida);
    return retorno;
}

int main()
{

    ht_t *ht;

    inicia_ht(ht, 1001);

    cria_pillha(pilha);

    item teste;

    insere_ht(ht, teste);

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

#define ull unsigned long long
#define Item struct Element
#define key(x) (x.curr)
#define less(a, b) (key(a) < key(b))
#define swap(a, b)  \
    {               \
        Item t = a; \
        a = b;      \
        b = t;      \
    }
#define cmpswap(a, b) \
    if (less(b, a))   \
    swap(a, b)

struct Element
{
    ull curr, prev, next;
};

int partition(Item *v, int size)
{
    int l = -1, r = size - 1;
    Item pivot = v[r];

    while (1)
    {
        while (less(v[++l], pivot))
            ;
        while (less(pivot, v[--r]) && r > l)
            ;

        if (l >= r)
            break;
        swap(v[l], v[r]);
    }
    swap(v[l], v[size - 1]);
    return l;
}

void quicksort(Item *v, int size)
{
    if (size < 2)
        return;

    cmpswap(v[(size - 1) / 2], v[size - 1]);
    cmpswap(v[0], v[(size - 1) / 2]);
    cmpswap(v[size - 1], v[(size - 1) / 2]);

    int m = partition(v, size);
    quicksort(v, m);
    quicksort(v + m + 1, size - m - 1);
}

int search(Item *v, int n, ull x)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (key(v[m]) == x)
            return m;
        else if (key(v[m]) < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int is_sane(Item *v, int n, Item prev, Item target)
{
    if (prev.next == target.curr && target.prev == prev.curr)
        return 1;

    int idx = search(v, n, prev.next);
    if (idx == -1 || v[idx].prev != prev.curr)
        return 0;

    return is_sane(v, n, v[idx], target);
}

Item v[500000];

int main()
{
    int n;
    for (n = 0; scanf(" %llx %llx %llx", &v[n].curr, &v[n].prev, &v[n].next) == 3; n++)
        ;

    Item ptr1 = v[0], ptr2 = v[1];
    quicksort(v, n);

    printf("%s\n", (is_sane(v, n, ptr1, ptr2) ? "sana" : "insana"));

    return 0;
}