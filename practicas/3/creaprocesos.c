#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv){

    unsigned pid =fork(); //corresponde al id del hijo

    if(pid==0){
        printf("Soy el proceso hijo \n");

        execv(argv[1],&argv[1]);

        return 10;
    }else{
        int status;
        printf("Soy el proceso padre y mi hijo es %u: \n", pid);
        //hacer mas cosas
        //sleep(4);


        wait(&status); //espera a que terminen los procesos hijos
        printf("terminando despues del hijo y estatus %d \n", status);
    }

    /*
    fork(); //se crea la otra copia, habra dos cuando acabe esto
    fork(); //habran 4 cuando acabe*/
    printf("Hola mundo \n"); //se ejecuta despues 


    return 0;
}