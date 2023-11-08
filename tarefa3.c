// ATIVIDADE 3 //
// MATEMATICA DISCRETA ADS //
// Enviar apenas o arquivo.C (pode ser txt). Nao enviar word, pdf ou outra
// extensao. Todos os integrantes do grupo devem enviar a mesma atividade feita
// pela equipe Inserir o nome completo de todos os integrantes
// INTEGRANTE: GABRIEL COELHO SOARES

/////////////////////////////////////////////////////////////////////////
///       FUNCAO PRINCIPAL A SER IMPLEMENTADA PELO GRUPO               ///
///       FUNCAO RECEBE  os inteiros OPCAO, n                       ///
///       FUNCAO IRA RETORNAR:                                        ///
///               aproximacao do numero de Euler e - SE OPCAO 1    ///
///               aproximacao do número de Euler pi - SE OPCAO 2        ///
///               -1 - SE OUTRA   OPCAO                                  ///
///////////////////////////////////////////////////////////////////

#include <math.h>
#include <stdio.h>

int fatorial(int n) {
  if (n == 0) {
    return 1;
  } else if (n < 0) {
    return -2;
  } else {
    int i = n - 1;
    while (i > 0) {
      n = n * i;
      i--;
    }
  }
  return n;
}

float aproximacao(int opcao, int n) {
  double calcFat, somatoria = 0;
  if (opcao == 1) {
    somatoria = 0;
    for (int i = 0; i <= n; i++) {
      calcFat = fatorial(i);
      somatoria = somatoria + (1 / calcFat);
    }
  } else if (opcao == 2) {

    somatoria = 0;
    for (int i = 0; i <= n; i++) {
      somatoria = somatoria + (8.00 / ((4 * i + 1) * (4 * i + 3)));
    }
  } else {
    return -1;
  }
  return somatoria;
}

/////////////////////////
/// CODIGO PARA TESTE ///
////////////////////////
int main() {

  int opcao, n;

  printf("***********************************************************\n");
  printf("APROXIMACAO DAS CONSTANTES NUMERO DE EULER e PI\n");
  printf("***********************************************************\n");

  for (opcao = 1; opcao <= 3; opcao++) {
    if (opcao == 1) {
      for (n = 0; n <= 5; n++) {
        printf("OPCAO %d: e(n= %d) = %f\n", opcao, n, aproximacao(opcao, n));
      }
    } else if (opcao == 2) {
      for (n = 0; n <= 5; n++) {
        printf("OPCAO %d: pi(n = %d) = %f\n", opcao, n, aproximacao(opcao, n));
      }
    } else {
      printf("OPCAO %d: OPERACAO INEXISTENTE", opcao);
    }
  }
  return 0;
}
