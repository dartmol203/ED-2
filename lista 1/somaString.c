#include <stdio.h>

int main()
{

    int qntString, soma;
    char string[101];

    scanf("%d", &qntString);

    for (int i = 0; i < qntString; i++)
    {
        soma = 0;

        scanf("%s", string);

        int j = 0;

        do
        {
            switch (string[j])
            {
            case '1':
                soma += 1;
                break;
            case '2':
                soma += 2;
                break;
            case '3':
                soma += 3;
                break;
            case '4':
                soma += 4;
                break;
            case '5':
                soma += 5;
                break;
            case '6':
                soma += 6;
                break;
            case '7':
                soma += 7;
                break;
            case '8':
                soma += 8;
                break;
            case '9':
                soma += 9;
                break;
            default:
                break;
            }
            /*
            if (string[j] >= 48 && string[j] <= 57)
            {
                printf("%c\n", string[j]);
                soma += string[j];
            }
            */
            j++;
        } while (string[j] != '\0');

        printf("%d\n", soma);
    }

    return 0;
}