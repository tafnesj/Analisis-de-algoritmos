/*
  Título: Medicion de tiempo de Algoritmo de Busqueda Binaria con hilos
  Descripción: Implementación de Busqueda de Binaria con hilos.
  Fecha: 22/Noviembre/2020.
  Versión: Versión 1.0
  Autor: Guerrero Espinosa Ximena Mariana
  Compilacion: "gcc BusquedaBinariaHilo.c tiempo.c -o bbh -lpthread"
  Ejecucion: "./bbh [tamaño del problema] [numero a buscar]"
*/

//LIBRERIAS INCLUIDAS
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"


//VARIABLES GLOBALES
int NumThreads; //Numero de threads
int N,j;
int *A;	//Arreglo dinamico donde se guardaran los n numeros del archivo
int B;		//Numero a buscar

/*
La funcion procesar se creo para indicar a cada uno de los hilos en que intervalo del arreglo 
trabajara, resaltemos que se recibira el identificador del hilo; considerando que el arreglo esta
ordenado ascendentemente podemos definir el inicio y fin de cada intervalo. Asimismo se indicara 
que hilo fue el que lo encontrÃ³. 
*/
void* procesar(void* id)
{	
	int n_thread=(int)id;//identificador del hilo
	int inicio,fin;//inicio y fin del intervalo
	
	//definicion de los intervalos
	inicio=(n_thread*N)/NumThreads;
	if(n_thread==NumThreads-1)	
		fin=N;
	else
		fin=((n_thread+1)*N)/NumThreads-1;

	printf("\nThread %d\tInicio %d\tTermino %d",n_thread,inicio,fin);
	
	if(busquedaBinaria(A,inicio,fin,B)!=-1){
		printf("-----El numero %d se encontro en este intervalo", B);
	}
	
	if(n_thread!=0){
		pthread_exit(0); //Termina el hilo en ejecucion.
	}
}

//DECLARACION DE FUNCIONES
//La funcion busquedaBinaria recibe el arreglo donde se buscaran los numeros, el inicio,el final y el numero que se va a buscar
int busquedaBinaria(int A[], int inicio, int final, int num);


//PROGRAMA PRINCIPAL 

int main (int argc, char *argv[])
{	
	int i=0; //Variables para ciclo for
	pthread_t *thread;
	NumThreads=4;//El numero de threads sera constante;
	thread = malloc(NumThreads*sizeof(pthread_t));
	
	if (argc<1) {
		printf("\nIndique el tamaño de N - \nEjemplo: [user@equipo]$ %s %s 1000\n",argv[0],argv[1]);
		exit(-1);
	}
	if(argc<2){
	printf("\nIndique el numero a buscar  - \nEjemplo: [user@equipo]$ %s %s 1000\n",argv[0],argv[1]);
		exit(-1);
	}
	N=atoi(argv[1]);
	B=atoi(argv[2]);

	A=(int*)malloc(sizeof(int)*N); //Creacion de memoria para el arreglo
	//ciclo para llenar el arreglo con el tamaño del problema 
	for(i=0; i<N; i++){
		scanf("%d", &A[i]);
	}
		//Inicializan las variables para la medicion de tiempo
		double utime0=0, stime0=0, wtime0=0, utime1=0, stime1=0, wtime1=0;

		uswtime(&utime0, &stime0, &wtime0);

		printf("----------BUSQUEDA NUMERO: %d ----------\n", B);
		//Con el ciclo se crean los hilos mediant el metodo procesar
		for (i=1; i<NumThreads; i++) 
		{	 
			if (pthread_create (&thread[i], NULL, procesar,(void*)i) != 0 ) 
			{
				//En caso de no ser posible la creacion se muestra error
				perror("El thread no pudo crearse");
				exit(-1);
			}
		}
		procesar(0);
		
		//Espera a que terminen los threads 
		for (i=1; i<NumThreads; i++){
				pthread_join(thread[i], NULL);
			} 	

		uswtime(&utime1, &stime1, &wtime1);
		//Calculo del tiempo de ejecuciÃ³n del programa
		printf("\n");
		printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
		printf("user (Tiempo de procesamiento en CPU's) %.10f s\n",  utime1 - utime0);
		printf("%d threads (Tiempo de procesamiento aproximado por cada thread en CPU) %.10f s\n", NumThreads,(utime1 - utime0)/NumThreads);	
		printf("sys (Tiempo en acciÃ³nes de E/S)  %.3f s\n",  stime1 - stime0);
		printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
		printf("\n");
	
	//Terminar programa normalmente	*/
	exit (0);	
}
/*Funcion busqueda binaria
Al estar los numeros ordenados de forma ascendente se identifica el punto medio del arreglo y se compara el numero a buscar; 
si el numero es mayor entonces se busca en el subarreglo derecho, sino en el izquierdo. El punto medio de referencia se 
recorre bajo el mismo criterio hasta que se encuentra o no. 
*/
int busquedaBinaria(int A[], int inicio, int final, int num){
	int medio;//punto de referencia
	//algoritmo de busqueda 
	while(inicio<=final){
		medio= (inicio + final)/2;
		if(A[medio]==num){
			return medio;
		}else{
			if(num<A[medio]){
				final = medio-1;
			}else{
				inicio = medio+1;
			}
		}
	}
	return -1;
}
