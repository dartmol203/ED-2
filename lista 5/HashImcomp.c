#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// HT = HashTable = Tabela Hash
//  para um vetor o intervalo fechado é [0,262143]
#define HTSIZE 140000
#define HTNULL -1

typedef struct pessoa
{
    int id;
    char fst_name[100];
    char lst_name[100];
    char tel[100];
    char birth[20];
} pessoa;

typedef struct no
{
    pessoa pes;
    struct no *prox;
} no;

typedef struct lista_st
{
    no *head;
    int count;
} lista_st;

void LEinit(lista_st *lista)
{
    lista->head = NULL;
    lista->count = 0;
}

void LEinsert(lista_st *lista, pessoa pes)
{
    no *l = malloc(sizeof(no));
    l->pes = pes;
    l->prox = lista->head;
    lista->head = l;
    lista->count++;
}

int LEsearchId(lista_st *lista, int x)
{
    no *aux = lista->head;
    while (aux != NULL)
    {
        if (aux->pes.id == x)
            return 1;
        aux = aux->prox;
    }
    return 0;
}

int LEsearchInfo(lista_st *lista, int x)
{
    no *aux = lista->head;
    while (aux != NULL)
    {
        if (aux->pes.id == x)
        {

            printf("%s %s %s %s\n", aux->pes.fst_name, aux->pes.lst_name, aux->pes.birth, aux->pes.tel);
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

int LEdelId(lista_st *lista, int x)
{
    no *aux = lista->head, *anterior = aux;
    while (aux != NULL)
    {
        if (aux->pes.id == x)
        {
            if (aux->pes.id == lista->head->pes.id)
            {
                lista->head = aux->prox;
                lista->count--;
                free(aux);
            }
            else
            {
                anterior->prox = aux->prox;
                lista->count--;
                free(aux);
            }

            return 1;
        }
        anterior = aux;
        aux = aux->prox;
    }
    return 0;
}

typedef struct HT_st
{
    lista_st *ht;
    int count;
} HT_st;

int hash(int Pi)
{
    return Pi % HTSIZE;
}

void HTinit(HT_st *HT)
{
    HT->ht = malloc(sizeof(lista_st) * HTSIZE);
    HT->count = 0;

    // elemento vazio da tabela hash será o -1
    for (int i = 0; i < HTSIZE; i++)
        LEinit(&HT->ht[i]);
}

void HTinsert(HT_st *HT, pessoa x)
{
    int hashv = hash(x.id);
    LEinsert(&HT->ht[hashv], x);
    HT->count++;
}

int HTsearch(HT_st *HT, pessoa x)
{
    int hashv = hash(x.id);

    return LEsearchId(&HT->ht[hashv], x.id);
}
int HTsearchInfo(HT_st *HT, pessoa x)
{
    int hashv = hash(x.id);

    return LEsearchInfo(&HT->ht[hashv], x.id);
}

int HTDel(HT_st *HT, pessoa x)
{

    int hashv = hash(x.id);

    return LEdelId(&HT->ht[hashv], x.id);
}

typedef struct Query
{
    char field[4], value[200];
} Query;

int main()
{

    char instruc[6];
    HT_st hashTable;
    int flag;

    HTinit(&hashTable);

    while (scanf(" %s", instruc) != EOF)
    {
        switch (instruc[0])
        {
        case 'i':
            pessoa info;
            scanf(" %d", &info.id);
            flag = HTsearchInfo(&hashTable, info);
            if (flag == 0)
            {
                printf("ID %d nao existente.\n", info.id);
            }
            break;
        case 'd':
            pessoa del;

            scanf(" %d", &del.id);
            flag = HTDel(&hashTable, del);
            if (flag == 0)
            {
                printf("ID %d nao existente.\n", del.id);
            }
            break;
        case 'q':
            char pesq[101];
            Query qs[4];
            scanf(" %[^\n]", pesq);
            printf("%s", pesq);

            char *q = strtok(pesq, " ");
            for (int qsize = 0; q && qsize < 4; qsize++)
            {
                sscanf(q, " %[^:]:%s", qs[qsize].field, qs[qsize].value);
                q = strtok(NULL, " ");
            }

            break;
        case 'a':
            pessoa novo;
            scanf(" %d %s %s %s %s", &novo.id, novo.fst_name, novo.lst_name, novo.birth, novo.tel);
            flag = HTsearch(&hashTable, novo);

            if (flag == 1)
            {
                printf("ID %d ja cadastrado.\n", novo.id);
            }
            else
            {
                HTinsert(&hashTable, novo);
            }
            printf("%d %s %s %s %s\n", novo.id, novo.fst_name, novo.lst_name, novo.birth, novo.tel);
            break;
        default:
            break;
        }
    }

    return 0;
}