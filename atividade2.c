#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int permutacao(int perm){
	int i;
	i = perm -1;
	while(i>0){
		perm = perm*i;
		i--;
	}
	return perm;
}

int arranjo(int el, int k){
	double res;
	int i, j; 
	i=el-1;
	j = (el-k);
	while(i>0){
		el=el*i;
		i--;
	}
	i=j-1;
	while(i>0){
		j=j*i;
		i--;
	}
	res = el/j;
	return res;
}

double combinacao(int n, int k){
	double res;
	int i, j; 
	i=n-1;
	j = (n-k);
	while(i>0){
		n=n*i;
		i--;
	}
	i=j-1;
	while(i>0){
		j=j*i;
		i--;
	}
	i=k-1;
	while(i>0){
		k=k*i;
		i--;
	}
	res = n/(k*j);
	return res;
}

double logica(int a,int b){
	int op;
	if(a == b){
		return permutacao(a);
	}else if(b < a){
		printf("Podemos fazer um Arranjo ou uma Combinação, qual voce prefere?\n\n1 para Arranjo\n2 para Combinação: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				return arranjo(a, b);
				break;
			case 2:
				return combinacao(a, b);
				break;
			default:
				printf("Voce digitou uma opcao invalida, fechando o programa");
		}
		return arranjo(a,b);
	}else{
	return -1;}
}


int main(void) {
	printf("Atividade de Matematica 2");
	// Nome: Gabriel Coelho Soares
	int option, posicao, elementos;

	printf("Seja bem vindo ao organizador automatico\n");
	printf("Aqui, basta indicar o numero de elementos e posicoes para executarmos:\n1. Permutação Simples\n2. Arranjo Simples\nCombinação Simples\n\n");
	printf("Indique o numero de elementos: ");
	scanf("%d", &elementos);
	printf("Agora nos informe o numero de posicoes: ");
	scanf("%d", &posicao);
	printf("As possibilidades de sua logica resultaram em: %.1f", logica(elementos, posicao));
}
