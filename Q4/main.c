#include <stdlib.h>
#include <stdio.h>
#include "lista.c"

int main(){
    list *l = createList();
    insereInicio(l, 1);
    insereFim(l, 2);
    insereFim(l, 3);
    insereInicio(l, 1);
    node *p = busca(l, 1);
    printf("%d\n", p->data);

    return 0;
}