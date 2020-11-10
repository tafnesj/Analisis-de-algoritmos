/*
  Título: Ordenamiento por método de inseción.
  Descripción: Implementación de función de Insertion sort.
  Fecha: 01/Noviembre/2020.
  Versión: Versión 1.0
  Autor: Tafnes Lorena Jiménez Aguilar.
*/

#include<stdio.h>

// Recibe un arreglo y un valor n
void insertionSort(int arr[], int n){
  int i, j; // Variables para loops
  int temp; // Variable auxiliar
  // Iteración por los n valores del array
  for(i=0; i<n; i++){
    j=i;
    temp=arr[i];
    // Encuentra la posición donde debería ir
    // Buscando el menor
    while(j>0 && temp<arr[j-1]){
      // Se inserta el valor
      arr[j]=arr[j-1];
      j--;
    }
    // Swap
    arr[j]=temp;
  }
}