/*
  Título: Búsqueda en un árbol binario.
  ---------------------------------------------------------------------
  Descripción: 
  Búsqueda de un valor "x" por medio de búsqueda binaria en un arreglo.
  Valores de entrada:
  * El árbol ABB y valor "x" a buscar.
  Valores de retorno:
  * Si se encuentra retorna un "true" y de ahí tenemos el valor de x.
  * En caso contrario se retorna "false".
  ---------------------------------------------------------------------
  Fecha: 22/Noviembre/2020.
  Versión: 1.0
  Autor: Tafnes Jiménez.
*/

// Biblioteca
#include <stdio.h>
#include <stdlib.h>

// Declaración de struct
typedef struct nodo
{
  // Nodo derecho e izquierdo
  struct nodo *izq, *der;
  // Variable para valor
  int num;
} nodo;

// Función para crear nodos: recibe valor
nodo *crear_nodo(int numb)
{
  // Almacenamiento dinámico de memoria
  nodo *new_nodo = malloc(sizeof(nodo));
  // Asignación de valor
  new_nodo->num = numb;
  new_nodo->izq = NULL; // Hijo izquierdo
  new_nodo->der = NULL; // Hijo derecho
  return new_nodo;
}

// Función para insertar en el árbol
void insertar(int num_nodo, nodo **raiz)
{
  while (*raiz != NULL)
  {
    if (num_nodo < (*raiz)->num)
    {
      raiz = &(*raiz)->izq; // Hijos menores
    }
    else
    {
      raiz = &(*raiz)->der; // Hijos mayores
    }
  }
  // Insertar valor en el nodo
  *raiz = crear_nodo(num_nodo);
}

// Implementación de la búsqueda
int treeSearch(int x, nodo *raiz)
{ 
  // Recibe el valor x y el árbol
  nodo *aux = raiz; //
  
  while (aux != NULL)
  {
    // Búsqueda en la raíz del árbol
    if (aux->num == x) // Cuando el valor de x se encuentra en la raíz
    {
      return 0;
    }else if (aux->num > x) // Cuando el valor de x < raiz
    {
      aux = aux->izq;
    }else if (aux->num < x) // Cuando el valor de x > raiz
    {
      aux = aux->der;
    }
  }
  return -1;
}

// Aplicación del algortimo, recibe un arreglo y un valor n
nodo *createTree(int *arr, int n)
{
  int i = 0;         // Variable para loop
  nodo *tree = NULL; // Asignación a null
  // Iteración por el array de n valores
  for (i = 0; i < n; i++)
  {
    // Guarda en el árbol los valores, llamado a función
    insertar(arr[i], &tree);
  }
  return tree;
}

// Función para imprimir el árbol
void imprimir(nodo *raiz){
  if(raiz!=NULL){
    imprimir(raiz->izq);
    printf("%d \n",raiz->num);
    imprimir(raiz->der);  
  }
}