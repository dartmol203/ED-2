#include <stdio.h>

int main(){

    int i=0, qntsim=0, qntTriagem=0;
    char entrada[4];

    while (scanf("%s", entrada)==1)
    {
        i++;
        if(entrada[0]=='s'){
            qntsim++;
        }
        if(i>9){
            if(qntsim>1){
                qntTriagem++;
            }
            i =0;
            qntsim = 0;
        }
    }
    
    printf("%d\n", qntTriagem);

    return 0;
}