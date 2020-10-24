#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
extern int h_errno;


int main(){
    struct sockaddr_in serverAddress;
    

    serverAddress.sin_family=AF_INET;
    serverAddress.sin_port=htons(2729);
    serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);//CUALQUIER DIRECCION IP QUE TENGA ESTA MAQUINA

    int sockfd=socket(AF_INET, SOCK_STREAM, 0); 
    bind(sockfd, &serverAddress, sizeof(serverAddress)); //socket, server addres, tamaño server address
    listen(sockfd, 5); //socket donde se van a conectar mis clientes, cuantos clientes pueden estar encolados esperando el servicio
    while(1){
        /*
        -El cliente llega, el servidor atrapa esa funcion accept
        -El accept me regresa primero al informacion del cliente (por donde se esta conectando, etc.), regresa otro socket (otro recurso que cualquier cosa que escriba ahi te servira para poder conectarse con ese cliente en particular)
        -El socket original que creo el server solo sirve para hacer LISTEN(), puerto en mi caso 2729
        -Despues del accept se va a crear otro socket con otro puerto diferente donde estos dos (cliente-servidor) van a estar platicando, hacen un close los dos y 
        -El accept regresa otro puerto donde realmente va a pasar la comunicacion, dejando lobre el de LISTEN para que alguien mas se pueda conectar
         
        */
        struct sockaddr_in clientAddress; //aqui copiara la info el socket del cliente
        int clientSize=sizeof(clientAddress);
        //socket del cliente
        int clientSocket=accept(sockfd, &clientAddress,&clientSize); //socket, direccion del cliente, tamaño direccion

        char c;
        char *message="Hello desde gitpod";
        //while(read(clientaSocket, &c, 1)){
          //  printf("%c", c);
            
        //}
        write(clientSocket,message,strlen(message));
        close(clientSocket);

    }
}