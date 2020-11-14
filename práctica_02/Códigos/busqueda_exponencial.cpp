/*
  Título: Búsqueda exponencial.
  ---------------------------------------------------------------------
  Descripción: 
  Búsqueda de un valor "x" por medio de búsqueda binaria en un arreglo.
  Valores de entrada:
  * Arreglo de enteros, tamaño y valor "x" a buscar.
  Valores de retorno: Valor buscado
  * Si se encuentra retorna la posición encontrado en middle.
  * En caso contrario se retorna -1.
  ---------------------------------------------------------------------
  Fecha: 10/Noviembre/2020.
  Versión: 1.0
  Autor: Hernandez Espinoza Miguel Angel.
*/
/*Breve explicacion el algoritmo busca el rango para 
el busqueda binaria para despues aplicarlo
Esto se logra comenzando con un subarreglo de tamaño 1, 
comparando el primer valor del indice con el elemento con x, 
luego probar el tamaño 2, luego 4 y así sucesivamente hasta 
que el último elemento de un subarreglo no sea mayor,
para despues aplicar la busqueda binaria */ 
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 
int exponentialSearch(int arr[], int n, int x);

int exponentialSearch(int arr[], int n, int x)
{
    // Se comienza el subarreglo de un elemento y comparar con el valor buscado
    if (arr[0] == x)
        return 0;
 
    // Encuentra el rango para la busqueda binaria 
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;
 
    //  ESTO ES PARTE DEL ALGORITMO DE BUSQUEDA BINARIA
    int left=i/2, right=min(i, n-1); 
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


