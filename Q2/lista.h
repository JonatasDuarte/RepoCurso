#include<stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

typedef struct{
    node *begin;
}list;


list *createList();

void add(list *l, int v);

void printList(list *l);

int isEmpty(list *l);

void removeBack(list *l);

int size(list *l);

int hasElement(list *l, int v);

int insertionPosition(list *l, int v, int pos);

int removePosition(list *l, int pos);

int removeElement(list *l, int v);

int get(list *l, int pos, int *vret);