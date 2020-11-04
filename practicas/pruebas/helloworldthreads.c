#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct td{
	int hid;
	char *msg;
} ThreadData; //es el alias


void * hello(void *arg){
	ThreadData *td =(ThreadData *)arg;
	printf("%s %d \n", td->msg,td->hid);
	free(arg); //se libera espacios de memoria una vez de utilizarlo
	//pthread_exit(NULL);
}

//copile and lik with -pthread. gcc helloworldthreads.c -o helloworldthreads -pthread
int main(){
	/*
	este va a crear los hilos
	
	1-primero guarda la informacion del hilo, nos permitira posteriormente detenerlos o cancelarlos, hacer 	  algo con ellos
	2- similar al primero
	3-La funcion que quiero que ejecute el hilo
	4-argumentos que recibe la funcion del hilo
	*/
	pthread_t newThread;
	//char *msg="Hola desde el hilo\n"; char * direccion donde esta la cadena
	
	//ThreadData td[10];
	
	for(int i=0;i<10;i++){
		//calloc, cuantos argumentos quiero, tamaño
		ThreadData *td=(ThreadData *)calloc(1, sizeof(ThreadData));//es un apuntador, los datos estaran en algun lugar de la ram
		td->msg="Hola desde el hilo";
		td->hid=i;
		pthread_create(&newThread, NULL, hello, (void *)td); //& en td es porque es una direccion
	}
	pthread_exit(NULL);//se usa para que este espere a que acaben los hilos, y ahora si termina el padre
	
	return 0;
}

