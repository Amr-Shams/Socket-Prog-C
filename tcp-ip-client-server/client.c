//adding includes
#include <stdio.h>
#include <stdlib.h>
//for socket and related functions
#include <sys/types.h>
#include <sys/socket.h>
//for including structures which will store information needed
#include <netinet/in.h>
#include <unistd.h>

/**
 * @breif client server app
 */
int main(){
    char msg[256] = "Hello World!!";
    // the same proc as the server 
    int server_socket; 
    server_socket = socket(AF_INET,SOCK_STREAM,0);
    // define the connection family 
    //
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket,(struct sockaddr*) &server_address,sizeof(server_address));
    listen(server_socket,5);

    // start accepting 
    int client_socket;
    // accpet(sockerWeAccept,IsConnectingFrom,)
    client_socket = accept(server_socket,NULL,NULL);
    // send the data the server is alive 
    // send(Des,Msg,Size,FLAg type )
    send(client_socket,msg,sizeof(msg),0);

    // close the conn
    //
    close(server_socket);
    return 0;
}
