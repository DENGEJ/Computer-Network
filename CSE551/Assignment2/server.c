#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>

#define SERVER_PORT 15539

int main()
{
 int sd,newsd,clilen,n;
 struct sockaddr_in cliaddr,servaddr;
 char line[100];

 bzero((char *) &servaddr,sizeof(servaddr));
 servaddr.sin_family=AF_INET;
 servaddr.sin_addr.s_addr=INADDR_ANY;
 servaddr.sin_port=htons(SERVER_PORT);

 sd=socket(AF_INET,SOCK_STREAM,0);
 printf("\nsuccessfully created stream socket\n");

 bind(sd,(struct sockaddr *) &servaddr,sizeof(servaddr));
 printf("\nlocal port successfully bound\n");

 listen(sd,5);

while(1){
  printf("\nwaiting for any client to connect at port %u\n",SERVER_PORT);
  newsd=accept(sd,(struct sockaddr *) &cliaddr,&clilen);
  printf("\n received from host [ip %u TCP port %d]\n",inet_ntoa(cliaddr.sin_addr),htons(cliaddr.sin_port));
  do{
    memset(line,0x0,100);
    n=recv(newsd,line,100,0);
    line[n]='\0';
    printf("received from host: %s\n",line);
  }while(strcmp(line,"quit"));
 }
  printf("\nclosing connection\n");
  close(sd);
 return 0;
}
