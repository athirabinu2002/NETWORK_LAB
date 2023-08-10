#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>
#include<stdio.h>


int main()
{
    char buf[100];
    int sock_desc;
    struct sockaddr_in server,client;
    socklen_t len;
    int k;
    
    sock_desc=socket(AF_INET,SOCK_DGRAM,0);
    if(sock_desc==-1)
      printf("error in socket creation");
      return 1;
      
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    server.sin-port=htons(atoi(4004)); 
      
      
      
    k=bind(sock_desc,(struct sockaddr*)&server,sizeof(server));
    if(k<0)
      printf("error in binding");
      return 1;
   
    len=sizeof(client);
    printf("server is waiting");
    while(1)
    {
        k=recfrom(sock_desc,buf,100,0,(struct sockaddr*)&client,&len);
        if(k<0){
          printf("error in recieving");
          return 1;
        } 
        int c= atoi(buf);
        if (c==1111)
        {
            printf("exiting...");
            break;
        }
        printf("message got from client%s",buf);
         printf("enter data to be send to client");
         fgets(buf,100,stdin);
        k=sento(sock_desc,buf,100,0,(struct sockaddr*)&client,&sizeof(client));
        {
        if(k<0)
         printf("error in sending")
         return 1;
        }
    }
}
