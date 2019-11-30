#include <stdlib.h>
#include <stdio.h>
#include "lista.c"

int main(){
    list *l = createList();
    add(l, 1);
    add(l, 3);
    add(l, 5);
    add(l, 4);
    add(l, 2);

    printf("Tem o elemento '1'?(Sim: posição / Não: -1)\n %d\n", hasElement(l, 1));
    printf("Tem e elemento '2'?(Sim: posição / Não: -1)\n %d\n", hasElement(l, 2));

    printf("Inseriu o elemento '2'?(Sim: 0 / Não: -1)\n %d\n", insertPosition(l, 2, 1));
    printf("Inseriu o elemento '8'?(Sim: 0 / Não: -1)\n %d\n", insertPosition(l, 8, 8));

    printList(l);
    printf("\nRemoveu na posição '0'?(Sim: 0 / Não: -1)\n %d\n", removePosition(l, 0));
    printf("Removeu na posição '3'?(Sim: 0 / Não: -1)\n %d\n", removePosition(l, 3));

    printList(l);
    printf("\nRemoveu o elemento '2'?(Sim: 0 / Não: -1)\n %d\n", removeElement(l, 2));
    printf("Removeu o elemento '0'?(Sim: 0 / Não: -1)\n %d\n", removeElement(l, 0));

    int getNumber;
    printf("Get na posição '1'?(Sim: 0 / Não: -1)\n %d\n", get(l, 1, &getNumber));
    printf("Get na posição '-2'?(Sim: 0 / Não: -1)\n %d\n", get(l, -2, &getNumber));

    return 0;
}