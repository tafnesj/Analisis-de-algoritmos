#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "tiempo.h"

struct argumentos {
	int *arr;
	int target; 
	int li; //Limite inferior
	int ls; //Limite superior
};

/*
	El algoritmo de busqueda exponencial requiere dos pasos:
		Encontrar el rango en el que se encuentra el elemento
		Hacer una busqueda binaria bajo este rango
	Por estar razon se requiere la funcion binarySearch.
	Recibe la Struct args que contiene los limites del rango, el numero a buscar y el arreglo
	Devuelve una bandera que indica si se encuentra. 
*/
void *binarySearch(void *args){
	int status = -1;
	struct argumentos *bargs = (struct argumentos*) args;
	int li = bargs -> li; //Empezmos a buscar desde aqui
	int ls = bargs -> ls; //Terminamos la busqueda aca
	//Algoritmo busqueda binaria
	while (li <= ls) { 
        int index = li + (ls - li) / 2; 
        if (bargs->arr[index] == bargs->target){
            status = 0; //Se ha encontrado el numero
            pthread_exit((void*)&status);
        }
        if (bargs->arr[index] < bargs->target)
            li = index + 1; 
        else
            ls = index - 1; 
    } 
    //Si retorna -1 indica que no se ha encontrado
	pthread_exit((void*)&status);
}

void main(int argc, char *argv[]){
	int *numeros = NULL, n = 0, i = 0, target = 0, li = 0, ls = 0, aux = 0;
	struct argumentos *margs = NULL;
	pthread_t id[4];
	int eid[4]; //Status del hilo
	double utime0, stime0, wtime0,utime1, stime1, wtime1;

	n = atoi(argv[1]);
	target = atoi(argv[2]);

	numeros = malloc(sizeof(int)*n);
	margs = malloc(sizeof(struct argumentos));

	if(numeros==NULL)
		exit(2);
	//Se leen los numeros desde la consola o un archivo
	for(i=0;i<n;i++){
		scanf("%i",&numeros[i]);
	}

	margs->arr = numeros;
	margs->target = target;

	//Comenzamos el algoritmo exponencial
	uswtime(&utime0, &stime0, &wtime0);

	if(numeros[0]==target){
		//Aqui salimos del programa de una buena vez
		uswtime(&utime1, &stime1, &wtime1); 
		printf("Encontrado en la posicion 0\n");
		exit(0);
	}

	i=1; //Partimos de la posicion 1
	while((i < n) && (numeros[i] <= target)){
		i = i*2;
	}

	//La i ha alcanzado un valor mayor al buscado o es el mismo, establecemos limites
	li = i/2; //Comenzaremos a buscar desde aqui
	if(i<(n-1))
		ls = i; //Terminamos de buscar aqui
	else
		ls = (n-1); //Terminamos de buscar en la ultima posicion del arreglo

	//Creacion de hilos
	ls = (ls-li)/4;
	margs->li=li;
	margs->ls=ls;
	pthread_create(&id[0],NULL,binarySearch,(void*)margs);
	margs->li=ls;
	margs->ls=ls*2;
	pthread_create(&id[1],NULL,binarySearch,(void*)margs);
	margs->li=ls*2;
	margs->ls=ls*3;
	pthread_create(&id[2],NULL,binarySearch,(void*)margs);
	margs->li=ls*3;
	margs->ls=ls*4;
	pthread_create(&id[3],NULL,binarySearch,(void*)margs);

	//ciclo encargado de unir los hilos,toma el valor retornado. 
	for(i=0;i<4;i++){
		pthread_join(id[i],(void*)&eid[i]);
		if(eid[i]==0){
			uswtime(&utime1, &stime1, &wtime1); 
			printf("Encontrado\n");
			exit(0);	
		}
	}
	uswtime(&utime1, &stime1, &wtime1); 
	printf("No encontrado\n");
	
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

	return;
}
