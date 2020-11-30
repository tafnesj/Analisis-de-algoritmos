/*
  Título: Medicion de tiempo de Algoritmo de Búsqueda Exponencial con hilos
	----------------------------------------------------------------------------
  Descripción: Implementación de Busqueda de Exponencial con hilos.
	----------------------------------------------------------------------------
  Fecha: 22/Noviembre/2020.
  Versión: Versión 1.0
  Autor: Guerrero Espinosa Ximena Mariana y Tafnes Jiménez.
*/

//LIBRERIAS INCLUIDAS
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
// Struct
#include "datos.h"

/*La funcion exponencialAuxiliar se creó para indicar a cada uno de los hilos en que intervalo del arreglo 
trabajara, resaltemos que se recibira el identificador del hilo; considerando que el arreglo esta
ordenado ascendentemente podemos definir el left y fin de cada intervalo. Asimismo se indicara 
que hilo fue el que lo encontró. 
*/
void *exponentialAuxiliar(void *args)
{
	datos *exponencial = (datos *)args;
	int left = exponencial->left;
	int right = exponencial->right;

	int i = left + 1;

	// Si x está presente en la primera posición
	if (exponencial->arreglo[left] == exponencial->elemento)
	{
		// Si lo encontró cambia a 0
		*exponencial->found = 0;
		pthread_exit(NULL);
	}

	while (i <= right && exponencial->arreglo[i] <= exponencial->elemento)
		i = i * 2;

	if (i <= right)
		right = i;

	left = i / 2;

	// Dividimos y buscamos hasta que lleguemos ambos índices sean iguales
	while (left <= right && *exponencial->found == -1)
	{
		// Variable para dividir en mitades
		int middle = (left + right) >> 1;

		// Revisamos si "x" se encuentra en la posición middle actual
		if (exponencial->arreglo[middle] == exponencial->elemento)
		{
			*exponencial->found = 0;
			pthread_exit(NULL);
		}
		// Si "x" es más grande que el valor de middle
		if (exponencial->arreglo[middle] < exponencial->elemento)
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
	pthread_exit(NULL);
}

// Llamar a la función para el main
int exponentialSearchHilos(int arr[], int n, int x, int parts)
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
		pthread_create(&ids[i], NULL, exponentialAuxiliar, (void *)d);
	}

	for (int i = 0; i < parts; i++)
	{
		// Fin/terminar hilos
		pthread_join(ids[i], NULL);
	}

	return found;
}