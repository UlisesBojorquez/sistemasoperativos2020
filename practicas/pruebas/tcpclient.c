#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
extern int h_errno;

struct hostent *gethostbyname(const char *name);

void bzero(void *s, size_t n);


int main(int argc, char **argv){
    char *hostName=argv[1]; //lo que escibimos en consola (Nombre de la pagina web)
    struct hostent *serverInfo =gethostbyname(hostName); //Esto se hace para obtener de un nombre una IP (DNS), e información tambien

    //printf("Oficial name %s, IP address %s \n",hostInfo->h_name,hostInfo->h_addr_list[0]);

    //AHORA SE CREA EL SOCKET
    /*
    AF_INET se refiere a TCP version 4
    El puerto al que nos vamos a conectar
    La direccion IP
    */
    struct sockaddr_in serverAddress;
    
    /*
    Cuando creo una varible viene con basura entonces la funcion bzero, ayudara a iniciar en 0 algunas estructuras
    Esto lo que hace es limpiar esta basura
    */
    bzero(&serverAddress, sizeof(serverAddress)); //direccion en RAM y tamaño

    serverAddress.sin_family=AF_INET;
    serverAddress.sin_port=htons(2729); //htons- convierte el puerto que esta ahi, en la representacion que espera
    //serverAddress.sin_addr=serverInfo->h_addr_list[0]; //no se puede

    //Como no se puede ser hara una copia bit a bit
    bcopy((char *)serverInfo->h_addr, (char *)&serverAddress.sin_addr.s_addr, serverInfo->h_length); //de donde viene, a donde lo vas a pegar y el tamaño


    //SOCKET para concetarnos SE CREA
    int sockfd=socket(AF_INET, SOCK_STREAM, 0); //tipo de direccion IP, orientado a conexion o no, 

    connect(sockfd, &serverAddress, sizeof(serverAddress)); //socket, server address, el mañano del address
    

    char *message="GET / HTTP/1.0\r\n\r\n"; //LE DECIMOS LO QUE QUEREMOS
    write(sockfd, message, strlen(message)); //socket, lo que viene en message, el tamaño de message
    //Imprimir direccion IP
    char c;
    while(read(sockfd,&c,1)){ //RECIBIMOS E IMPRIMIMOS LO QUE PEDIMOS
        printf("%c", c);
    } 
    close(sockfd);
    printf("\n");
    
    return 0;
}

