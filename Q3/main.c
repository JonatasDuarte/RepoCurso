#include <stdlib.h>
#include <stdio.h>
#include "lista.c"

/*
    Adicionamos o atributo Tamanho, nosso 'N', dentro
da nossa List. Sendo assim, para retornamos o tamanho, basta
mostrar nosso N, nosso 'Size' fica com complexidade O(1).
Devemos modificar as funções de remove,insertion, add e createList, para que elas
decrementem e incrementem nosso 'N', para manter o tamanho corrto da nossa List.

*/

int main(){
    list *l = createList();
        add(l, 1);
        add(l, 3);
        add(l, 5);
        add(l, 1);

        printList(l);
        printf("Size: %d\n\n", size(l));
        printf("%d\n", removeElement(l,3));
        printList(l);
        printf("%d\n", removePosition(l, 2));
        printList(l);
        printf("%d\n", insertPosition(l, 2, 1));
        printf("\nSize: %d\n", size(l));
        printList(l);

    return 0;
}