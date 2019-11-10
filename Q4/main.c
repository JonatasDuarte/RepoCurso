#include <stdlib.h>
#include <stdio.h>
#include "lista.c"

int main(){
    list *l = createList();
    becomeCircular(l);
    insereInicio(l, 1);
    insereFim(l, 2);
    insereInicio(l, 1);
    insereFim(l, 3);
    node *p = busca(l, 1);
    printf("Valor buscado: %d\n", p->data);
    printCircular(l);
    printf("Removendo valores\n");
    removeElementCircular(l, 1);
    removeElementCircular(l, 2);
    printCircular(l);

    return 0;
}