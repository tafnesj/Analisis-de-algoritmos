#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct datos {
	int *arreglo;
	int p2;
	int p1;
	int tam;
	int elemento;	
};

int min(int x, int y) { return (x<=y)? x : y; }

void *fibonacci(void *ags){
    printf("Entro hilo1\n");
	struct datos *args = (struct datos*) ags;
	int status = 0, offset = 0;
	
    int fibMMm2 = args->p2; 
    int fibMMm1 = args->p1; 
    int fibM = fibMMm2 + fibMMm1; 
    int n = args->tam;
    int x = args->elemento;
	while (fibM > 1) 
        { 
            
            int i = min(offset+fibMMm2, n-1); 
           
            if ((args->arreglo[i]) < x) 
            { 
                fibM = fibMMm1; 
                fibMMm1 = fibMMm2; 
                fibMMm2 = fibM - fibMMm1; 
                offset = i; 
            } 
  
           
            else if ((args->arreglo[i]) > x) 
            { 
                fibM = fibMMm2; 
                fibMMm1 = fibMMm1 - fibMMm2; 
                fibMMm2 = fibM - fibMMm1; 
            } 
  
            else
            {
            	status = 0;
    			pthread_exit((void*)&status);        	
            } 
        } 
  

        if(fibMMm1 == 1 && (args->arreglo[offset+1]) == x) 
            status = 0;
  

        status = -1;
	pthread_exit((void*)&status);
}

void main(int argc, char *argv[]){
	struct datos *fibo = NULL;
	pthread_t id1 = 0,id2 = 0;
	int n = 0, target = 0, *numeros, i = 0;
	int eid1 = -1, eid2 = -1;

	int f2 = 0; // (m-2)'th Fibonacci 
    int f1 = 1; // (m-1)'th Fibonacci 
    int menor = f2 + f1; 
	
	n = atoi(argv[1]);
	target = atoi(argv[2]);

	numeros = malloc(sizeof(int)*n);
	fibo = malloc(sizeof(struct datos));

	fibo -> tam = n;
	fibo -> elemento = target;
	
	if(numeros==NULL)
		exit(2);

	for(i=0;i<n;i++){
		scanf("%i",&numeros[i]);
	}

    fibo-> arreglo = numeros;
	
	i = 0;

    while (fibM < n) 
    { 
        fibMMm2 = fibMMm1; 
        fibMMm1 = fibM; 
        fibM = fibMMm2 + fibMMm1; 
        i++;
        if(i==18){
        	
        	fibo -> p1 = fibMMm1;
			fibo -> p2 = fibMMm2;
        	pthread_create(&id1,NULL,fibonacci,(void*)fibo);
        }
    } 

    fibo -> p1 = fibMMm1;
	fibo -> p2 = fibMMm2;
	pthread_create(&id2,NULL,fibonacci,(void*)fibo);
  	
  	pthread_join(id1,(void*)&eid1);
  	if(eid1==0)
  		printf("hilo 1\n");
  	pthread_join(id2,(void*)&eid2);
  	if(eid2==0)
  		printf("hilo 2\n");
  	if(eid1!=0 && eid2!=0)
  		printf("No encontrado\n");
  	
	return;
}
