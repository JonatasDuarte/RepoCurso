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

node *busca(list *l, int v){
    node *p = l->begin;
    while(p != NULL){
        if(p->data == v) return p;
        p= p->next;
    }
}

void removeValor(list *l, int v){
    node *p = busca(l, v);
    if(p != NULL){
        if(l->begin == l->end){
            l->begin = l->end = NULL;
        }
        else if(p == l->begin){
            l->begin = p->next;
            l->begin->bef = NULL;
        }
    }
}

void becomeCircular(list *l){
    if(l->begin != l->end){
        l->begin->bef = l->end;
        l->end->next = l->begin;
    }
}

void printCircular(list *l){
    if(l->begin != NULL){
        node *p = l->begin;
        printf("[ ");
        do{
            printf("%d ", p->data);
            p= p->next;
        }while(p != l->begin);
        printf("]\n");
    }
}

void insertCircular(list *l, int v){

}