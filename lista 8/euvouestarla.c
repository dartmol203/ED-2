#include <stdio.h>
#include <stdlib.h>

int g[2010][2010];

int pos[2010];

int main()
{

    int n, m, j;
    scanf(" %d %d %d", &n, &m, &j);
    for (int i = 0, x, y; i < n; i++)
    {
        g[i][i] = 1;
        scanf(" %d", &x);
        while (x--)
        {
            scanf(" %d", &y);
            g[i][y] = 1;
        }
    }

    for (int i = 0, x; i < m; i++)
    {
        scanf(" %d", &x);
        for (int y = 0; y < n; y++)
            if (g[x][y] == 1)
                pos[y] = 2;
    }

    while (j--)
    {
        int x;
        scanf(" %d", &x);
        printf("%s vou estar la\n", (pos[x] == 2 ? "Eu" : "Nao"));
    }

    return 0;
}