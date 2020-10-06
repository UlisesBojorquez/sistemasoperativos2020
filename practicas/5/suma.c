#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    char c;
    char buffer[20];
    unsigned total=0;
    unsigned i=0;
    while(read(STDIN_FILENO, &c, 1)!=0){ // donde lo voy a leer, se guardara en, cantidad de carecteres que se quieren leer a la vez

        if(c !=' '){
            buffer[i]=c;
            i++;
        }else{
            buffer[i]='\0'; //hasta donde este \0 es informacion valida
            total+=atoi(buffer); //convierte de cadena a numero
            i=0;
            

        }
        
    }
    buffer[i]='\0'; //hasta donde este \0 es informacion valida
    total+=atoi(buffer); //convierte de cadena a numero

    printf("%u \n", total);
    return 0;
}