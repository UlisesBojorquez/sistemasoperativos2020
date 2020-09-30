#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>


void signalHandler(int signum){
    int status;
    wait(&status);
    printf("Mi hijo termino con status %d \n", status);
}

int main(int argc, char **argv){
    signal(17,signalHandler);
    unsigned pid =fork(); //corresponde al id del hijo

    if(pid==0){
        sleep(5);
        printf("Soy el proceso hijo \n");
        return 10;
    }else{
        printf("Soy el proceso padre y mi hijo es %u: \n", pid);

        //aqui hace la chamba
        while(1){
            sleep(2);
            printf("trabajando \n");
        }        
    }

    /*
    fork(); //se crea la otra copia, habra dos cuando acabe esto
    fork(); //habran 4 cuando acabe*/
    printf("Hola mundo \n"); //se ejecuta despues 


    return 0;
}