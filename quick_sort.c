#include <stdio.h>

int particiona(int *A, int inicio, int fim)
{
  int posPivo = fim;
  int k = inicio, i;
  int aux = 0;
  
  for(i=inicio; i<fim; i++)
    {
      if(A[i]<=A[posPivo])
      {
        aux = A[k];
        A[k] = A[i];
        A[i] = aux;
        k++;
      }
    }
  if(A[k]>A[posPivo])
  {
    aux = A[k];
    A[k] = A[posPivo];
    A[posPivo] = aux;
    posPivo = k;
  }
  return posPivo;
}

void quickSort(int *A, int inicio, int fim)
{
  int posPivo;
  if(inicio<fim)
  {
    posPivo = particiona(A,inicio,fim);
    quickSort(A,inicio,posPivo-1);
    quickSort(A,posPivo+1,fim);
  }
}

int main(void) {
  //Declaração de variáveis
  int A[10]={10,4,3,6,7,2,1,6,2,8};
  int i=0;
  
  //Impressão dos valores presentes no vetor DESORDENADO
	printf("\n\tMétodo de ordenação 'Quick Sort'\n");
	printf("\tVetor inicial:{");
	for(;i<10;i++)
	{
		if(i!=9)
		{
			printf("%d, ", A[i]);
		}
		else
		{
			printf("%d", A[i]);
		}
	}
	printf("}\n");

  //Chamada da função "quickSort"
  quickSort(A,0,9);  //um vetor é um ponteiro que aponta para uma sequencia de n valores - aponta diretamente para o primeiro

  //Impressão dos valores presentes no vetor ORDENADO
	printf("\tVetor ordenado:{");
	for(i=0;i<10;i++)
	{
		if(i!=9) printf("%d, ", A[i]);
		else printf("%d", A[i]);
	}
	printf("}\n\n");
  
  return 0;
}
