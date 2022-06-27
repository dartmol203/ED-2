#include <stdio.h>

int main(){

    long int a, b, c=0;

    scanf("%ld", &a);

    for(int i = 0; i<a; i++){
        scanf("%ld", &b);
        c+=b;
    }

    printf("%ld\n", c);

    return 0;
}