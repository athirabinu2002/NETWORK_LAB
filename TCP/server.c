#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<fcntl.h>



int main()
{
    char buf[100],bufs[100];
    struct sockaddr_in server,client;
    int sock_desc,temp_sock_desc;
    socklen_t len;
    int k;
    
    sock_desc=socket(AF_INET,SOCK_STREAM,0);
    if(sock_desc==-1)
      printf("error in socket creation");
    
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    server.sin_port=3003;
    
    client.sin_family=AF_INET;
    client.sin_addr.s_addr=INADDR_ANY;
    client.sin_port=3003;
    
    k=bind(sock_desc,(struct sockaddr*)&server,sizeof(server));
    if(k==-1)
      printf("error in binding");
    
    k=listen(sock_desc,5);
    if(k==-1)
      printf("error in listening");
    
    len=sizeof(client);
    temp_sock_desc=accept(sock_desc,(struct sockaddr*)&client,&len);
    if(temp_sock_desc==-1)
      printf("error in temp socket creation");
    for(;;)                                      // instead of this USE while(1)
    {
        k=recv(temp_sock_desc,buf,100,0);
        if(k==-1)
          printf("error in receiving");
        int c= atoi(buf);
        if(c!=0)
        {
            
            if(c==1111)
            {
                printf("exiting....");
                exit(0);
                
            }
            printf("message got from client%s",buf);       //in normal tcp after this (printf("enter message to client") fgets(bufs,100,stdin)
            int fact=1;
            for(int i=1;i<=c;i++)
              fact=fact*i;
            sprintf(bufs, "%d",fact);
            k=send(temp_sock_desc,bufs,100,0);
            if(k==-1)
              printf("error in sending");
         
        }
        else
        {
          sprintf(bufs "%d",0);
        k=send(temp_sock_desc,bufs,100,0);   // the this step <<
        if(k==-1)
              printf("error in sending");
    
        }    
     }
    
}
