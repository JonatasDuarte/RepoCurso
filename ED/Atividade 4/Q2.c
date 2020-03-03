#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int verifyListInt(const char *s){
    int cont = 0, i;
    for(i=0; s[i]!='\0'; i++){
        if((s[i] >= '0' && s[i] <= '9') && (s[i+1] == ' ' | s[i+1] == '\0')){
            cont++;
        } else if((s[i] < '0' | s[i]>'9') && s[i] != ' '){
            return 0;
        }
        
    }
    return cont;
}

int* splitInt(const char *s, int *size){
    int tam = verifyListInt(s);
    *size = tam;
    if(tam == 0) return NULL;
    int* vet = (int*)malloc(tam*sizeof(int));
    int i,j, veti = 0;
    char aux[10];
    int ind= 0;

    for(i=0; s[i] != '\0'; i++){
        if(s[i] != ' '){
            aux[ind] = (s[i]);
            ind++;
        }
        if((s[i+1] == ' ' | s[i+1] == '\0') && ind != 0){
            aux[ind] = '\0';
            vet[veti] = atoi(aux);
            veti++;
            ind = 0;
        }
    }
    return vet;
}

int main(){
    char ent[100];
    scanf("%[^\n]s", ent);
    int size;
    int *ent_int = splitInt(ent, &size);
    if(ent_int==NULL){
        printf("String inválida\n");
        return 1;
    }
    printf("Size: %d\n", size);
    int i;
    for(i = 0; i<size; i++){
        printf("%d\n", ent_int[i]);
    }
    return 0;
}