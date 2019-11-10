#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

list *createList(){
    list *l = (list*)malloc(sizeof(list));
    l->begin = NULL;
    l->end = l->begin;
    return l;
}

void insereInicio(list *l, int v){
    node *n = (node*)malloc(sizeof(node));
    n->data = v;
    n->next = l->begin;
    n->bef = NULL;
    l->begin = n;
    if(l->end == NULL) l->end = n;
}

void insereFim(list *l, int v){
    node *n = (node*)malloc(sizeof(node));
    n->data = v;
    n->next = NULL;
    n->bef = l->end;
    l->end->next = n;
    l->end = n;

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
    if(l->begin != NULL){
        l->begin->bef = l->end;
        l->end->next = l->begin;
    }
}

void printCircular(list *l)
{
    printf("[ ");
    node *p = l->begin;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("]\n");
}

void insertCircular(list *l, int v){
    node *n = (node*)malloc(sizeof(node));
    n->data = v;
     if(l->begin == NULL){
        l->begin = l->end = n;
        n->bef = n->next = n;
    } else{
        n->next = l->begin;
        n->bef = l->end;
        n->bef->next = n;
        l->end = n;
    }
}

int hasElement(list *l, int v){
    node *n = l->begin;
    int pos = 0;
    while(n != NULL){
        if(n->data == v) return pos;
        n = n->next;
        pos++;
    }
    return -1;
}

void removeElementCircular(list *l, int v){
    int pos = hasElement(l, v), i;
    if(pos >= 0)
    {
        node *p = l->begin;
        for(i = 0; i < pos; i++)
            p = p->next;

        if(l->begin == p){
            l->begin = p->next;
            l->begin->bef = NULL;
        }
        else if(l->end == p){
            l->end = p->bef;
            l->end->next = NULL;
        }
        else{
            p->next->bef = p->bef;
            p->bef->next = p->next;
        }
        free(p);
    }
}