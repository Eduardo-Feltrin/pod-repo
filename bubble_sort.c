#include <stdio.h>

int main()
{
	//Declaração das variáveis
	int vetor[10]={8,5,2,6,10,1,3,7,9,4}, i=0, j=0, aux=0, flag=0;

	//Impressão dos valores presentes no vetor DESORDENADO
	printf("\n\tMétodo de ordenação 'Bubble Sort'\n");
	printf("\tVetor inicial:{");
	for(;i<10;i++)
	{
		if(i!=9)
		{
			printf("%d, ", vetor[i]);
		}
		else
		{
			printf("%d", vetor[i]);
		}
	}
	printf("}\n");

	//Aplicação da técnica "Bubble Sort"
	for(i=10;i>0;i--)
	{
		flag=0;
		for(j=0;j<10;j++)
		{
			if (vetor[j]>vetor[j+1])
			{
				aux=vetor[j];
				vetor[j]=vetor[j+1];
				vetor[j+1]=aux;
				flag=1;
			}
		}
		if(flag==0) break;
	}

	//Impressão dos valores presentes no vetor ORDENADO
	printf("\tVetor ordenado:{");
	for(i=0;i<10;i++)
	{
		if(i!=9) printf("%d, ", vetor[i]);
		else printf("%d", vetor[i]);
	}
	printf("}\n");

	return 0;
}

