//adding includes
#include <stdio.h>
#include <stdlib.h>
//for socket and related functions
#include <sys/types.h>
#include <sys/socket.h>
//for including structures which will store information needed
#include <netinet/in.h>
#include <unistd.h>
/*
 * @breif this is the server side follwoing the steps of creating a connection
 */
int main(){
	int network_socket; // create the socket and store this into a var 
			    //
	// AF_INET = defined in the header file 
	// SOCK_STREAM FOR TCP
	// 0 for TCP 
	
	network_socket = socket(AF_INET,SOCK_STREAM,0);
	// connect to the other side
	// specify the address 
	// struct used is sockaddr_in
	struct sockaddr_in server_address;
	// sin_family = signal family the type of the address
	server_address.sin_family = AF_INET;
	// convert the port number into the byte used in the struct use a converison function 
	// htons: the conversion function 
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;
	int connect_status = connect(network_socket,(struct sockadd*)&server_address,sizeof(server_address));
	// handle the error connection
	if(connect_status == -1)
		printf(stderr,"Error 004");
	char server_response[256];
	recv(network_socket,&server_response,sizeof(server_response),0);

	printf("the msg: %s",server_response);
	
	// close the connection 
	close(network_socket);
	return 0;
}
