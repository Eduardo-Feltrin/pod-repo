#include <stdio.h>

int main(void) {
  //Declaração de variáveis
  int vet[10]={10,20,8,4,5,3,2,6,7,9};
  int i=0, j=0, p=0;

  //Impressão dos valores presentes no vetor DESORDENADO
	printf("\n\tMétodo de ordenação 'Insertion Sort'\n");
	printf("\tVetor inicial:{");
	for(;i<10;i++)
	{
		if(i!=9)
		{
			printf("%d, ", vet[i]);
		}
		else
		{
			printf("%d", vet[i]);
		}
	}
	printf("}\n");
  
  //Insertion Sort
  for(i=1;i<10;i++)
    {
      p=vet[i];
      for(j=i;j>=1&&p<vet[j-1];j--)
        {
          vet[j]=vet[j-1];
        }
      vet[j]=p;
    }

  //Impressão dos valores presentes no vetor ORDENADO
	printf("\tVetor ordenado:{");
	for(i=0;i<10;i++)
	{
		if(i!=9) printf("%d, ", vet[i]);
		else printf("%d", vet[i]);
	}
	printf("}\n\n");
  
  return 0;
}