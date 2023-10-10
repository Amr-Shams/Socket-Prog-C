/**
 * @file client.c
 * @brief UDP client
 * @details echo client for udp connection
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 4444
#define MAXLINE 1024

/**
 * @brief main function
*/

int main(){
    int server_fd;
    socklen_t addlen;
   char sendMessage[MAXLINE],recvMessage[MAXLINE];
   struct sockaddr_in servaddr;
    server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(server_fd == -1){
        printf("socket creation failed...\n");
        exit(0);
    }
    else{
        printf("Socket successfully created..\n");
    }
 
   
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
    addlen = sizeof(servaddr);
    
    // check connection
    if(connect(server_fd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        printf("Connection failed...\n");
        exit(0);
    }
    /**
     * @brief receive message from user
    */
    printf("Client: ");
    fgets(sendMessage, MAXLINE, stdin);

   /**
     * @brief send message to server
    */
    sendto(server_fd, sendMessage, MAXLINE, 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
    /**
     * @brief receive message from server
    */
    recvfrom(server_fd, recvMessage, MAXLINE, 0, (struct sockaddr*)&servaddr, &addlen);
    printf("Server: %s\n", recvMessage);
    /**
     * @brief close the socket
    */
    close(server_fd);
    return 0;
}
