/*
  Título: Búsqueda binaria.
  ---------------------------------------------------------------------
  Descripción: 
  Búsqueda de un valor "x" por medio de búsqueda binaria en un arreglo.
  Valores de entrada:
  * Arreglo de enteros, tamaño y valor "x" a buscar.
  Valores de retorno:
  * Si se encuentra retorna la posición encontrado en middle.
  * En caso contrario se retorna -1.
  ---------------------------------------------------------------------
  Fecha: 10/Noviembre/2020.
  Versión: 1.0
  Autor: Hernandez Espinoza Miguel Angel.
*/

#include <stdio.h>
#include <stdlib.h>

// Retorna la posición de la primera ocurrencia de x
int exponentialSearch(int arr[], int n, int x)
{
  // Si x está presente en la primera posición
  if (arr[0] == x)
    return 0;

  // Encuentra un rango para la búsqueda binaria
  int i = 1;
  while (i < n && arr[i] <= x)
    i = i * 2;
  int right = 0;
  if (i < (n - 1))
    right = i;
  else
    right = (n - 1);
  int left = i / 2;
  // Dividimos y buscamos hasta que lleguemos ambos índices sean iguales
  while (left <= right)
  {
    // Variable para dividir en mitades
    int middle = (left + right) >> 1;

    // Revisamos si "x" se encuentra en la posición middle actual
    if (arr[middle] == x)
    {
      // De ser así, regresamos esa posición
      return middle;
    }
    // Si "x" es más grande que el valor de middle
    if (arr[middle] < x)
    {
      /* Ignoramos los valores de la izquierda igualando
             al valor de left con middle+1 */
      left = middle + 1;
    }
    else
    { // Si n es más pequeño que el valor de middle
      /* Ignoramos los valores de la derecha igualando
             al valor de right con middle-1 */
      right = middle - 1;
    }
  }
  return -1;
}
