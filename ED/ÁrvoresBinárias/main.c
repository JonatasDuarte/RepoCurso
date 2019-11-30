
#include <stdlib.h>
#include <stdio.h>
#include "arvorebinaria.c"

int main(){
    no *arv = criaArvore(2);
    insertValue(arv, 1);
    insertValue(arv, 3);
    insertValue(arv, 5);
    insertValue(arv, 4);
    printTree(arv);
    printf("\n");
    printf("Size: %d\n",size(arv));
    printf("SUM: %d\n",sumX(arv, 2));
    printf("Altura: %d\n\nRemoção.\n",getHeigh(arv));
    removeValue(arv, 3);
    printTree(arv);
    printf("\nNovo size: %d\n",size(arv));
    printf("Nova altura: %d\n",getHeigh(arv));
    printf("SUM: %d",sumX(arv, 2));
    printf("\n");

    return 0;
}