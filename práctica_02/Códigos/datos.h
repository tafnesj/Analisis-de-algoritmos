/*
  Título: Struct de datos.
  ----------------------------------------------------
  Descripción: 
  Struct para la simulación del paso de argumentos
	por medio de este.
  ----------------------------------------------------
  Fecha: 30/Noviembre/2020.
  Versión: 1.0
  Autor: Tafnes Jiménez.
*/

#ifndef datos_
#define datos_

// Struct
typedef struct datos
{
	int *arreglo;
	int left;
	int right;
	int elemento;
	int *found;
}datos;

#endif