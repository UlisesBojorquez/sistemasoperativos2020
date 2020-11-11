#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){
char *sourceFile=argv[1];
char *destinationFile=argv[2];

    int fd=open(sourceFile, O_RDONLY,0); //abrir archivos, fopen. DIRECCION ARCHIVO, MODO
    
    if(fd<0){
        printf("Error al abrir el archivo \n");
        return 1;
    }
    
    
    int dfd=open(destinationFile, O_WRONLY | O_CREAT,0600);
    
    
    char c;
    while(read(fd,&c,1)){ //read
        write(dfd,&c,1);
    }

    close(fd);
    close(dfd);
    

    return 0;
}