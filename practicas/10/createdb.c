#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./student.h" //Con las comillas le estamos pasando la ruta

int main(){
    
    Student *myStudent; //apuntador
    myStudent=calloc(1, sizeof(Student)); //tiene un bloque de ceros 
    int dfd=open("class.dat", O_WRONLY | O_CREAT,0600);
    for(int i=0;i<20;i++){
        write(dfd,myStudent,sizeof(Student)); //estamos reservando el espacio para los 20 estudiantes
    }
    close(dfd);
    return 0;
}