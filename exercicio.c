#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

  // Atividade 1 - MMD001 
  // Nome Completo: Gabriel Coelho Soares
  //
  //   FUNCAO A SER IMPLEMENTADA PELO GRUPO                  ///
///       FUNCAO RECEBE OPCAO (inteiro) E ANGULO [rad]         ///
///       FUNCAO IRA RETORNAR:                                  ///
///               sin(ANGULO) - SE OPCAO 1                      ///
///               cos(ANGULO) - SE OPCAO 2                      ///
///               tan(ANGULO) - SE OPCAO 3 E ANGULO VALIDO NO DOMINIO     ///
///               123456789   - SE OPCAO 3 E ANGULO INVALIDO NO DOMINIO   ///
///               RETORNAR -1 SE QUALQUER OUTRA OPCAO          ///
///////////////////////////////////////////////////////////////////

  
int logica(int opcao, int p, int q)
{
  switch (opcao) {
      case 1:
        if (p && q) {
          return 1;
        } else {
          return 0;
        } 
      case 2:
        if (p || q) {
          return 1;
        } else {
          return 0;
        } 
      case 2:
        if (!((!p || q) && (!q || p))) {
          return 1;
        } else {
          return 0;
        } 
      case 2:
        if (!p || q) {
          return 1;
        } else {
          return 0;
        } 
      case 2:
        if ((!p || q)&&(!q||p)) {
          return 1;
        } else {
          return 0;
        } 
      default:
       printf("Não deveria chegar aqui\n")
  }
}



/////////////////////////
/// CODIGO PARA TESTE ///
////////////////////////
int main()
{
    int opcao, p, q, soma;
    float nota;
   
    p = 1;
    q = 0;
    printf("***********************************************************\n");
    printf("Considere 1 para VERDADEIRO e 0 para FALSO\n");
    printf("TESTE DIRETO para p = %d e q = %d em cada uma das opcoes\n",p,q);
    printf("***********************************************************\n");

    for (opcao = 1; opcao <= 6; opcao++){
        if (opcao == 1){
            printf("OPCAO %d: %d ^ %d = %d\n",opcao,p,q,logica(opcao,p,q));
            }
        else if (opcao == 2){
            printf("OPCAO %d: %d v %d = %d\n",opcao,p,q,logica(opcao,p,q));
        }
        else if (opcao == 3){
            printf("OPCAO %d: %d _v_ %d = %d\n",opcao,p,q,logica(opcao,p,q));
        }
        else if (opcao == 4){
            printf("OPCAO %d: %d --> %d = %d\n",opcao,p,q,logica(opcao,p,q));
        }
        else if (opcao == 5){
            printf("OPCAO %d: %d <--> %d = %d\n",opcao,p,q,logica(opcao,p,q));
        }
        else{
            printf("OPCAO %d: OPCAO INEXISTENTE", opcao);
        }
    }
   
 // TESTANDO TODOS OS VALORES
    printf("\n***********************************************************\n");
    printf("Analise para toda a tabela verdade em cada um dos casos\n");
    printf("***********************************************************\n");
    nota = 0.0;
    soma = 0;
    p = 1; q = 1;
    if (logica(1,p,q)==1){
        soma = 25 + soma;
    }
    p = 1; q = 0;
    if (logica(1,p,q)==0){
        soma = 25 + soma;
    }
    p = 0; q = 1;
    if (logica(1,p,q)==0){
        soma = 25 + soma;
    }
    p = 0; q = 0;
    if (logica(1,p,q)==0){
        soma = 25 + soma;
    }
    printf("p ^ q: %d por cento de acerto na tabela verdade completa\n",soma);
    nota = soma+nota;

    soma = 0;
    p = 1; q = 1;
    if (logica(2,p,q)==1){
        soma = 25 + soma;
    }
    p = 1; q = 0;
    if (logica(2,p,q)==1){
        soma = 25 + soma;
    }
    p = 0; q = 1;
    if (logica(2,p,q)==1){
        soma = 25 + soma;
    }
    p = 0; q = 0;
    if (logica(2,p,q)==0){
        soma = 25 + soma;
    }
    printf("p v q: %d por cento de acerto na tabela verdade completa\n",soma);    
    nota = soma+nota;
 
    soma = 0;
    p = 1; q = 1;
    if (logica(3,p,q)==0){
        soma = 25 + soma;
    }
    p = 1; q = 0;
    if (logica(3,p,q)==1){
        soma = 25 + soma;
    }
    p = 0; q = 1;
    if (logica(3,p,q)==1){
        soma = 25 + soma;
    }
    p = 0; q = 0;
    if (logica(3,p,q)==0){
        soma = 25 + soma;
    }
    printf("p _v_ q: %d por cento de acerto na tabela verdade completa\n",soma);
    nota = soma+nota;
 
    soma = 0;
    p = 1; q = 1;
    if (logica(4,p,q)==1){
        soma = 25 + soma;
    }
    p = 1; q = 0;
    if (logica(4,p,q)==0){
        soma = 25 + soma;
    }
    p = 0; q = 1;
    if (logica(4,p,q)==1){
        soma = 25 + soma;
    }
    p = 0; q = 0;
    if (logica(4,p,q)==1){
        soma = 25 + soma;
    }
    printf("p --> q: %d por cento de acerto na tabela verdade completa\n",soma);
    nota = soma+nota;
 
    soma = 0;
    p = 1; q = 1;
    if (logica(5,p,q)==1){
        soma = 25 + soma;
    }
    p = 1; q = 0;
    if (logica(5,p,q)==0){
        soma = 25 + soma;
    }
    p = 0; q = 1;
    if (logica(5,p,q)==0){
        soma = 25 + soma;
    }
    p = 0; q = 0;
    if (logica(5,p,q)==1){
        soma = 25 + soma;
    }
    printf("p <--> q: %d por cento de acerto na tabela verdade completa\n",soma);
    nota = soma+nota;
   
    printf("\n***************************\n");
    printf("Nota da atividade = %.2f \n",0.1*nota/5);
    printf("*****************************\n");
   
    return 0;
}
