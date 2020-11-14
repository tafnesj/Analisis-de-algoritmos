/*
  T�tulo: B�squeda exponencial.
  ---------------------------------------------------------------------
  Descripci�n: 
  B�squeda de un valor "x" por medio de b�squeda binaria en un arreglo.
  Valores de entrada:
  * Arreglo de enteros, tama�o y valor "x" a buscar.
  Valores de retorno: Valor buscado
  * Si se encuentra retorna la posici�n encontrado en middle.
  * En caso contrario se retorna -1.
  ---------------------------------------------------------------------
  Fecha: 10/Noviembre/2020.
  Versi�n: 1.0
  Autor: Hernandez Espinoza Miguel Angel.
*/
/*Breve explicacion el algoritmo busca el rango para 
el busqueda binaria para despues aplicarlo
Esto se logra comenzando con un subarreglo de tama�o 1, 
comparando el primer valor del indice con el elemento con x, 
luego probar el tama�o 2, luego 4 y as� sucesivamente hasta 
que el �ltimo elemento de un subarreglo no sea mayor,
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
  // Dividimos y buscamos hasta que lleguemos ambos �ndices sean iguales
  while(left<=right){
        // Variable para dividir en mitades
        int middle=(left+right)>>1; 
  
        // Revisamos si "x" se encuentra en la posici�n middle actual
        if (arr[middle]==x){
          // De ser as�, regresamos esa posici�n
          return middle; 
        }   
        // Si "x" es m�s grande que el valor de middle 
        if(arr[middle]<x){
          /* Ignoramos los valores de la izquierda igualando
             al valor de left con middle+1 */
          left=middle+1; 
        }else{ // Si n es m�s peque�o que el valor de middle 
          /* Ignoramos los valores de la derecha igualando
             al valor de right con middle-1 */
          right=middle-1; 
        }
    } 
  	// Si no se encuentra n retornamos -1
  	return -1; 
}


