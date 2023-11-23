#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

void subtraiMatriz(int ma, int na, int mb, int nb, int mxa[ma][na],
                   int mxb[mb][nb]) {
  if (ma != mb || na != nb) {
    printf("A subtração não pode ser feita pois não possuem a mesma "
           "ordem:\nA(%dx%d) e B(%dx%d)",
           ma, na, mb, nb);
    sleep(1);
  } else {
    int matriz_subtraida[ma][nb];
    for (int i = 0; i < ma; i++) {
      for (int j = 0; j < nb; j++) {
        matriz_subtraida[i][j] = mxa[i][j] - mxb[i][j];
      }
    }
    exibeMatriz(ma, nb, matriz_subtraida, "A-B");
    printf("Retornando ao menu principal\n");
    sleep(5);
  }
}

void somaMatriz(int ma, int na, int mb, int nb, int mxa[ma][na],
                int mxb[mb][nb]) {
  if (ma != mb || na != nb) {
    printf("A soma não pode ser feita pois não possuem a mesma "
           "ordem:\nA(%dx%d) e B(%dx%d)",
           ma, na, mb, nb);
    sleep(1);
  } else {
    int matriz_somada[ma][nb];
    for (int i = 0; i < ma; i++) {
      for (int j = 0; j < nb; j++) {
        matriz_somada[i][j] = mxa[i][j] + mxb[i][j];
      }
    }
    exibeMatriz(ma, nb, matriz_somada, "A+B");
    printf("Retornando ao menu principal\n");
    sleep(5);
  }
}

void multiplicaMatriz(int ma, int na, int mb, int nb, int mxa[ma][na],
                      int mxb[mb][nb]) {
  if (na != mb) {
    printf("Não é possível realizar a multiplicação, pois a ordem delas não "
           "permite.\nA(%dx%d) e B(%dx%d)\n\n",
           ma, na, mb, nb);
    sleep(1);
  } else {
    int matriz_multiplicada[ma][nb];
    int somatoria = 0;
    for (int i = 0; i < ma; i++) {
      for (int j = 0; j < nb; j++) {
        for (int k = 0; k < mb; k++) {
          somatoria += mxa[i][k] * mxb[k][j];
        }
        matriz_multiplicada[i][j] = somatoria;
        somatoria = 0;
      }
    }
    exibeMatriz(ma, nb, matriz_multiplicada, "AxB");
    sleep(1);
  }
}

void determinanteMatriz(int ma, int na, int mxa[ma][na]) {
  int result;
  if (ma != na) {
    printf("A Matriz não é quadrada, sendo impossível declarar seu "
           "determinante\n\n\n");
    sleep(2);
  } else {
    switch (ma) {
    case 1:
      printf("O Determinante da matriz indicada é: %d\n\n", mxa[0][0]);
      sleep(1);
      break;
    case 2:
      result = (mxa[0][0] * mxa[1][1]) - (mxa[0][1] * mxa[1][0]);
      printf("O determinante da matriz indicada é: %d\n\n", result);
      sleep(1);
      break;
    case 3:
      result = +((mxa[0][0] * mxa[1][1] * mxa[2][2]) +
                 (mxa[0][1] * mxa[1][2] * mxa[2][0]) +
                 (mxa[0][2] * mxa[1][0] * mxa[2][1])) -
               ((mxa[0][2] * mxa[1][1] * mxa[2][0]) +
                (mxa[0][0] * mxa[1][2] * mxa[2][1]) +
                (mxa[0][1] * mxa[1][0] * mxa[2][2]));
      printf("O determinante da matriz indicada é: %d\n\n", result);
      sleep(1);
      break;
    case 4:
      // a implementar
      break;
    default:
      printf("Matriz quadrada maior do que o proposto, por favor, tente com "
             "outra menor!\n");
      break;
    }
  }
}

int main(int argc, char *argv[]) {
  char matriz_a_nome[2] = "A", matriz_b_nome[2] = "B";
  int linhas_a, linhas_b, colunas_a, colunas_b, menu = 0;
  printf("--------- OPERAÇÕES MATRICIAIS --------\n\n");
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
  while (menu == 0) {
    exibeMatriz(linhas_a, colunas_a, matriz_a, matriz_a_nome);
    exibeMatriz(linhas_b, colunas_b, matriz_b, matriz_b_nome);
    sleep(4);
    printf("Escolha uma operação "
           "matricial:\n\n1.Soma\t2.Subtração\n3.Multiplicação\t4."
           "Determinante\n\n9. Sair do programa\n");
    scanf("%d", &menu);
    switch (menu) {
    case 1:
      somaMatriz(linhas_a, colunas_a, linhas_b, colunas_b, matriz_a, matriz_b);
      menu = 0;
      break;
    case 2:
      subtraiMatriz(linhas_a, colunas_a, linhas_b, colunas_b, matriz_a,
                    matriz_b);
      menu = 0;
      break;
    case 3:
      multiplicaMatriz(linhas_a, colunas_a, linhas_b, colunas_b, matriz_a,
                       matriz_b);
      menu = 0;
      break;
    case 4:
      printf("Determinante da matriz (A)\n");
      determinateMatriz(linhas_a, colunas_a, matriz_a);
      printf("Determinante da matriz (B)\n");
      determinanteMatriz(linhas_b, colunas_b, matriz_b);
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
