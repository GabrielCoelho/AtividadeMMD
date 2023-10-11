#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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


int main(int argc, char *argv[])
{
  int indFinal;
  double calcFat, somatoria = 0;
  FILE *fro = fopen("euler.in", "r");
  FILE *fwr = fopen("euler.out", "w+");
  while (fscanf(fro, "%d ", &indFinal)!=EOF) { 
    somatoria = 0;
    for(int i = 0; i<=indFinal; i++){
      calcFat = fatorial(i);
      somatoria = somatoria + (1/calcFat);
    }

    fprintf(fwr, "%.18lf\n", somatoria);
  }
  fclose(fro);
  fclose(fwr);
  fro=fopen("pi.in", "r");
  fwr=fopen("pi.out", "w+");
  while (fscanf(fro, "%d", &indFinal)!=EOF) {
    somatoria = 0;
    for(int i=0; i<=indFinal;i++){
      somatoria = somatoria + (8.00/((4*i+1)*(4*i+3)));
    }
    fprintf(fwr, "%.18lf\n", somatoria);
  }
  return EXIT_SUCCESS;
}
