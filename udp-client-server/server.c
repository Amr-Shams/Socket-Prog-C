/**
 * @brief echo server
 * @author Amr Shams
 * @date 2023-10-10
 * @details echo server for udp connection
 */ 
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

#define PORT 4444
#define MAXLINE 1024

/**
 * @brief main function
*/

int main()
{
    int sockfd;
    char buffer[MAXLINE];
    socklen_t addlen;
    char *message = "Hello Client";
    struct sockaddr_in servaddr, cliaddr;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;
    /**
     * @brief socket create and varification
    */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    else 
    {
        printf("Socket successfully created..\n");
    }
    /**
     * @brief assign IP, PORT
    */
    bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    /**
     * @brief infinite loop for recieveing
    */

   while(1)
   {
    addlen = sizeof(cliaddr);
    int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&cliaddr, &addlen);
    buffer[n] = '\0';
    printf("Client : %s\n", buffer);
    if(strncmp("exit", buffer, 4) == 0)
    {
        printf("Server Exit...\n");
        break;
    }
    if(n < 6)
    {
        printf("Client : %s\n", buffer);
        sendto(sockfd, message, MAXLINE, 0, (struct sockaddr*)&cliaddr, sizeof(cliaddr)); // send the response
    }
   }
    return 0;
}