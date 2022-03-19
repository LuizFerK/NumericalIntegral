#include <stdio.h>
#include <math.h>

int main() {
  // Declaração de variáveis
  float a, b, n, aux, tmp, i, w, ed = 0, ee = 0;

  // Pegar as informações necessárias
  printf("Por favor, digite as informações necessárias.\n");

  // a = limite inferior; b = limite superior
  printf("Intervalo a b: ");
  scanf("%f %f", &a, &b);

  // n = número de subintervalos
  printf("Número de subintervalos: ");
  scanf("%f", &n);

  // func = f(x) e^(-2x) + 2
  float func(float x) {
    aux = -2 * x;
    return pow(M_E, aux) + 2;
  }

  // Caso o limite inferior for maior que o
  // superior, faz a inversão dos limites
  if (a > b) {
    tmp = a;
    a = b;
    b = tmp;
  }
  
  // w = tamanho de cada passo/coluna
  w = (b - a) / n;

  // ed = soma dos valores de área
  // aplicados a extrema direita da coluna
  i = a;
  while (i <= b - w) {
    i += w;
    ed += w * func(i);
  }

  // ee = soma dos valores de área 
  // aplicados a extrema esquerda da coluna
  i = a;
  while (i < b) {
    ee += w * func(i);
    i += w;
  }

  // Saídas
  if (ed > ee) {
    printf("%f < área < %f\n", ee, ed);
  } else {
    printf("%f < área < %f\n", ed, ee);
  }
  printf("Aproximação da área da região plana: %f\n", (ee + ed) / 2);
  
  return 0;
}
