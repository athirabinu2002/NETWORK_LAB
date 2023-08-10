#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>



int main()
{
    char buf[100];
    int sock_desc;
    struct sockaddr_in server,client;
    int k;
    socklen_t len;
    
    sock_desc=socket(AF_INET,SOCK_DGRAM,0);
    if(sock_desc==-1){
      printf("error in socket creation");
      return 1;
    }
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    server.sin-port=htons(atoi(4004));
    

    len= sizeof(server);
    while(1)
    {
        printf("enter data to be send");
        fgets(sock_desc,100,stdin);
        
        int c = atoi(buf);
        if(c==1111)
        {
        k=sendto(sock_desc,buf,100,0,(struct sockaddr*)&server,&sizeof(server))
        {
            if(k<0)
            printf("error in sending");
            return 1;
            
        }
        printf("exiting..");
        break;
        }
         k=sendto(sock_desc,buf,100,0,(struct sockaddr*)&server,&sizeof(server));
         if(k<0){
         printf("error in sending");
            return 1;
         } 
         k=recvfrom(sock_desc,buf,100,0,(struct sockaddr*)&server,&len;
         if(k<0){
         printf("error in receiving");
            return 1;
         }
        printf("message got from server %s",buf);
     
    
    }
}
