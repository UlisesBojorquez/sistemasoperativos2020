#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    char c;
    char buffer[20];
    unsigned i=0;

    unsigned linea=0;
    unsigned palabra=0;
    unsigned caracter=0;

    while(read(STDIN_FILENO, &c, 1)!=0){ 
        i++; //iniciamos i en 1
        buffer[i]=c;
        if(c!='\n'){
            caracter++;
        }
        if(c=='\n'){
            linea++;
            if(buffer[i-1]!=' ' && i>1){
                palabra++;
            }
            i=0;
            
        }else if(c==' '){
            if(buffer[i-1]!='\n' && buffer[i-1]!=' ' && i>1){
                palabra++;
            }

        }
        
    }
    
    caracter=caracter+ linea; //contamos el salto de linea como un caracter
    printf("lineas: %u palabras: %u caracter: %u \n",linea, palabra, caracter);
    return 0;
}