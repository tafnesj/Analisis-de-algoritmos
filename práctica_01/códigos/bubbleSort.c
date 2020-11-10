/*
  Título: Ordenamiento por método de burbuja.
  Descripción: Implementación de función de Bubble sort.
  Fecha: 01/Noviembre/2020.
  Versión: Versión 1.0
  Autor: Tafnes Lorena Jiménez Aguilar.
*/

#include <stdio.h>

// Recibe un arreglo y un valor n
void bubbleSort(int arr[], int n){
  int i, j; // variables para loops
  int temp; // Variable auxiliar
  
  // Iteración por los n valores del array
  for(i=0; i<n-1; i++){
    for(j=0; j<(n-1)-i; j++){
      // Comparación si arr[j] es mayor que el array en la siguiente posición
      if(arr[j]>arr[j+1]) {
        // Swap si arr[j] es mayor
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }  
  }
}