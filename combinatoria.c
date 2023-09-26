// ATIVIDADE 2 
// MATEMATICA DISCRETA ADS 
// Máximo de 5 integrantes
// Nome: Gabriel Coelho Soares
// ADS Noite - 2023.2 - Matemática Discreta
//     FUNCAO PRINCIPAL A SER IMPLEMENTADA PELO GRUPO               
//     FUNCAO RECEBE  os inteiros OPCAO, n, k                       
//     FUNCAO IRA RETORNAR:                                        
//             permutacao de n - SE OPCAO 1                       
//              Arranjo de n tomados de k em k - SE OPCAO 2        
//             Combinaco de n tomados de k em k - SE OPCAO 3     


#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int fatorial(int n)
{
  if(n==0)
  {
    return 1;
  }
  else if (n<0) 
  {
    return -2;
  }
  else
  {  
	  int i=n-1;
	  while(i>0){
		  n=n*i;
		  i--;
	  }
  }
	return n;
}

bool elementoMenor(int a, int b)
{
  if (a<b) 
  {
    return false;
  }
  else
  {
    return true;
  }
}

int permutacao(int perm)
{
	return fatorial(perm);
}

int arranjo(int el, int k)
{
  if(elementoMenor(el,k))
  {
	  k = el-k;
	  el=fatorial(el);
	  k=fatorial(k);
	  return el/k;
  }
  else 
  {
    return -2;
  }
}

double combinacao(int n, int k)
{
  if (elementoMenor(n,k)) 
  {
  
	  int j;
	  j = (n-k);
	  n = fatorial(n);
	  j = fatorial(j);
	  k = fatorial(k);
	  return n/(k*j);
  }
  else 
  {
    return -2;
  }
}
// A funcao a ser implementada
int combinatoria(int opcao, int n, int k)
{
  switch (opcao) 
  {
    case 1:
      return permutacao(n);
      break;
    case 2:
    return arranjo(n,k);
      break;
    case 3:
    return combinacao(n,k);
      break;
      default:
    return -1;

  }
}


// NAO MODIFICAR O CODIGO TESTE ABAIXO///
int main()
{
    int opcao, n, k, soma;
    float nota;
   
    n = 5;
    k = 2;
    printf("***********************************************************\n");
    printf("ANALISE COMBINATORIA (SEM REPETICAO)\n");
    printf("Considerando n = %d e k = %d em cada uma das opcoes\n",n,k);
    printf("***********************************************************\n");

    for (opcao = 1; opcao <= 3; opcao++){
        if (opcao == 1){
            printf("OPCAO %d: P(%d) = %d\n",opcao,n,combinatoria(opcao,n,k));
            }
        else if (opcao == 2){
            printf("OPCAO %d: A(%d,%d) = %d\n",opcao,n,k,combinatoria(opcao,n,k));
        }
        else if (opcao == 3){
            printf("OPCAO %d: C(%d,%d) = %d\n",opcao,n,k,combinatoria(opcao,n,k));
        }
        else{
            printf("OPCAO %d: OPERACAO INEXISTENTE", opcao);
        }
    }
 
// TESTANDO ALGUNS CASOS
    printf("\n***********************************************************\n");
    printf("*** Analisando alguns casos validos e invalidos ***\n");
    printf("***********************************************************\n");
    nota = 0.0;
    soma = 0;

    if (combinatoria(1,0,1)==1){
        soma = 1 + soma;
        printf("P(0) = %d, resposta correta\n",combinatoria(1,0,1));
    }
   
    if (combinatoria(1,0,1)!=1){
            printf("Sua resposta: P(0) = %d\n", combinatoria(1,0,1));
            printf("Mas P(0) = 1, resposta incorreta\n");
    }
   
    if (combinatoria(1,1,1)==1){
        soma = 1 + soma;
        printf("P(1) = %d, resposta correta\n",combinatoria(1,1,1));
    }
   
    if (combinatoria(1,1,1)!=1){
            printf("Sua resposta: P(1) = %d. ", combinatoria(1,1,1));
            printf("Mas P(1) = 1, resposta incorreta\n");
    }
   
    if (combinatoria(1,5,2)==120){
        soma = 1 + soma;
        printf("P(5) = %d, resposta correta\n",combinatoria(1,5,2));
    }
   
    if (combinatoria(1,5,2)!=120){
            printf("Sua resposta: P(5) = %d. ",combinatoria(1,5,2));
            printf("Mas P(5) = 120, resposta incorreta\n");
    }
   
    if (combinatoria(1,-5,2)==-2){
        soma = 1 + soma;
        printf("P(-5) nao existe pq n<0, resposta correta\n");
    }
   
    if (combinatoria(1,-5,2)!=-2){
            printf("Sua resposta: P(-5) = %d. ",combinatoria(1,-5,2));
            printf("Mas P(-5) nao existe pq n<0, resposta incorreta\n");
    }
   
    if (combinatoria(2,5,2)==20){
        soma = 1 + soma;
        printf("A(5,2) = %d, resposta correta\n",combinatoria(2,5,2));
    }
   
    if (combinatoria(2,5,2)!=20){
            printf("Sua resposta: A(5,2) = %d. ",combinatoria(2,5,2));
            printf("Mas A(5,2) = 20, resposta incorreta\n");
    }
       
    if (combinatoria(2,2,5)==-2){
        soma = 1 + soma;
        printf("A(2,5) nao existe pq n<k, resposta correta\n");
    }
   
    if (combinatoria(2,2,5)!=-2){
            printf("Sua resposta: A(2,5) = %d. ",combinatoria(2,2,5));
            printf("Mas A(2,5) nao existe pq n<k, resposta incorreta\n");
    }
         
    if (combinatoria(3,5,2)==10){
        soma = 1 + soma;
        printf("C(5,2) = %d, resposta correta\n",combinatoria(3,5,2));
    }
   
    if (combinatoria(3,5,2)!=10){
            printf("Sua resposta: C(5,2) = %d. ",combinatoria(3,5,2));
            printf("Mas C(5,2) = 10, resposta incorreta\n");
    }
       
    if (combinatoria(3,2,5)==-2){
        soma = 1 + soma;
        printf("C(2,5) nao existe pq n<k, resposta correta\n");
    }
   
    if (combinatoria(3,2,5)!=-2){
            printf("Sua resposta: C(2,5) = %d. ",combinatoria(3,2,5));
            printf("Mas C(2,5) nao existe pq n<k, resposta incorreta\n");
    }
         
    nota = soma;
   
    printf("\n***************************\n");
    printf("Nota da atividade = %.2f \n",10*nota/8);
    printf("*****************************\n");
   
    return 0;
}

