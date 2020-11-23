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
    // Inizializa numeros fibonacci  
    int fibMMm2 = args->p2; // (m-2)'th Fibonacci No. 
    int fibMMm1 = args->p1; // (m-1)'th Fibonacci No. 
    int fibM = fibMMm2 + fibMMm1; // m Fibonacci 
    int n = args->tam;
    int x = args->elemento;
    while (fibM > 1) 
        { 
            // Check if fibMm2 is a valid location 
            int i = min(offset+fibMMm2, n-1); 
            // Si x es maqyor que el valor de index fibMn2, corta el subarray 
            if ((args->arreglo[i]) < x) 
            { 
                fibM = fibMMm1; 
                fibMMm1 = fibMMm2; 
                fibMMm2 = fibM - fibMMm1; 
                offset = i; 
            } 
  
            // Si x es menor que el valor index fibMm2, corta el subarray despues de i+1 
            else if ((args->arreglo[i]) > x) 
            { 
                fibM = fibMMm2; 
                fibMMm1 = fibMMm1 - fibMMm2; 
                fibMMm2 = fibM - fibMMm1; 
            } 
  
            // Elemento encontrado retorna S
            else
            {
                status = 0;
                pthread_exit((void*)&status);           
            } 
        } 
  
        // compara el ultimo elemento con x 
        if(fibMMm1 == 1 && (args->arreglo[offset+1]) == x) 
            status = 0;
  
        //Elemento no encontrado retorna N */
        status = -1;
    pthread_exit((void*)&status);
}

void main(int argc, char *argv[]){
    struct datos *fibo = NULL;
    pthread_t id1 = 0,id2 = 0;
    int n = 0, target = 0, *numeros, i = 0;
    int eid1 = -1, eid2 = -1;

    int fibMMm2 = 0; // (m-2)'th Fibonacci No. 
    int fibMMm1 = 1; // (m-1)'th Fibonacci No. 
    int fibM = fibMMm2 + fibMMm1; // m Fibonacci 
    
    n = atoi(argv[1]);
    target = atoi(argv[2]);

    numeros = malloc(sizeof(int)*n);
    fibo = malloc(sizeof(struct datos));

    fibo -> tam = n;
    fibo -> elemento = target;
    
    if(numeros==NULL)
        exit(2);
    //Se leen los numeros desde la consola o un archivo
    for(i=0;i<n;i++){
        scanf("%i",&numeros[i]);
    }

    fibo-> arreglo = numeros;
    /*Generamos los numeros fibonacci, para el tamaño de problema
    el índice máximo alcanzado en la serie fibonacci será el 36
    por lo tanto, se propone la creacion de dos hilos, uno busca
    en índice < 18 y otro en índice > 18*/
    i = 0;
    // fibM va a guardar el mas pequeño
    while (fibM < n) 
    { 
        fibMMm2 = fibMMm1; 
        fibMMm1 = fibM; 
        fibM = fibMMm2 + fibMMm1; 
        i++;
        if(i==18){
            //Lanzamos un hilo que busque aqui
            fibo -> p1 = fibMMm1;
            fibo -> p2 = fibMMm2;
            pthread_create(&id1,NULL,fibonacci,(void*)fibo);
        }
    } 
    //Alcanzo los ultimos numeros, lanzamos otro hilo para que busque por alla
    fibo -> p1 = fibMMm1;
    fibo -> p2 = fibMMm2;
    pthread_create(&id2,NULL,fibonacci,(void*)fibo);
    
    pthread_join(id1,(void*)&eid1);
    if(eid1==0)
        printf("Encontrado por hilo 1\n");
    pthread_join(id2,(void*)&eid2);
    if(eid2==0)
        printf("Encontrado por hilo 2\n");
    if(eid1!=0 && eid2!=0)
        printf("No encontrado\n");
    
    return;
}nt x, int y) { return (x<=y)? x : y; }

void *fibonacci(void *ags){
    printf("Entro hilo1\n");
    struct datos *args = (struct datos*) ags;
    int status = 0, offset = 0;
    // Inizializa numeros fibonacci  
    int fibMMm2 = args->p2; // (m-2)'th Fibonacci No. 
    int fibMMm1 = args->p1; // (m-1)'th Fibonacci No. 
    int fibM = fibMMm2 + fibMMm1; // m Fibonacci 
    int n = args->tam;
    int x = args->elemento;
    while (fibM > 1) 
        { 
            // Check if fibMm2 is a valid location 
            int i = min(offset+fibMMm2, n-1); 
            // Si x es maqyor que el valor de index fibMn2, corta el subarray 
            if ((args->arreglo[i]) < x) 
            { 
                fibM = fibMMm1; 
                fibMMm1 = fibMMm2; 
                fibMMm2 = fibM - fibMMm1; 
                offset = i; 
            } 
  
            // Si x es menor que el valor index fibMm2, corta el subarray despues de i+1 
            else if ((args->arreglo[i]) > x) 
            { 
                fibM = fibMMm2; 
                fibMMm1 = fibMMm1 - fibMMm2; 
                fibMMm2 = fibM - fibMMm1; 
            } 
  
            // Elemento encontrado retorna S
            else
            {
                status = 0;
                pthread_exit((void*)&status);           
            } 
        } 
  
        // compara el ultimo elemento con x 
        if(fibMMm1 == 1 && (args->arreglo[offset+1]) == x) 
            status = 0;
  
        //Elemento no encontrado retorna N */
        status = -1;
    pthread_exit((void*)&status);
}

void main(int argc, char *argv[]){
    struct datos *fibo = NULL;
    pthread_t id1 = 0,id2 = 0;
    int n = 0, target = 0, *numeros, i = 0;
    int eid1 = -1, eid2 = -1;

    int fibMMm2 = 0; // (m-2)'th Fibonacci No. 
    int fibMMm1 = 1; // (m-1)'th Fibonacci No. 
    int fibM = fibMMm2 + fibMMm1; // m Fibonacci 
    
    n = atoi(argv[1]);
    target = atoi(argv[2]);

    numeros = malloc(sizeof(int)*n);
    fibo = malloc(sizeof(struct datos));

    fibo -> tam = n;
    fibo -> elemento = target;
    
    if(numeros==NULL)
        exit(2);
    //Se leen los numeros desde la consola o un archivo
    for(i=0;i<n;i++){
        scanf("%i",&numeros[i]);
    }

    fibo-> arreglo = numeros;
    /*Generamos los numeros fibonacci, para el tamaño de problema
    el índice máximo alcanzado en la serie fibonacci será el 36
    por lo tanto, se propone la creacion de dos hilos, uno busca
    en índice < 18 y otro en índice > 18*/
    i = 0;
    // fibM va a guardar el mas pequeño
    while (fibM < n) 
    { 
        fibMMm2 = fibMMm1; 
        fibMMm1 = fibM; 
        fibM = fibMMm2 + fibMMm1; 
        i++;
        if(i==18){
            //Lanzamos un hilo que busque aqui
            fibo -> p1 = fibMMm1;
            fibo -> p2 = fibMMm2;
            pthread_create(&id1,NULL,fibonacci,(void*)fibo);
        }
    } 
    //Alcanzo los ultimos numeros, lanzamos otro hilo para que busque por alla
    fibo -> p1 = fibMMm1;
    fibo -> p2 = fibMMm2;
    pthread_create(&id2,NULL,fibonacci,(void*)fibo);
    
    pthread_join(id1,(void*)&eid1);
    if(eid1==0)
        printf("Encontrado por hilo 1\n");
    pthread_join(id2,(void*)&eid2);
    if(eid2==0)
        printf("Encontrado por hilo 2\n");
    if(eid1!=0 && eid2!=0)
        printf("No encontrado\n");
    
    return;
}
