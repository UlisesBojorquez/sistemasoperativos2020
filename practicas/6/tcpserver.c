#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
extern int h_errno;
#include <strings.h>
#include <string.h>

int main(){



    struct sockaddr_in serverAddress;
    serverAddress.sin_family= AF_INET;
    serverAddress.sin_port=htons(27282);
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY); //CUALQUIER DIRECCION DE LA MAQUINA LOCAL

    int sockfd=socket(AF_INET, SOCK_STREAM, 0);
    bind(sockfd,(const struct sockaddr *) &serverAddress, sizeof(serverAddress));
    listen(sockfd,5);

    
    while(1){
        struct sockaddr_in clientAddress;
        int clientSize=sizeof(clientAddress);
        int clientSocket=accept(sockfd, (struct sockaddr *)&clientAddress, (unsigned int *) &clientSize);
        char c;
        char *message="Hello desde gitpod";
        //while(read(clientSocket,&c,1)){
         //   printf("%c",c);
            //write(clientSocket,&c, 1);
        //}
        write(clientSocket, message, strlen(message));
        close(clientSocket);
    }

}