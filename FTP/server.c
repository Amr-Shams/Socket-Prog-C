/**
 * @file server.c
 * @brief FTP server
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//headers for socket and related functions
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
//for including structures which will store information needed
#include <netinet/in.h>
#include <unistd.h>
//for gethostbyname
#include "netdb.h"
#include "arpa/inet.h"

#define PORT 21

int main(){
    int sockfd;
    struct sockaddr_in serverAddress, newAddress;
    socklen_t addr_size;
    char buffer[1024],file[1000];


    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("Error creating socket");
        exit(1);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0){
        perror("Error binding");
        exit(1);
    }
    /**
     * @brief Listen for incoming connections
     * @param sockfd Socket file descriptor
     * @param backlog Maximum number of connections to be queued
    */
    if(listen(sockfd, 5) < 0){
        perror("Error listening");
        exit(1);
    }
    printf("Server started\n");

    int clientCount = accept(sockfd, (struct sockaddr*)&newAddress, &addr_size);
    if(clientCount < 0){
        perror("Error accepting");
        exit(1);
    }
    while(1)
    {
        // reset buffer
        memset(buffer, 0, sizeof(buffer));
        // reset the file
        memset(file, 0, sizeof(file));
        // receive file name from client
        recv(clientCount, buffer, 1024, 0);
        // open file
        FILE *fp = fopen(buffer, "r");
        // check if file exists
        if(fp == NULL){
            strcpy(file, "File not found\n");
        }
       fread(file, 1, 1000, fp);
        send(clientCount, file, 1000, 0);
    }
    return 0;
}