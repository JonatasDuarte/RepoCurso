#include<stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
    struct node *bef;
};
typedef struct node node;

typedef struct{
    node *begin;
    node *end;
}list;

list *criaList();

void insereInicio(list *l, int v);

node *busca(list *l, int v);

void insereFim(list *l, int v);

void removeValor(list *l, int v);

void becomeCircular(list *l);

void printCircular(list *l);

void insertCircular(list *l, int v);

int hasElement(list *l, int v);

void removeElementCircular(list *l, int v);