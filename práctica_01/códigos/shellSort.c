/*
  Título: Ordenamiento por shell.
  Descripción: Implementación de función de Shell sort.
  Fecha: 01/Noviembre/2020.
  Versión: Versión 1.0
  Autor: Tafnes Lorena Jiménez Aguilar.
*/

#include <stdio.h>

void shellSort(int arr[], int n){
  int distancia=n/2; // Variable para partición
  int i, j; // Variables para Loops
  int temp; // Variable auxiliar
  // Recorre mientras la distancia no sea 0
  while(distancia>0){
    i=1;
    // Mientras la posición no sea 0
    while(i!=0){
      i=0;
      // Iteración por los n elementos del array
      for(j=distancia; j<=n-1; j++){
        if(arr[j-distancia]>arr[j]){
          // Swaps para ordenamiento
          temp=arr[j];
          arr[j]=arr[j-distancia];
          arr[j-distancia]=temp;
          i++;
        }
      }
    }
    // Particiones a la mitad
    distancia/=2; 
  }
}