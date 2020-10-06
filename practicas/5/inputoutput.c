#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    char c;
    while(read(STDIN_FILENO, &c, 1)!=0){ // donde lo voy a leer, se guardara en, cantidad de carecteres que se quieren leer a la vez
    
        write(STDOUT_FILENO,&c, 1);
    }
    
    return 0;


    /*char name[250];
    
    //nos permite escanear una palabra
    scanf("%s", name); 


    printf("El contenido es: %s \n", name);
    */
}