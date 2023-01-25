#include <stdio.h>
#define heapSize 5;

void maxHeapify(int a[], int i) {
  int aux = 0;
  int maior = 0;
  int leftChild = i << 1;
  int rightChild = leftChild + 1;

  if (leftChild <= heapSize &&
      a[leftChild] > a[i]) { // sizeof recebe o tamanho do vetor e após isso
                             // divide por 4 para saber o número de elementos
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
    maxHeapify(a, maior);
  }
}

void buildMaxHeap(int a[]) {
  for (int i = heapSize / 2; i > 0; i--) {
    maxHeapify(a, i);
  }
}

void heapSort(int a[]) {
  int aux = 0;
  buildMaxHeap(a);
  for (int i = heapSize; i > 1; i--) {
    aux = a[0];
    a[0] = a[i];
    a[i] = aux;
    heapSize--;
    maxHeapify(a, 0);
  }
}

int main() {
  // Declaração de variáveis
  int a[] = {10, 20, 8, 4, 5};
  int i = 0;

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
  heapSort(a);

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
