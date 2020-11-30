/*
  Título: Función main.
	-----------------------------------------------------------------------------
  Descripción: 
	* Manda a llamar a las diversas funciones de los algoritmos de búsqueda.
	* Obtiene la medición de los tiempos de ejecución (llamada a las funciones).
	-----------------------------------------------------------------------------
	Compilación: gcc main.c tiempo.c -lpthread -O2
	Ejecución: ./a.out [n] [algoritmo] [x]
  Fecha: 23/Noviembre/2020.
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
#include "binarySearchTree.c"
#include "BusquedaFibonacci.c"
#include "busquedaExponencial.c"

// Algoritmos con hilos
#include "linealSearchHilos.c"
#include "BusquedaFibonacciHilos.c"
#include "BusquedaBinariaHilos.c"
#include "BusquedaExponencialHilos.c"

int main(int argc, char *argv[])
{

	/*  Variables para time */

	// Variables para medición de tiempos
	double utime0, stime0, wtime0, utime1, stime1, wtime1;
	int n; // n determina el tamaño del algorito dado por argumento al ejecutar
	int i; // Variables para loops

	// Variables
	int algoritmo; // Variable para elegir el algoritmo.
	int x;				 // India el valor a buscar.
	int found;		 // Indica si encontró el valor.

	if (argc != 4)
	{
		printf("\nUso: %s [n] [algoritmo] [x] \n", argv[0]);
		exit(1);
	}
	// Tomar el segundo argumento como tamaño del algoritmo
	else
	{
		n = atoi(argv[1]);
		algoritmo = atoi(argv[2]);
		x = atoi(argv[3]);
	}

	// Lectura
	int *arr = malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	/*--------------------------------------------------------------------
	 Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	---------------------------------------------------------------------*/

	// Case para seleccionar el algoritmo a ejecutar
	switch (algoritmo)
	{
	/* ---------------------------------- 
						Algoritmos sin hilos 
		----------------------------------*/
	case 1: // lineal Search, llamado a función
		// recibe un arreglo, un valor n y un valor x a buscar
		uswtime(&utime0, &stime0, &wtime0);
		found = linealSearch(arr, n, x);
		break;
	case 2:; // Binary Tree Search, llamado a función
		// recibe un arreglo, un valor n y un valor x a buscar
		nodo *aux = createTree(arr, n);
		uswtime(&utime0, &stime0, &wtime0);
		found = treeSearch(x, aux);
		break;
	case 3: // Binary Search, llamado a función
		// recibe un arreglo, un valor n y un valor x a buscar
		uswtime(&utime0, &stime0, &wtime0);
		found = binarySearch(arr, n, x);
		break;
	case 4: // Exponential Search, llamado a función
		// recibe un arreglo, un valor n y un valor x a buscar
		uswtime(&utime0, &stime0, &wtime0);
		found = exponentialSearch(arr, n, x);
		break;
	case 5: // Fibonacci Search, llamado a función
		// recibe un arreglo, un valor n y un valor x a buscar
		uswtime(&utime0, &stime0, &wtime0);
		found = fibMonaccianSearch(arr, n, x);
		break;
	/* ---------------------------------- 
						Algoritmos con hilos 
		----------------------------------*/
	case 6: // lineal Search II, llamado a función
		// recibe un arreglo, un valor n y un valor x a buscar
		uswtime(&utime0, &stime0, &wtime0);
		found = linealSearchHilos(arr, n, x, 5);
		break;
	case 7: // Binary Search II, llamado a función
		// recibe un arreglo, un valor n y un valor x a buscar
		uswtime(&utime0, &stime0, &wtime0);
		found = binarySearchHilos(arr, n, x, 5);
		break;
	case 8: // Exponential Search II, llamado a función
		// recibe un arreglo, un valor n y un valor x a buscar
		uswtime(&utime0, &stime0, &wtime0);
		found = exponentialSearchHilos(arr, n, x, 5);
		break;
	case 9: // Fibonacci Search II, llamado a función
		// recibe un arreglo, un valor n y un valor x a buscar
		uswtime(&utime0, &stime0, &wtime0);
		found = fibonacciSearchHilos(arr, n, x, 5);
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
	if (found >= 0)
	{
		printf("1 ");
	}
	else
	{
		printf("0 ");
	}

	/*------------------------------------------------------------
	 Impresión del cálculo del tiempo de ejecución del programa
	------------------------------------------------------------*/
	// Tiempo real
	printf("%.10f ", wtime1 - wtime0);
	// Tiempo de CPU
	printf("%.10f ", utime1 - utime0);
	//Tiempo E/S
	printf(" %.10f", stime1 - stime0);
	// CPU/Wall %
	printf(" %.10f \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));

	// Terminar programa normalmente
	exit(0);
}
