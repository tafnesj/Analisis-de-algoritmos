/*
  Título: Busqueda de Fibonacci
  Descripción: Implementación de Busqueda de Fibonacci.
  Fecha: 10/Noviembre/2020.
  Versión: Versión 1.0
  Autor: Guerrero Espinosa Ximena Mariana
*/

#include <stdio.h> 

// Función para encontrar el mínimo de dos elementos
int min(int x, int y) { 
	return (x<=y)? x : y; 
	}

/*  Recibe un arreglo, el numero a buscar 
	y el tamaño del arreglo*/
int fibMonaccianSearch(int arr[], int x, int n){

    /* Inicializa los números de fibonacci */
    int fibMMm2 = 0; // (m-2) numero Fibonacci 
    int fibMMm1 = 1; // (m-1) numero Fibonacci  
    int fibM = fibMMm2 + fibMMm1; // m numero Fibonacci 

    /* fibM va a almacenar el menor número de Fibonacci 
    mayor o igual a n */
    while (fibM < n) 
    { 
        fibMMm2 = fibMMm1; 
        fibMMm1 = fibM; 
        fibM = fibMMm2 + fibMMm1; 
    } 
    //Se marca el rango de eliminación 
    int offset = -1; 
    /* mientras haya elementos para ser inspeccionados. 
    se compara arr[fibMm2] con x. Cuando fibM se convierte en 1, 
    fibMm2 se convierte en 0 */
    while (fibM > 1) 
    { 
        //  Comprueba si fibMm2 es una ubicación válida
        int i = min(offset+fibMMm2, n-1); 

        /* Si x es mayor que el valor en el índice fibMm2, 
        se corta el subarreglo a i */
        if (arr[i] < x) 
        { 
            fibM = fibMMm1; 
            fibMMm1 = fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
            offset = i; 
        } 

        /* Si x es mayor que el valor en el índice fibMm2, 
        se corta el subarreglo después de i+1 */
        else if (arr[i] > x) 
        { 
            fibM = fibMMm2; 
            fibMMm1 = fibMMm1 - fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
        } 

        /* Si se encuentra se regresa el índice */
        else return i; 
    } 

    /* compara el ultimo elemento con x*/
    if(fibMMm1 && arr[offset+1]==x)return offset+1; 

    /*Si el elemento se encuentra regresa -1*/
    return -1; 
}  
