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


list *l createList();

void add(list *l, int v);

void printList(list *l);

int isEmpty(list *l);

void removeBack(list *l);

int size(list *l);