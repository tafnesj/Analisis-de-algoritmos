//Compilación: "gcc BusquedaBinaria.c -o bb"
//Ejecución: "./bb [tamaño del problema] [numero a buscar]"

//LIBRERIAS INCLUIDAS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
   


//VARIABLES GLOBALES
int N,j;
int *A;	//Arreglo dinámico donde se guardaran los n numeros del archivo
int B;		//Número a buscar

int busquedaBinaria(int A[], int B, int N);


//PROGRAMA PRINCIPAL 

int main (int argc, char *argv[])
{	
	int i=0; //Variables para ciclo for
	
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
		printf("----------BUSQUEDA NUMERO: %d ----------\n", B);
		if(busquedaBinaria(A,B,N))
				printf("Numero encontrado\n");
		else
			printf("No encontrado\n");

	//Terminar programa normalmente	*/
	exit (0);	
}
/*Funcion para la busqueda de cada numero 
la busqueda binaria funciona, marcando el punto medio de arreglo donde se busca el numero, luego , si el numero  a buscar
es mayor entonces el punto de inicio par buscar de recorre a la mitad del arreglo y se obtiene un nuevo punto medio
si este es menor, el final se recorre hasta el punto medio y se obtiene una nueva mitad, y así hasta que el 
numero medio coincida con el numero a buscar 
*/
int busquedaBinaria(int arreglo[], int busqueda, int tamanioDelArreglo){
    int izquierda = 0, derecha = tamanioDelArreglo - 1;
    while (izquierda <= derecha){
        int indiceDeLaMitad = floor((izquierda + derecha) / 2);
 
        int valorQueEstaEnElMedio = arreglo[indiceDeLaMitad];
 
        if (busqueda == valorQueEstaEnElMedio){
            // En caso de encontrar lo que buscamos, terminamos la función
            // y regresamos el índice
            return indiceDeLaMitad;
        }
        
        if (busqueda < valorQueEstaEnElMedio){
            // Entonces está hacia la izquierda
            derecha = indiceDeLaMitad - 1;
        }else{
            // Está hacia la derecha
            izquierda = indiceDeLaMitad + 1;
        }
    }
    // Termina el ciclo y no encontramos nada
    return -1;
}
