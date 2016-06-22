#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>
#include <string.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <sys/time.h>
#include <netdb.h>  
#include <arpa/inet.h>

int main(int argc, char** argv)
{  
    float delta;
    struct timeval tv1, tv2;
    int socket_descriptor;  
    struct sockaddr_in sin;  
    struct in_addr servAddr;

    bzero(&sin,sizeof(sin));  
    sin.sin_family=AF_INET;  
    inet_aton("192.168.18.255", &(sin.sin_addr));
    sin.sin_port=htons(4398);  

    socket_descriptor=socket(AF_INET,SOCK_DGRAM,0);  
    bind(socket_descriptor,(struct sockaddr *)&sin, sizeof(sin));  

    while(1)  
    {  
        memset(&tv1, 0, sizeof(tv1));
        memset(&tv2, 0, sizeof(tv2));
        memset(&servAddr, 0, sizeof(servAddr));

        gettimeofday(&tv1, NULL);
        recvfrom(socket_descriptor, &servAddr, sizeof(servAddr),0, NULL, NULL);  
        gettimeofday(&tv2, NULL);
        delta = (double)(((tv2.tv_sec - tv1.tv_sec)*10E6 + tv2.tv_usec - tv1.tv_usec)) / 10E6;
        printf("Response from [%.2fS][%s]\n", delta, inet_ntoa(servAddr));  
    }  

    close(socket_descriptor);  

    return (EXIT_SUCCESS);  
}  

