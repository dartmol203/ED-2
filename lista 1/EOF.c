#include <stdio.h>

int main(){

    long int a, i = 0;

    while (scanf("%ld",&a) == 1)
    {
        i++;
    }
    
    printf("%ld\n", i);

    return 0;
}