#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



struct datos{
	int *arreglo;
	int tam;
	int elemento;

};

void *Lineal(void *args){
	struct datos *lineal = (struct datos*) args;
	int j;
	int bandera = 1;
	
	for(j=0; j<(lineal->tam); j++){
    // Si arr[i] es igual a nuestro n�mero a buscar 
    if(lineal->arreglo[j]==(lineal->elemento)){
      	bandera=0;
     	pthread_exit((void*)&bandera);
		printf("%i",lineal->elemento);
    	}
  	}
	pthread_exit((void*)&bandera);
}



void main(int argc, char *argv[]){
	printf("%d",argc);
	int *numeros = NULL, i = 0, n = 0, buscado = 0; 
	int eid[5];
	struct datos *d = NULL;
	pthread_t hilos[5];

	d = malloc(sizeof(struct datos));
	
	n = atoi(argv[1]);
	buscado = atoi(argv[2]);
	numeros = malloc(sizeof(int)*n);
	
	if(numeros==NULL)
		exit(2);
	printf("hola");
	
	//Se leen los numeros desde la consola o un archivo
	for(i=3;i<n;i++){
		numeros[i-3]=atoi(argv[i-3]);
		printf("%i",numeros[i-3]);
		printf("hola");
	}
	
	d->arreglo = numeros;
	d->tam = n;
	d->elemento = buscado;

	for(i=0;i<5;i++){
		
		pthread_create(&hilos[i],NULL,Lineal,(void*)d);
	}
	
	for(i=0;i<5;i++){
		pthread_join(hilos[i],(void*)&eid[i]);
	}
	return;
}
