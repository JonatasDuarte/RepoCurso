#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

list *createList(){
  list *l = (list*)malloc(sizeof(list));
  l->begin = NULL;
  //Nosso tamanho se inicia em Zero
  l->n = 0;
  return l;
}

void add(list *l, int v){
  node *n = (node*)malloc(sizeof(node));
  n->data = v;
  n->next = NULL;
  node *p = l->begin;
  node *a = NULL;
  while(p != NULL){
    a = p;
    p = p->next;
  }
  if(a == NULL)
    l->begin = n;
  else{
    a->next = n;
  }
  //Incrementando nosso N
  l->n++;
}

void printList(list *l){
  node *p = l->begin;
  printf("[ ");
  while(p != NULL){
    printf("%d ", p->data);
    p = p->next;
  }
  printf("]\n");
}

int isEmpty(list *l){
  if(l->begin == NULL) return 1;
  else return 0;
}

void removeBack(list *l){
  node *n = l->begin, *a = NULL;
  while(n->next != NULL){
    a = n;
    n = n->next;
  }
  if(a != NULL)
    a->next = NULL;
  free(n);
}

int size(list *l){
  return l->n;
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

int insertPosition(list *l, int v, int pos){
    int max = size(l), i;
    if(pos >=0 && pos<max){
        node *n =(node*)malloc(sizeof(node));
        n->data = v;
        node *p = l->begin;
        node *a = NULL;
        for(i = 0; i<pos; i++){
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
        //Incrementando o tamanho da List
        l->n++;
        return 0;
    }
    return -1;
}

int removePosition(list *l, int pos){
    int max = size(l), i;
    if(pos >=0 && pos<max){
        node *p = l->begin;
        node *a = NULL;
        for(i=0; i<pos; i++){
            a = p;
            p = p->next;
        }
        if(a == NULL) l->begin = p->next;
        else a->next = p->next;
        free(p);
        //Decrementando o tamanho da List
        l->n--;
        return 0;
    }
    return -1;
}

int removeElement(list *l, int v){
    int pos = hasElement(l, v);
    if(pos <0) return -1;
    //A função chamada já decrementa nosso tamanho
    removePosition(l, pos);
    return pos;

}

int get(list *l, int pos, int *vret){
    int max = size(l), i;
    if(pos >=0 && pos<max){
        node *p = l->begin;
        for(i = 0; i<pos; i++){
            p = p->next;
        }
        *vret = p->data;
        return 0;
    }
    return -1;
}