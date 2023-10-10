/**
 * @file client.c
 * @brief FTP client
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include "netdb.h"
#include "arpa/inet.h"
#include "netinet/in.h"


#define PORT 21


/**
 * @brief FTP client
 * @param argc Number of arguments
 * @param argv Arguments
 * @return 0 on success, 1 otherwise
*/

int main(){
    int sockfd;
    struct sockaddr_in serverAddress;
    char buffer[1024],file[1000];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("Error creating socket");
        exit(1);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    while (1)
    {
       printf("File name: ");
       scanf("%s",buffer);
       // send file name to server
        send(sockfd, buffer, strlen(buffer), 0);
        // receive file from server
        printf("Receiving file...\n");
        recv(sockfd, file, 1000, 0);
        printf("%s",file);
    }
    return 0;
}