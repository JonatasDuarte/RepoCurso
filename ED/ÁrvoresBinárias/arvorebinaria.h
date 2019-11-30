#include <stdlib.h>
#include <stdio.h>

typedef struct no no;

struct no{
    int v;
    no *esq;
    no *dir;
};

no* insertValue(no *raiz, int v);
no* findValue(no *raiz, int v);
void printTree(no *raiz);
int getHeigh(no *raiz);
no* removeValue(no *raiz, int v);
int size(no *raiz);
int sumX(no *raiz, int x);
no *criaArvore(int v);