/*
  Título: Ordenamiento por árbol de búsqueda binaria.
  Descripción: Implementación de función de Tree sort.
  Fecha: 01/Noviembre/2020.
  Versión: Versión 1.0
  Autor: Tafnes Lorena Jiménez Aguilar.
*/

#include <stdio.h>

// Declaración de struct
typedef struct nodo {
  // Nodo derecho e izquierdo
  struct nodo* izq, *der;
  // Variable para valor
  int num;
}nodo;

// Función para crear nodos: recibe valor
nodo* crear_nodo(int numb){
  // Almacenamiento dinámico de memoria
  nodo* new_nodo=malloc(sizeof(nodo));
  // Asignación de valor 
  new_nodo->num=numb;
  new_nodo->izq=NULL; // Hijo izquierdo
  new_nodo->der=NULL; // Hijo derecho
  return new_nodo;
}

// Función para insertar en el árbol
void insertar(int num_nodo, nodo**raiz){
  while(*raiz!=NULL){
    if(num_nodo<(*raiz)->num){
      raiz=&(*raiz)->izq; // Hijos menores
    }else{
      raiz=&(*raiz)->der; // Hijos mayores
    }
  }
  // Insertar valor en el nodo
  *raiz=crear_nodo(num_nodo);
}

int x=0; // Variable para iterar

// Función para In Order
void inOrder(nodo*raiz, int*arr){
  // Si no hay hijos termina la función
  if(raiz==NULL){
    return;
  }else{
    // Llamadas recursivas a la función
    inOrder(raiz->izq, arr);
    // Asignación hijo izquierdo
    arr[x]=raiz->num;
    x++;
    // Asignación hijo izquierdo
    inOrder(raiz->der, arr);
  }
}

// Aplicación del algortimo, recibe un arreglo y un valor n
void treeSort(int*arr, int n){
  int i=0; // Variable para loop
  nodo*tree=NULL; // Asignación a null
  // Iteración por el array de n valores
  for(i=0; i<n; i++){
    // Guarda en el árbol los valores, llamado a función
    insertar(arr[i], &tree);
  }
  // Recorre el árbol
  inOrder(tree, arr);
}