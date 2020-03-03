#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double x, y;
} Ponto;


typedef struct {
  double a, b, c;
} Reta;

double dist(Ponto p, Ponto q){
  
  double dist = sqrt(pow((p.x - q.x), 2) + pow((p.y - q.y),2));
  return dist;
}

double ponto_naReta(Ponto p, Reta r){
  
  if((p.x * r.a + p.y * r.b + r.c) == 0) {
    return 1;
  } else{
    return 0;
  }
}

double dit_reta(Ponto p, Reta r){
    double dist_reta = fabs((r.a)*(p.x) + (r.b)*(p.y) + r.c)/sqrt(pow((r.a),2)+pow((r.b),2));
    return dist_reta;
}


int main(void){
    Ponto p, q;
    Reta rt;
    p.x = 2;
    p.y = 1;
    q.x = 3;
    q.y = 4;
    rt.a = 1;
    rt.b = 2;
    rt.c = 3;

    printf("Distancia entre os dois pontos: %.2lf\n", dist(p,q));
    int pontoLinha = ponto_naReta(p, rt);
    if(pontoLinha) printf("O primeiro ponto esta na reta!\n");
    else{
        printf("O primeiro ponto nao esta na reta!\n");

        printf("Distancia do primeiro ponto para a reta: %.2lf\n", dit_reta(p, rt));
    }

}
