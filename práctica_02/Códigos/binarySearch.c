/*
  Título: Búsqueda binaria.
  ---------------------------------------------------------------------
  Descripción: 
  Búsqueda de un valor "x" por medio de búsqueda binaria en un arreglo.
  Valores de entrada:
  * Arreglo de enteros, tamaño y valor "x" a buscar.
  Valores de retorno:S
  * Si se encuentra retorna la posición encontrado en middle.
  * En caso contrario se retorna -1.
  ---------------------------------------------------------------------
  Fecha: 10/Noviembre/2020.
  Versión: 1.0
  Autor: Tafnes Jiménez.
*/

#include <stdio.h>

// Recibe un arreglo, su tamaño y valor "x" a buscar
int binarySearch(int arr[], int n, int x){
  // Variables para índices para movernos en el arreglo
  int left=0, right=n-1; 
  // Dividimos y buscamos hasta que lleguemos ambos índices sean iguales
  while(left<=right){
        // Variable para dividir en mitades
        int middle=(left+right)>>1; 
  
        // Revisamos si "x" se encuentra en la posición middle actual
        if (arr[middle]==x){
          // De ser así, regresamos esa posición
          return middle; 
        }   
        // Si "x" es más grande que el valor de middle 
        if(arr[middle]<x){
          /* Ignoramos los valores de la izquierda igualando
             al valor de left con middle+1 */
          left=middle+1; 
        }else{ // Si n es más pequeño que el valor de middle 
          /* Ignoramos los valores de la derecha igualando
             al valor de right con middle-1 */
          right=middle-1; 
        }
    } 
  // Si no se encuentra n retornamos -1
  return -1; 
}
