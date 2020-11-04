#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUF_SIZE 10


sem_t mutexBuffer;
unsigned int buffer[BUF_SIZE];

sem_t semEspacios; //es para indicar espacios disponibles
sem_t semDatos; //es para indicar que hay algo que consumir


void *producer(void *arg){
    int i=0;
    while(1){

        sleep(1); //tiempo que nos produce un dato, simulacion
        sem_wait(&semEspacios); //checa que hay espacios en el buffer donde guardarlos
        sem_wait(&mutexBuffer); //trata de acceder al buffer, se protege el acceso, 1 tiene acceso 0 tiene que esperar
        buffer[i]=rand();
        sem_post(&mutexBuffer); //libera al buffer y lo incrementa, alguien mas peuda usarlo
        sem_post(&semDatos); //ya hay un dato que consumir (es un 1)
        i+=1;
        if(i==BUF_SIZE){
            i=0;
        }
    }

    pthread_exit(NULL);
}

void *consumer(void *arg){
    int i=0;
    while(1){
        sem_wait(&semDatos); //si el consumidor corre antes del productor se bloquea osea inicia en 0, y con este se resta y lo bloque porque no hay -1
        sem_wait(&mutexBuffer); //lo suspende para que nadie mas lo use
        int dato=buffer[i];
        //buffer[i]=0; //con esto se limpia
        sem_post(&mutexBuffer); //lo libera

        printf("El valor leido es %d \n", dato);
        sleep(2); //lo que tarda en consumir el dato
        i+=1;
        if(i==BUF_SIZE){
            i=0;
        }
    }
    pthread_exit(NULL);
}

int main(){
    sem_init(&mutexBuffer,0,1);
    sem_init(&semEspacios,0,BUF_SIZE);
    sem_init(&semDatos,0,0);
    pthread_t tproducer;
    pthread_t tconsumer;
    pthread_create(&tproducer, NULL, producer, NULL);
    pthread_create(&tconsumer, NULL, consumer, NULL);

    pthread_exit(NULL);
}


