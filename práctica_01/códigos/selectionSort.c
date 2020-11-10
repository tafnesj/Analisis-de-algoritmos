/*
  Título: Ordenamiento por método de Selección.
  Descripción: Implementación de función de Selection sort.
  Fecha: 01/Noviembre/2020.
  Versión: Versión 1.0
  Autor: Tafnes Lorena Jiménez Aguilar.
*/

#include<stdio.h>

void selectionSort(int arr[], int n){
  int i=0, k=0, p=0; // Variables para Loops
  int temp=0; // Variable auxiliar 
  // Iteración por los n valores del array
  for(k=0; k<n-1; k++){
    p=k;
    // Búsqueda del mínimo elemento
    for(i=k+1; i<n; i++){
      if(arr[i]<arr[p]){
        // Guarda la posición del elemento
        p=i;
      }
    }
    // Swaps para ordenamiento
    temp=arr[p];
    arr[p]=arr[k];
    arr[k]=temp;
  }
}