#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* INTEGRANTES DO GRUPO:
 * FERNANDO CESAR GIMENES
 * GABRIEL COELHO SOARES
 * LUIS FELIPE GALDINO ZAVARIZZE
 * MARCOS MOREIRA
 * MATEUS ARAÚJO
 */

void randomizaMatriz(int x, int y, int m[x][y]) {
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      m[i][j] = rand() % 19 - 9;
    }
  }
}

void exibeMatriz(int x, int y, int m[x][y], char n[]) {
  printf("\nExibindo Matriz(%s)\n\n", n);
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      printf("%d \t", m[i][j]);
    }
    printf("\n");
  }
}

void subtraiMatriz() {
  int linhas_a, linhas_b, colunas_a, colunas_b;
  printf("Entre com a ordem da primeira matriz: A\nLinhas: ");
  scanf("%d", &linhas_a);
  printf("Colunas: ");
  scanf("%d", &colunas_a);
  int matriz_a[linhas_a][colunas_a];
  printf("\nEntre com a ordem da segunda matriz: B\nLinhas: ");
  scanf("%d", &linhas_b);
  printf("Colunas: ");
  scanf("%d", &colunas_b);
  int matriz_b[linhas_b][colunas_b];
  randomizaMatriz(linhas_a, colunas_a, matriz_a);
  randomizaMatriz(linhas_b, colunas_b, matriz_b);
  printf("Aguarde enquanto randomizamos os elementos das matrizes...\n");
  sleep(2);
  exibeMatriz(linhas_a, colunas_a, matriz_a, "A");
  exibeMatriz(linhas_b, colunas_b, matriz_b, "B");
  sleep(1);
  if (linhas_a != linhas_b || colunas_a != colunas_b) {
    printf("A subtração não pode ser feita pois não possuem a mesma "
           "ordem:\nA(%dx%d) e B(%dx%d)\n\n",
           linhas_a, colunas_a, linhas_b, colunas_b);
    sleep(1);
  } else {
    int matriz_subtraida[linhas_a][colunas_b];
    for (int i = 0; i < linhas_a; i++) {
      for (int j = 0; j < colunas_b; j++) {
        matriz_subtraida[i][j] = matriz_a[i][j] - matriz_b[i][j];
      }
    }
    exibeMatriz(linhas_a, linhas_b, matriz_subtraida, "A-B");
    printf("Retornando ao menu principal\n");
    sleep(2);
  }
}

void somaMatriz() {
  int linhas_a, linhas_b, colunas_a, colunas_b;
  printf("Entre com a ordem da primeira matriz: A\nLinhas: ");
  scanf("%d", &linhas_a);
  printf("Colunas: ");
  scanf("%d", &colunas_a);
  int matriz_a[linhas_a][colunas_a];
  printf("\nEntre com a ordem da segunda matriz: B\nLinhas: ");
  scanf("%d", &linhas_b);
  printf("Colunas: ");
  scanf("%d", &colunas_b);
  int matriz_b[linhas_b][colunas_b];
  randomizaMatriz(linhas_a, colunas_a, matriz_a);
  randomizaMatriz(linhas_b, colunas_b, matriz_b);
  printf("Aguarde enquanto randomizamos os elementos das matrizes...\n");
  sleep(2);
  exibeMatriz(linhas_a, colunas_a, matriz_a, "A");
  exibeMatriz(linhas_b, colunas_b, matriz_b, "B");
  sleep(1);
  if (linhas_a != linhas_b || colunas_a != colunas_b) {
    printf("A soma não pode ser feita pois não possuem a mesma "
           "ordem:\nA(%dx%d) e B(%dx%d)\n\n",
           linhas_a, colunas_a, linhas_b, colunas_b);
    sleep(1);
  } else {
    int matriz_subtraida[linhas_a][colunas_b];
    for (int i = 0; i < linhas_a; i++) {
      for (int j = 0; j < colunas_b; j++) {
        matriz_subtraida[i][j] = matriz_a[i][j] + matriz_b[i][j];
      }
    }
    exibeMatriz(linhas_a, linhas_b, matriz_subtraida, "A+B");
    printf("Retornando ao menu principal\n");
    sleep(2);
  }
}

void multiplicaMatriz() {
  int linhas_a, linhas_b, colunas_a, colunas_b;
  printf("Entre com a ordem da primeira matriz: A\nLinhas: ");
  scanf("%d", &linhas_a);
  printf("Colunas: ");
  scanf("%d", &colunas_a);
  int matriz_a[linhas_a][colunas_a];
  printf("\nEntre com a ordem da segunda matriz: B\nLinhas: ");
  scanf("%d", &linhas_b);
  printf("Colunas: ");
  scanf("%d", &colunas_b);
  int matriz_b[linhas_b][colunas_b];
  randomizaMatriz(linhas_a, colunas_a, matriz_a);
  randomizaMatriz(linhas_b, colunas_b, matriz_b);
  printf("Aguarde enquanto randomizamos os elementos das matrizes...\n");
  sleep(2);
  exibeMatriz(linhas_a, colunas_a, matriz_a, "A");
  exibeMatriz(linhas_b, colunas_b, matriz_b, "B");
  sleep(1);
  if (colunas_a != linhas_b) {
    printf("Não é possível realizar a multiplicação, pois a ordem delas não "
           "permite.\nA(%dx%d) e B(%dx%d)\n\n",
           linhas_a, colunas_a, linhas_b, colunas_b);
    sleep(1);
  } else {
    int matriz_multiplicada[linhas_a][colunas_b];
    int somatoria = 0;
    for (int i = 0; i < linhas_a; i++) {
      for (int j = 0; j < colunas_b; j++) {
        for (int k = 0; k < linhas_b; k++) {
          somatoria += matriz_a[i][k] * matriz_b[k][j];
        }
        matriz_multiplicada[i][j] = somatoria;
        somatoria = 0;
      }
    }
    exibeMatriz(linhas_a, colunas_b, matriz_multiplicada, "AxB");
    sleep(1);
  }
}

int laplaceMatriz(int n, int matriz_a[n][n]) {
  int result = 0;
  if (n == 3) {
    result = +((matriz_a[0][0] * matriz_a[1][1] * matriz_a[2][2]) +
               (matriz_a[0][1] * matriz_a[1][2] * matriz_a[2][0]) +
               (matriz_a[0][2] * matriz_a[1][0] * matriz_a[2][1])) -
             ((matriz_a[0][2] * matriz_a[1][1] * matriz_a[2][0]) +
              (matriz_a[0][0] * matriz_a[1][2] * matriz_a[2][1]) +
              (matriz_a[0][1] * matriz_a[1][0] * matriz_a[2][2]));
  } else {
    int exclude = 0, col = 0, matriz_b[3][3];
    // linha excluida 1
    for (int e = 0; e < n; e++) {
      for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (j == e) {
            continue;
          }
          matriz_b[i - 1][col] = matriz_a[i][j];
          col++;
        }
        col = 0;
      }
      int sinal = (e % 2 == 0) ? 1 : -1;
      result += (sinal * matriz_a[0][e]) * laplaceMatriz(3, matriz_b);
    }
  }
  return result;
}

void determinanteMatriz() {
  int result, ma, na;
  printf("Entre com a ordem da primeira matriz: A\nLinhas: ");
  scanf("%d", &ma);
  printf("Colunas: ");
  scanf("%d", &na);
  int matriz_a[ma][na];
  randomizaMatriz(ma, na, matriz_a);
  exibeMatriz(ma, na, matriz_a, "A");
  sleep(1);
  if (ma != na) {
    printf("A Matriz não é quadrada, sendo impossível declarar seu "
           "determinante\n\n\n");
    sleep(2);
  } else {
    switch (ma) {
    case 1:
      printf("O Determinante da matriz indicada é: %d\n\n", matriz_a[0][0]);
      sleep(1);
      break;
    case 2:
      result =
          (matriz_a[0][0] * matriz_a[1][1]) - (matriz_a[0][1] * matriz_a[1][0]);
      printf("O determinante da matriz indicada é: %d\n\n", result);
      sleep(1);
      break;
    case 3:
      printf("O determinante da matriz indicada é: %d\n\n",
             laplaceMatriz(ma, matriz_a));
      sleep(1);
      break;
    case 4:
      printf("O determinante da matriz indicada é: %d\n\n",
             laplaceMatriz(ma, matriz_a));
      break;
      // default:
      // printf("Matriz quadrada maior do que o proposto, por favor, tente com "
      // "outra menor!\nMaximo 4x4");
      // sleep(1);
      // break;
    }
  }
}

int main(int argc, char *argv[]) {
  char matriz_a_nome[2] = "A", matriz_b_nome[2] = "B";
  int linhas_a, linhas_b, colunas_a, colunas_b, menu = 0;
  srand(time(NULL));
  while (menu == 0) {
    printf("--------- OPERAÇÕES MATRICIAIS --------\n\n");
    printf("Escolha uma operação "
           "matricial:\n\n1.Soma\t2.Subtração\n3.Multiplicação\t4."
           "Determinante\n\n9. Sair do programa\n");
    scanf("%d", &menu);
    switch (menu) {
    case 1:
      somaMatriz();
      menu = 0;
      break;
    case 2:
      subtraiMatriz();
      menu = 0;
      break;
    case 3:
      multiplicaMatriz();
      menu = 0;
      break;
    case 4:
      determinanteMatriz();
      menu = 0;
      break;
    case 9:
      printf("Saindo do programa...\n");
      sleep(1);
      return 0;
      break;
    default:
      printf("Escolha uma opção válida\n");
      menu = 0;
      break;
    }
  }
  return EXIT_SUCCESS;
}
