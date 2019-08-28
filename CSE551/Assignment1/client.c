#include<sys/types.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>

#define CLIENT_PORT 15559
#define SERVER_PORT 15557

int main()
{
 int sd,newsd,client,n;
 struct sockaddr_in cliaddr,servaddr;

 bzero((char *) &servaddr,sizeof(servaddr));
 servaddr.sin_family=AF_INET;
 servaddr.sin_addr.s_addr=INADDR_ANY;
 servaddr.sin_port=htons(SERVER_PORT);

 bzero((char *) &cliaddr,sizeof(cliaddr));
 cliaddr.sin_family=AF_INET;
 cliaddr.sin_addr.s_addr=INADDR_ANY;
 cliaddr.sin_port=htons(CLIENT_PORT);
 sd=socket(AF_INET,SOCK_STREAM,0);
 printf("\nsuccessfully created socket\n");

 bind(sd,(struct sockaddr *) &cliaddr,sizeof(cliaddr));
 printf("\nlocal port successfully bound\n");

 connect(sd,(struct sockaddrn *) &servaddr,sizeof(servaddr));
 printf("\nconnected successfully\n");
 close(sd);
 return 0;
}
