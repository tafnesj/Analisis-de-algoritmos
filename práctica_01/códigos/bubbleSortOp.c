/*
  Título: Ordenamiento por método de burbuja optimizado.
  Descripción: Implementación de función de Bubble sort de manera optimizada.
  Fecha: 01/Noviembre/2020.
  Versión: Versión 1.0
  Autor: Tafnes Lorena Jiménez Aguilar.
*/

#include <stdio.h>

// Recibe un arreglo y un valor n
void bubbleSortOp(int arr[], int n){
  // Variable bandera y auxiliar
  int cambios=1, aux; 
  int i, j; // Variables para loops
  // Entrar mientras la bandera no sea 0
  while(i<n-1 && cambios!=0){
    // Cambio de la bandera
    cambios=0;
    // Iteración con decremento para optimizar
    // Recorre con cada iteración una posición menos
    for(j=0; j<(n-1)-i; j++){
      if(arr[j]>arr[j+1]){
        // Swap si arr[j] es mayor
        aux=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=aux;
        cambios=1; // Cambio de bandera
      }
    }
    // Incremento a la iteración del for
    i=i+1; 
  }
}