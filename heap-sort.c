#include <stdio.h>

void maxHeapify(int a[], int i, int heapSize) {
  int aux = 0;
  int maior = 0;
  int leftChild = i << 1;
  int rightChild = leftChild + 1;

  if (leftChild <= heapSize && a[leftChild] > a[i]) {
    maior = leftChild;
  } else {
    maior = i;
  }
  if (rightChild <= heapSize && a[rightChild] > a[maior]) {
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
  for (int i = heapSize / 2; i > 0; i--) {
    maxHeapify(a, i, heapSize);
  }
}

void heapSort(int a[], int heapSize) {
  int aux = 0;
  buildMaxHeap(a, heapSize);
  for (int lastElem = heapSize; lastElem > 1; lastElem--) {
    aux = a[0];
    a[0] = a[lastElem];
    a[lastElem] = aux;
    heapSize--;
    maxHeapify(a, 0, heapSize); //0 == primeiro elemento
  }
}

int main() {
  // Declaração de variáveis
  int a[] = {10, 20, 8, 4, 5};
  int heapSize = sizeof(a)/sizeof(a[0]); // sizeof recebe o tamanho do vetor e após isso
  int i = 0;							 // divide pelo valor de um int(4) para saber o número de elementos

  // Impressão dos valores presentes no vetor DESORDENADO
  printf("\n\tMétodo de ordenação 'Heap Sort'\n");
  printf("\tVetor inicial:{");
  for (; i < heapSize; i++) {
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
  for (i = 0; i < heapSize; i++) {
    if (i != heapSize - 1)
      printf("%d, ", a[i]);
    else
      printf("%d", a[i]);
  }
  printf("}\n\n");

  return 0;
}
