#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node node;

typedef struct {
  node *begin;

} list;

list *createList(){
  list *l = (list*)malloc(sizeof(list));
  l->begin = NULL;
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
  node *n = l->begin;
  int cont = 0;
  while(n != NULL){
    cont++;
    n = n->next;
  }
  return cont;
}

int main(void){
  int v, s, n, i;
  list *l =  createList();
  printf("Adicionado os valores:\n");
  add(l, 1);
  add(l, 5);
  add(l, 3);
  add(l, 5);

  printList(l);
  printf("Size: %d\n", size(l));
  printf("%d\n",isEmpty(l));


  removeBack(l);
  removeBack(l);

  printf("Após removermos alguns valores nossa lista ficou:\n");
  printList(l);
  printf("Size: %d\n", size(l));
  printf("%d\n",isEmpty(l));


}