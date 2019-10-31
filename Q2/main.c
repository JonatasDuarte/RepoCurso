#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

int main(){
    list *l = createList();
    add(l, 1);
    add(l, 3);
    add(l, 5);

    printf("Tem o elemento '1'?(Sim: 0 / Não: -1)\n %d\n", hasElement(l, 1));
    printf("Tem e elemento '2'?(Sim: 0 / Não: -1)\n %d\n", hasElement(l, 2));

    printf("Inseriu o elemento '2'?(Sim: 0 / Não: -1)\n %d\n", insertionPosition(l, 2, 1));
    printf("Inseriu o elemento '8'?(Sim: 0 / Não: -1)\n %d\n", insertionPosition(l, 8, 8));

    printf("Removeu na posição '0'?(Sim: 0 / Não: -1)\n %d\n", removePosition(l, 0));
    printf("Removeu na posição '9'?(Sim: 0 / Não: -1)\n %d\n", removePosition(l, 9));

    printf("Removeu o elemento '2'?(Sim: 0 / Não: -1)\n %d\n", removeElement(l, 2));
    printf("Removeu o elemento '0'?(Sim: 0 / Não: -1)\n %d\n", removeElement(l, 0));

    int getNumber;
    printf("Get na posição '0'?(Sim: 0 / Não: -1)\n %d\n", get(l, 1, &getNumber));
    printf("Get na posição '-2'?(Sim: 0 / Não: -1)\n %d\n", get(l, -2, &getNumber));

    return 0;
}