#include <stdlib.h>
#include <stdio.h>
#include "arvorebinaria.h"

no *criaArvore(int v){
    no *raiz = (no*)malloc(sizeof(no));
    raiz->v = v;
    raiz->dir = raiz->esq = NULL;
    return raiz;
}

no * insertValue(no *raiz, int v){
    if(raiz == NULL){
        no *novo = (no*)malloc(sizeof(no));
        novo->v = v;
        novo->dir = novo->esq = NULL;
        raiz = novo;
    } else if(v < raiz->v)
        raiz->esq = insertValue(raiz->esq, v);
    else 
        raiz->dir = insertValue(raiz->dir, v);
    
    return raiz;
}

no *findValue(no *raiz, int v){
    if(raiz == NULL || raiz->v == v) return raiz;
    if(v < raiz->v)
        return findValue(raiz->esq, v);
    else 
        return findValue(raiz->dir, v);
}

void printTree(no *raiz){
    if(raiz!=NULL){
        printf("%d ", raiz->v);
        printTree(raiz->esq);
        printTree(raiz->dir);
    }
}

int getHeigh(no *raiz){
    if(raiz == NULL) return -1;
    int left = getHeigh(raiz->esq);
    int right = getHeigh(raiz->dir);
    if(left > right) 
        return (1+left);
    else
        return (1+right);
}

no *removeValue(no *remo, int v){
    if(remo == NULL) return remo;
    if(v<remo->v) 
        remo->esq = removeValue(remo->esq, v);

    else if(v>remo->v) 
        remo->dir = removeValue(remo->dir, v);

    else{
        if(remo->esq == NULL && remo->dir == NULL){
            free(remo);
            return NULL;

        }else if(remo->esq == NULL && remo->dir != NULL){
            no*a = remo->dir;
            free(remo);
            return a;

        } else {
            no *a= remo->esq;
            while(a->dir != NULL) a = a->dir;
            remo->v = a->v;
            a->v = v;
            remo->esq = removeValue(remo, v);
        }
    }
}

int size(no *raiz){
    if(raiz == NULL) return 0;
    else{
        int left = size(raiz->esq);
        int right = size(raiz->dir);    
        return (left+right+1);
    }
}

int sumX(no *raiz, int x){
    if(raiz != NULL){
        if(x < raiz->v){
            int left = sumX(raiz->esq,x);
            int right = sumX(raiz->dir,x);
            return (raiz->v + right+left); 
        } else{
            int left = sumX(raiz->esq,x);
            int right = sumX(raiz->dir,x);
            return (right+left);
        }
    }
}