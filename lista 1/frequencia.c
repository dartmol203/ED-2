#include <stdio.h>
#include <stdlib.h>

int main()
{

    int qntAlunos, num, max = 0;

    scanf("%d", &qntAlunos);

    int *vet = calloc(1000000, sizeof(int));

    for (int i = 0; i < qntAlunos; i++)
    {

        scanf("%d", &num);

        if (max < num)
        {
            max = num;
        }
        vet[num] = 1;
    }

    num = 0;

    for (int i = 0; i <= max; i++)
    {

        if (vet[i] == 1)
        {
            num++;
        }
    }

    printf("%d\n", num);

    return 0;
}