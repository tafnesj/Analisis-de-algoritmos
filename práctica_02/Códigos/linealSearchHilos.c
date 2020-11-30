/*
  Título: Búsqueda lineal con hilos.
  ---------------------------------------------------------------------
  Descripción: 
  Búsqueda de un valor "x" por medio de búsqueda lineal en un arreglo.
  Valores de entrada:
  * Arreglo de enteros, tamaño y valor "x" a buscar.
  Valores de retorno:
  * Si se encuentra retorna la posición. 
  * En caso contrario se retorna -1.
  ---------------------------------------------------------------------
  Fecha: 22/Noviembre/2020.
  Versión: 1.0
  Autores: Hernandez Espinoza Miguel Angel y Tafnes Jiménez.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// Struct
#include "datos.h"

void *linealAuxiliar(void *args)
{
	datos *lineal = (datos *)args;

	// Iterará hasta que un hilo no lo haya encontrado
	for (int j = lineal->left; j <= lineal->right && *lineal->found == -1; j++)
	{
		// Si arreglo[i] es igual a nuestro número a buscar
		if (lineal->arreglo[j] == (lineal->elemento))
		{
			// Si lo encontró cambia a 0
			*lineal->found = 0;
			pthread_exit(NULL);
			// printf("%i",lineal->elemento);
		}
	}
	pthread_exit(NULL);
}

// Llamar a la función para el main
int linealSearchHilos(int arr[], int n, int x, int parts)
{
	pthread_t ids[parts]; // Número de hilos
	int found = -1;				// Encontró el hilo o no (0 -> false)
	// Variable auxiliar para cálculo de los rangos de los hilos
	int tamT = n / parts;
	// Variable auxiliar para divisibles no exactos
	int mod = n % parts;

	for (int i = 0; i < parts; i++)
	{
		// Creación de memoria para
		datos *d = malloc(sizeof(datos));
		d->arreglo = arr;
		d->elemento = x;
		// Variable inicio del rango
		d->left = i * tamT;
		// Variable fin del rango
		d->right = (d->left + tamT) - 1;
		// Condicional para ajustar el rango
		if (i == parts - 1)
		{
			// Asignación del valor de rango
			d->right += mod;
		}
		// Comunicación entre hilos
		d->found = &found;

		// Lanza los hilos
		pthread_create(&ids[i], NULL, linealAuxiliar, (void *)d);
	}

	for (int i = 0; i < parts; i++)
	{
		// Fin/terminar hilos
		pthread_join(ids[i], NULL);
	}

	return found;
}