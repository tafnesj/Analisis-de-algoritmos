/*
  T�tulo: B�squeda binaria.
  ---------------------------------------------------------------------
  Descripci�n: 
  B�squeda de un valor "x" por medio de b�squeda binaria en un arreglo.
  Valores de entrada:
  * Arreglo de enteros, tama�o y valor "x" a buscar.
  Valores de retorno:S
  * Si se encuentra retorna la posici�n encontrado en middle.
  * En caso contrario se retorna -1.
  ---------------------------------------------------------------------
  Fecha: 10/Noviembre/2020.
  Versi�n: 1.0
  Autor: Hernandez Espinoza Miguel Angel.
*/

// C++ program to find an element x in a
// sorted array using Exponential search.


#include<stdio.h>
#include<stdlib.h>
 
int exponentialSearch(int arr[], int n, int x);
 
// Returns position of first occurrence of
// x in array
int exponentialSearch(int arr[], int n, int x)
{
    // If x is present at firt location itself
    if (arr[0] == x)
        return 0;
 
    // Find range for binary search by
    // repeated doubling
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;
    int right=0;
	if(i < (n-1)) right=i;
	else right=(n-1);
	int left=i/2;
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
          right=middle-1;}
 
	}
}

