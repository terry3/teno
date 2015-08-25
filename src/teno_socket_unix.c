#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "teno.h"
#include "teno_msg.h"
#include "teno_mq.h"
#include "teno_service.h"
#include "teno_monitor.h"
#include "teno_cli.h"
#include "teno_str.h"
#include "teno_socket_unix.h"

F_RET teno_server() {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[TENO_MAX_MSG_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n = 0;
    portno = TENO_SCI_SERVER_PORT;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    CHK_RET(sockfd > 0, T_ERR);
    /* clear both addr struct */
    F_BZERO((char *) &serv_addr, sizeof(serv_addr));
    F_BZERO((char *) &cli_addr, sizeof(cli_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    CHK_RET(bind(sockfd,
                 (struct sockaddr *) &serv_addr,
                 sizeof(serv_addr)) >= 0, T_ERR);
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd,
                       (struct sockaddr *) &cli_addr,
                       &clilen);
    CHK_RET(newsockfd > 0, T_ERR);
    F_BZERO(buffer, TENO_MAX_MSG_SIZE);
    n = read(newsockfd,buffer,255);
    CHK_RET(n > 0, T_ERR);
    printf("Here is the message: %s\n", buffer);
    /* TODO: must have a Mechanism to send response */
    /* n = write(newsockfd,"I got your message", 18); */
    /* if (n < 0) error("ERROR writing to socket"); */
    close(newsockfd);
    close(sockfd);
    return F_SUCCESS;
}

F_RET teno_client() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    portno = TENO_SCI_SERVER_PORT;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    CHK_RET(sockfd > 0, T_ERR);
    server = gethostbyname("terry3-VirtualBox"); /* TODO: Hard code */
    CHK_RET(server != NULL, T_ERR);
    F_BZERO((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr,
           (char *)server->h_addr,
           server->h_length);
    serv_addr.sin_port = htons(portno);
    CHK_RET(connect(sockfd,
                    (struct sockaddr *) &serv_addr,
                    sizeof(serv_addr)) >= 0,
            T_ERR);
    printf("Please enter the message: ");
    F_BZERO(buffer, 256);
    fgets(buffer, 255, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    CHK_RET(n >= 0, T_ERR);
    F_BZERO(buffer, 256);
    /* TODO: must have a Mechanism to send response */
    /* n = read(sockfd,buffer,255); */
    /* if (n < 0) */
    /*      error("ERROR reading from socket"); */
    /* printf("%s\n",buffer); */
    /* close(sockfd); */
    return 0;
}
