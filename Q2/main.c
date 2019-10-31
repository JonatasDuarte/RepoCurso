#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

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

int insertPosition(list *l, int v, int pos){
    int max = size(l), i;
    if(pos >=0 && pos<max){
        node *n =(node*)malloc(sizeof(node));
        n->data = v;
        node *p = l->begin;
        node *a = NULL;
        for(i = 0; i<pos;){
            a = p;
            p = p->next;
        }
        if(a == NULL){
            n->next = l->begin;
            l->begin = n;
        }else if(p == NULL){
            n->next = NULL;
            a->next = n;
        } else{
            n->next = p;
            a->next = n;
        }
        return 0;
    }
    return -1;
}