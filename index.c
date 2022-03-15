#include <stdio.h>
#include <math.h>

int main() {
  // Declaração de variáveis
  float a, b, n, aux, tmp, i, w, ed = 0, ee = 0;

  // Pegar as informações necessárias
  printf("Por favor, digite as informações necessárias.\n");

  printf("Intervalo a b: ");
  scanf("%f %f", &a, &b);

  // n = número de subintervalos
  printf("Número de subintervalos: ");
  scanf("%f", &n);

  float func(float x) {
    aux = -2 * x;
    return pow(M_E, aux) + 2;
  }

  if (a > b) {
    tmp = a;
    a = b;
    b = tmp;
  }
  
  w = (b - a) / n;

  i = a;
  while (i <= b) {
    i += w;
    ed += w * func(i);
  }

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
