/*
  Título: Búsqueda lineal.
  ---------------------------------------------------------------------
  Descripción: 
  Búsqueda de un valor "x" por medio de búsqueda lineal en un arreglo.
  Valores de entrada:
  * Arreglo de enteros, tamaño y valor "x" a buscar.
  Valores de retorno:
  * Si se encuentra retorna la posición. 
  * En caso contrario se retorna -1.
  ---------------------------------------------------------------------
  Fecha: 10/Noviembre/2020.
  Versión: 1.0
  Autor: Tafnes Jiménez.
*/

#include <stdio.h>

// Recibe un arreglo, su tamaño y valor "x" a buscar
int linealSearch(int arr[], int n, int x){
  int i; // Variables para loops
  // Iteramos por todo el arregloS
  for(i=0; i<n; i++){
    // Si arr[i] es igual a nuestro número a buscar 
    if(arr[i]==x){
      // Retornamos la posición del iterador
      return i;
    }
  } 
  // Si no se encuentra n retornamos -1
  return -1; 
}