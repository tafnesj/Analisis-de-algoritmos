/*
  Título: Función main.
  Descripción: Manda a llamar a las diversas funciones y obtiene
	             la medición de los tiempos de ejecución (llamada a las funciones).
  Fecha: 01/Noviembre/2020.
  Versión: Versión 1.0
  Autor: Tafnes Lorena Jiménez Aguilar.
*/

// Librerías
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
// Algoritmos
#include "bubbleSort.c"
#include "bubbleSortOp.c"
#include "insertionSort.c"
#include "selectionSort.c"
#include "shellSort.c"
#include "treeSort.c"

int main (int argc, char* argv[]){

	/*  Variables para time */
	
	// Variables para medición de tiempos
	double utime0, stime0, wtime0,utime1, stime1, wtime1; 
	int n; 	// n determina el tamaño del algorito dado por argumento al ejecutar
	int i; // Variables para loops

	// Variables
	int algoritmo; // Variable para elegir el algoritmo.

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
		case 1: // Bubble Sort, llamado a función
				// recibe un arreglo y un valor n
				bubbleSort(arr, n);
			break;
		case 2: // Bubble Sort Optimizado, llamado a función
				// recibe un arreglo y un valor n
				bubbleSortOp(arr, n);
			break;
		case 3: // Insertion Sort, llamado a función
				// recibe un arreglo y un valor n
				insertionSort(arr, n);
			break;
		case 4: // Selection Sort, llamado a función
				// recibe un arreglo y un valor n
				selectionSort(arr, n);
			break;
		case 5: // Shell Sort, llamado a función
			// recibe un arreglo y un valor n
			shellSort(arr, n);
			break;
		case 6: // Tree Sort, llamado a función
			// recibe un arreglo y un valor n
			treeSort(arr, n);
			break;
		default:
			// Devuelve mensaje de error si no existe la opción
			printf("\n Opci%cn no v%clida", 162, 160); 
			break;
	}

	uswtime(&utime1, &stime1, &wtime1);

	// Verificar que las soluciones están ordenadas
	for(i=0; i<n-1; i++){
		if(arr[i]>arr[i+1]){
			printf("No ordenado.\n");
			exit(1);
		}
	}

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