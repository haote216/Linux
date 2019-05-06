#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

// ./tcp_server ip port
int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage: %s ip port\n");
        return 1;
    }

    int listen_sock = socket(AF_INET,SOCK_STREAM, 0 );
    if(listen_sock < 0)
    {
        perror("socket");
        return 2;
    }

    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(atoi(argv[2]));
    local.sin_addr.s_addr = inet_addr(argv[1]);

    if(bind(listen_sock,(struct sockaddr*)&local, sizeof(local)) < 0)
    {
        perror("bind");
        return 3;
    }

    if(listen(listen_sock, 5) < 0)
    {
        perror("listen");
        return 4;
    }
    
    for(;;) 
    {
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        int new_sock = accept(listen_sock,(struct sockaddr*)&client, &len);
        if(new_sock < 0)
        {
            perror("accept");
            continue;
        }
        
        printf("get a new client,[%s:%d]\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port)); 

        pid_t id = fork();
        if(id == 0)
        {
            //child 
            close(listen_sock);
            if(fork() > 0)
            {
                exit(0);
            }
            char buf[128];
            while(1)
            {
                ssize_t s = read(new_sock, buf, sizeof(buf)-1);
                if(s > 0)
                {
                    buf[s]= 0;
                    printf("[%s:%d]:> %s\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port),buf);
                    write(new_sock, buf, strlen(buf));
                }
                else if(s == 0)
                {
                    printf("client quit, break!\n");
                    break;
                }
                else 
                {
                    perror("read");
                    break;
                }
            }
            close(new_sock);
            exit(0);
        } 
        else 
        {
            //father
            close(new_sock);
            waitpid(id, NULL, 0);
        }
    }
}




























