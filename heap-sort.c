#include <stdio.h>

void maxHeapify(int a[], int i, int heapSize) {
  int aux = 0;
  int maior = 0;
  int leftChild = 2*i+1;
  int rightChild = 2*i+2;

  if (leftChild <= heapSize-1 && a[leftChild] > a[i]) {
    maior = leftChild;
  } else {
    maior = i;
  }
  if (rightChild <= heapSize-1 && a[rightChild] > a[maior]) { //????
    maior = rightChild;
  }
  if (maior != i) {
    aux = a[i];
    a[i] = a[maior];
    a[maior] = aux;
    maxHeapify(a, maior, heapSize); //checa recursivamente se o filho obedece a propriedade "max-heap"
  }
}

void buildMaxHeap(int a[], int heapSize) {
  for (int i = (heapSize / 2)-1; i >= 0; i--) { //-1 é para assegurar que as folhas não sejam iteradas
	maxHeapify(a, i, heapSize);
  }
}

void heapSort(int a[], int heapSize) {
  int aux = 0;
  buildMaxHeap(a, heapSize);
  for (int lastElem = heapSize; lastElem >= 1; lastElem--) {
    aux = a[0];
    a[0] = a[lastElem-1];
    a[lastElem-1] = aux;
    heapSize--;
    maxHeapify(a, 0, heapSize); //0 == primeiro elemento
  }
}

int main() {
  // Declaração de variáveis
  int a[] = {10, 20, 8, 4, 5};
  int heapSize = sizeof(a)/sizeof(a[0]); //sizeof recebe o tamanho do vetor e após isso divide pelo valor de um int(4) para saber o número de elementos

  // Impressão dos valores presentes no vetor DESORDENADO
  printf("\n\tMétodo de ordenação 'Heap Sort'\n");
  printf("\tVetor inicial:{");
  for (int i = 0; i < heapSize; i++) {
    if (i != heapSize - 1) {
      printf("%d, ", a[i]);
    } else {
      printf("%d", a[i]);
    }
  }
  printf("}\n");

  // Método de ordenação Heap Sort
  heapSort(a, heapSize);

  // Impressão dos valores presentes no vetor ORDENADO
  printf("\tVetor ordenado:{");
  for (int i = 0; i < heapSize; i++) {
    if (i != heapSize - 1)
      printf("%d, ", a[i]);
    else
      printf("%d", a[i]);
  }
  printf("}\n\n");

  return 0;
}
