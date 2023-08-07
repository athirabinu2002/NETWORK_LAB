// FACTORIAL OF NUMBER
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<fcntl.h>

int main()
{
    char buf[100];
    int sock_desc;
    struct sockaddr_in server,client;
    socklen_t len;
    
    sock_desc=socket(AF_INET,SOCK_STREAM,0);
    if(sock_desc==-1)
      printf("error in socket creation");
    
    client.sin_family=AF_INET;
    client.sin_addr.s_addr=INADDR_ANY;
    client.sin_port=3003;
    
    k=connect(sock_desc,(struct sockaddr*)&client,&sizeof(client));
    if(k==-1)
      printf("error in connecting");
    for(;;)
    {
        printf("enter data to be send");
        fgets(buf,100,stdin);
        
        if atoi(buf)==1111
        {
            k=send(sock_desc,buf,100,0);
            printf("exiting");
            exit(0);
        }
         
        k=send(sock_desc,buf,100,0);
        if(k==-1)
         printf("error in sending");
        k=recv(sock_desc,buf,100,0);
        if(k==-1)
         printf("error in recieving");
        
        
        int l=atoi(buf);
        if(l !=0)
        
            printf(factorial %s, buf)
        
        else
            printf("you have passed word rather than number");
            
        
        
        
    }
    
}
