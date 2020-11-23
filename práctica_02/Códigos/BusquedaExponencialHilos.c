/*
  Título: Medicion de tiempo de Algoritmo de Busqueda Exponencial con hilos
  Descripción: Implementación de Busqueda de Exponencial con hilos.
  Fecha: 22/Noviembre/2020.
  Versión: Versión 1.0
  Autor: Guerrero Espinosa Ximena Mariana
 Compilación: "gcc BusquedaExponencialHilo.c tiempo.c -o beh -lpthread"
 Ejecución: "./beh [tamaño del problema] [numero a buscar]"
*/
//LIBRERIAS INCLUIDAS
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"


//VARIABLES GLOBALES
int NumThreads; //Número de threads
int N,j;
int *A;	//Arreglo dinámico donde se guardaran los n numeros del archivo
int B;		//Número a buscar

/*La funcion procesar se creo para indicar a cada uno de los hilos en que intervalo del arreglo 
trabajara, resaltemos que se recibira el identificador del hilo; considerando que el arreglo esta
ordenado ascendentemente podemos definir el inicio y fin de cada intervalo. Asimismo se indicara 
que hilo fue el que lo encontró. 
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
	
	if(exponentialSearch(A,inicio,fin,B)==1){
		printf("-----El numero %d se encontró en este intervalo", B);
	}
	
	if(n_thread!=0){
		pthread_exit(0); //Termina el hilo en ejecucion.
	}
}
int exponentialSearch(int A[], int inicio, int final, int num);

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

	A=(int*)malloc(sizeof(int)*N); //Creación de memoria para el arreglo
	//ciclo para llenar el arreglo con el tamaño del problema 
	for(i=0; i<N; i++){
		scanf("%d", &A[i]);
	}

	i=0;

		double utime0=0, stime0=0, wtime0=0, utime1=0, stime1=0, wtime1=0;

		uswtime(&utime0, &stime0, &wtime0);

		printf("----------BUSQUEDA NUMERO: %d ----------\n", B);

		//Crear los threads con el comportamiento "procesar"
		//ciclo para enviar cada hilo a la funcion procesar 
		
		for (i=1; i<NumThreads; i++) 
		{	 
			if (pthread_create (&thread[i], NULL, procesar,(void*)i) != 0 ) 
			{
				perror("El thread no pudo crearse");
				exit(-1);
			}
		}
		procesar(0);
		
		//Esperar a que terminen los threads (Procesar)
		for (i=1; i<NumThreads; i++){
				pthread_join(thread[i], NULL);
			} 	

		uswtime(&utime1, &stime1, &wtime1);
		//Cálculo del tiempo de ejecución del programa
		printf("\n");
		printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
		printf("user (Tiempo de procesamiento en CPU's) %.10f s\n",  utime1 - utime0);
		printf("%d threads (Tiempo de procesamiento aproximado por cada thread en CPU) %.10f s\n", NumThreads,(utime1 - utime0)/NumThreads);	
		printf("sys (Tiempo en acciónes de E/S)  %.3f s\n",  stime1 - stime0);
		printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
		printf("\n");
	
	//Terminar programa normalmente	*/
	exit (0);	
}

int exponentialSearch(int A[], int inicio, int final, int num){
    int i = 1;
    int n=final-inicio;
    while (i < n && A[i] <= num)
        i = i*2;
    int right=0;
	if(i < (n-1)) right=i;
	else right=(n-1);
	int left=i/2;
  // Dividimos y buscamos hasta que lleguemos ambos índices sean iguales
  while(left<=right){
        // Variable para dividir en mitades
        int middle=(left+right)>>1; 
  
        // Revisamos si "x" se encuentra en la posición middle actual
        if (A[middle]==num){
          return 1; 
        }   
        // Si "x" es más grande que el valor de middle 
        if(A[middle]<num){
          /* Ignoramos los valores de la izquierda igualando
             al valor de left con middle+1 */
          left=middle+1; 
        }else{ // Si n es más pequeño que el valor de middle 
          /* Ignoramos los valores de la derecha igualando
             al valor de right con middle-1 */
          right=middle-1;}
 
	}
}
