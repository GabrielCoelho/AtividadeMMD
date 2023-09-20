#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int fatorial(int n){
	int i=n-1;
	while(i>0){
		n=n*i;
		i--;
	}
	return n;
}

int permutacao(int perm){
	perm=(fatorial(perm));
	return perm;
}

int arranjo(int el, int k){
	k = el-k;
	el=fatorial(el);
	k=fatorial(k);
	return el/k;
}

double combinacao(int n, int k){
	int j;
	j = (n-k);
	n = fatorial(n);
	j = fatorial(j);
	k = fatorial(k);
	return n/(k*j);
}

double logica(int a,int b){
	int op;
	if(a == b){
		printf("Número de Elementos igual ao de Posições\n      EXECUTANDO: PERMUTAÇÃO SIMPLES\n\n");
		return permutacao(a);
	}else if(b < a){
		printf("Podemos fazer um Arranjo ou uma Combinação, qual voce prefere?\n\n1 para Arranjo\n2 para Combinação: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("EXECUTANDO: ARRANJO SIMPLES\n\n");
				return arranjo(a, b);
				break;
			case 2:
				printf("EXECUTANDO: COMBINAÇÃO SIMPLES\n\n");
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
	printf("Atividade 2 de Matemática \n\n");
	// Nome: Gabriel Coelho Soares
	int option, posicao, elementos;

	printf("ORGANIZADOR AUTOMÁTICO\n");
	printf("Aqui, basta indicar o número de elementos e posições para executarmos:\n   Permutação Simples\n   Arranjo Simples\n   Combinação Simples\n\n");
	printf("Indique o número de elementos: ");
	scanf("%d", &elementos);
	printf("Agora nos informe o número de posicoes: ");
	scanf("%d", &posicao);
	printf("As possibilidades de organização são: %.1f", logica(elementos, posicao));
}
