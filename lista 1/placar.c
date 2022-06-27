#include <stdio.h>
#include <string.h>

#define ponto(A) (A.qntProbs)
#define LESS(A, B) (ponto(A) < ponto(B))
#define LESSSTR(A, B) (strcmp(A.nome, B.nome))
#define EXCH(A, B)          \
    {                       \
        participante t = B; \
        B = A;              \
        A = t;              \
    }
#define CMPEXCH(A, B)   \
    {                   \
        if (LESS(B, A)) \
            EXCH(A, B); \
    }

#define CMPEXCHSTR(A, B)   \
    {                      \
        if (LESSSTR(B, A)) \
            EXCH(A, B);    \
    }
typedef struct participante
{
    char nome[21];
    int qntProbs;
} participante;

void insertionSortInt(participante *vet, int r)
{

    for (int i = 0; i < r; i++)
    {
        participante aux = vet[i];
        int j = i - 1;
        while (j >= 0 && LESS(aux, vet[j]))
        {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
    }
}

void insertionSortStr(participante *vet, int r)
{

    for (int i = 0; i < r; i++)
    {
        participante aux = vet[i];
        int j = i - 1;
        while (j >= 0 && strcmp(aux.nome, vet[j].nome) > 0)
        {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
    }
}

int main()
{

    int qntAlunos, instancia = 1;

    participante parts[100];

    while (scanf("%d", &qntAlunos) != EOF)
    {
        printf("Instancia %d\n", instancia);

        for (int i = 0; i < qntAlunos; i++)
        {
            scanf("%s %d", parts[i].nome, &parts[i].qntProbs);
        }

        insertionSortStr(parts, qntAlunos);

        insertionSortInt(parts, qntAlunos);

        printf("%s \n", parts[0].nome, qntAlunos);

        printf("\n");

        instancia++;
    }

    return 0;
}