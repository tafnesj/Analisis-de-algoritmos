/*
  Título: Medicion de tiempo de Algoritmo de Busqueda Binaria con hilos
	------------------------------------------------------------------------------------
  Descripción: Implementación de Busqueda de Binaria con hilos.
	Al estar los numeros ordenados de forma ascendente se identifica el punto
	medio del arreglo y se compara el numero a buscar; si el numero es mayor 
	entonces se busca en el subarreglo derecho, sino en el izquierdo. El punto 
	medio de referencia se recorre bajo el mismo criterio hasta que se encuentra o no.
	------------------------------------------------------------------------------------
  Fecha: 22/Noviembre/2020.
  Versión: Versión 1.0
  Autor: Guerrero Espinosa Ximena Mariana y Tafnes Jiménez.
*/

//LIBRERIAS INCLUIDAS
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// Struct
#include "datos.h" 

/*
La funcion binaryAuxiliar se creó para indicar a cada uno de los hilos en que intervalo del arreglo 
trabajara, resaltemos que se recibira el identificador del hilo; considerando que el arreglo esta
ordenado ascendentemente podemos definir el left y fin de cada intervalo. Asimismo se indicara 
que hilo fue el que lo encontró. 
*/
void *binaryAuxiliar(void *args)
{
	datos *binary = (datos *)args;

	int medio; //punto de referencia
	int left = binary->left;
	int right = binary->right;

	//algoritmo de búsqueda
	while (left <= right && *binary->found == -1)
	{
		medio = (left + right) / 2;
		if (binary->arreglo[medio] == binary->elemento)
		{
			// Si lo encontró cambia a 0
			*binary->found = 0;
			pthread_exit(NULL);
		}
		else
		{
			if (binary->elemento < binary->arreglo[medio])
			{
				right = medio - 1;
			}
			else
			{
				left = medio + 1;
			}
		}
	}
	pthread_exit(NULL);
}

/* La funcion busquedaBinaria recibe el arreglo donde se buscaran los numeros, 
   el inicio,el n y el numero que se va a buscar */
int binarySearchHilos(int arr[], int n, int x, int parts)
{
	pthread_t ids[parts]; // Número de hilos
	int found = -1;				// Encontró el hilo o no (0 -> false)
	// Variable auxiliar para cálculo de los rangos de los hilos
	int tamT = n / parts;
	// Variable auxiliar para divisibles no exactos
	int mod = n % parts;

	for (int i = 0; i < parts; i++)
	{
		// Creación de memoria para struct
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
		pthread_create(&ids[i], NULL, binaryAuxiliar, (void *)d);
	}

	for (int i = 0; i < parts; i++)
	{
		// Fin/terminar hilos
		pthread_join(ids[i], NULL);
	}

	return found;
}