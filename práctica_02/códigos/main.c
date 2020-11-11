/*
  Título: Función main.
	-----------------------------------------------------------------------------
  Descripción: 
	* Manda a llamar a las diversas funciones de los algoritmos de búsqueda.
	* Obtiene la medición de los tiempos de ejecución (llamada a las funciones).
	-----------------------------------------------------------------------------
  Fecha: 10/Noviembre/2020.
  Versión: Versión 1.0
  Autor: Tafnes Jiménez.
*/

// Librerías
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
// Algoritmos sin hilos
#include "linealSearch.c"
#include "binarySearch.c"
#include "BusquedaFibonacci.c"
// Algoritmos con hilos

int main (int argc, char* argv[]){

	/*  Variables para time */
	
	// Variables para medición de tiempos
	double utime0, stime0, wtime0,utime1, stime1, wtime1; 
	int n; 	// n determina el tamaño del algorito dado por argumento al ejecutar
	int i; // Variables para loops

	// Variables
	int algoritmo; // Variable para elegir el algoritmo.
	int x; // India el valor a buscar.

	if(argc!=3){
		printf("\nArgumento no v%clido",160);
		exit(1);
	} 
	// Tomar el segundo argumento como tamaño del algoritmo
	else{
		n=atoi(argv[1]);
		algoritmo=atoi(argv[2]);
	}

	// Lectura
	int *arr=malloc(sizeof(int)*n);
  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
	
	/*--------------------------------------------------------------------
	 Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	---------------------------------------------------------------------*/
	uswtime(&utime0, &stime0, &wtime0);

	// Case para seleccionar el algoritmo a ejecutar
	switch(algoritmo){
		/* ---------------------------------- 
						Algoritmos sin hilos 
		----------------------------------*/
		case 1: // lineal Search, llamado a función
				// recibe un arreglo, un valor n y un valor x a buscar
				linealSearch(arr, n, x);
			break;
		case 2: // Binary Tree Search, llamado a función
				// recibe un arreglo, un valor n y un valor x a buscar
				(arr, n, x);
			break;
		case 3: // Binary Search, llamado a función
				// recibe un arreglo, un valor n y un valor x a buscar
				binarySearch(arr, n, x);
			break;
		case 4: // Exponential Search, llamado a función
				// recibe un arreglo, un valor n y un valor x a buscar
				(arr, n, x);
			break;
		case 5: // Fibonacci Search, llamado a función
			// recibe un arreglo, un valor n y un valor x a buscar
			fibMonaccianSearch(arr, n, x);
			break;
		/* ---------------------------------- 
						Algoritmos con hilos 
		----------------------------------*/
		case 6: // lineal Search II, llamado a función
				// recibe un arreglo, un valor n y un valor x a buscar
				(arr, n, x);
			break;
		case 7: // Binary Tree Search II, llamado a función
				// recibe un arreglo, un valor n y un valor x a buscar
				(arr, n, x);
			break;
		case 8: // Binary Search II, llamado a función
				// recibe un arreglo, un valor n y un valor x a buscar
				(arr, n, x);
			break;
		case 9: // Exponential Search II, llamado a función
				// recibe un arreglo, un valor n y un valor x a buscar
				(arr, n, x);
			break;
		case 10: // Fibonacci Search II, llamado a función
			// recibe un arreglo, un valor n y un valor x a buscar
			(arr, n, x);
			break;
		default:
			// Devuelve mensaje de error si no existe la opción
			printf("\n Opci%cn no v%clida", 162, 160); 
			break;
	}

	uswtime(&utime1, &stime1, &wtime1);

	/*------------------------------------------------------------
	 Impresión del cálculo del tiempo de ejecución del programa
	------------------------------------------------------------*/
	// Tiempo real
	printf("%.10f ",wtime1-wtime0);
	// Tiempo de CPU
	printf("%.10f ",utime1-utime0);
	//Tiempo E/S
	printf(" %.10f",stime1-stime0);
	// CPU/Wall % 
	printf(" %.10f \n",100.0*(utime1-utime0+stime1-stime0)/(wtime1-wtime0));
	
	// Terminar programa normalmente
	exit (0);	
}