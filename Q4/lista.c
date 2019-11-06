#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

list *createList(){
    list *l = (list*)malloc(sizeof(list));
    l->begin = NULL;
    l->end = NULL;
    return l;
}

void insereInicio(list *l, int v){
    node *n = (node*)malloc(sizeof(node));
    n->data = v;
    n->next = l->begin;
    n->bef = l->end;
    if(l->begin == NULL){
        l->begin = n;
        l->end = n;
    }  else{
        l->begin->bef = n;
        l->begin = n;
    }
}

void insereFim(list *l, int v){
    node *n = (node*)malloc(sizeof(node));
    n->data = v;
    n->next = NULL;
    n->bef = l->end;
    if(l->begin == NULL){
        l->begin = l->end = n;
    } else{
        l->end->next = n;
        l->end = n;
    }
}