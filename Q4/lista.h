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

node *removeValor(list *l, int v);
