#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/time.h>
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

    int maxfd =listen_sock; 
    fd_set reads,temp;
    FD_ZERO(&reads);
    FD_SET(listen_sock,&reads);
    

    while(1)
    {
        struct sockaddr_in client;
        socklen_t client_len = sizeof(client);

        temp = reads;
        int ret = select(maxfd+1,&reads,NULL,NULL,NULL);
        if(ret == -1)
        {
            perror("select error");
            exit(1);
        }

        if(FD_ISSET(listen_sock, &temp))
        {
            int cfd = accept(listen_sock, (struct sockaddr*)&client,&client_len);
            if(cfd == -1)
            {
                perror("accept error");
                exit(1);
            }
            printf("new client ip:%s, port:%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
            FD_SET(cfd, &temp);
            maxfd = maxfd < cfd ? cfd : maxfd;
        }
        int i = listen_sock + 1;
        for(;i<=maxfd;++i)
        {
            if(FD_ISSET(i,&temp))
            {
                char buf[1024] = {0};
                while(1)  
                {
                    int len = read(i,buf,sizeof(buf)-1);
                    buf[len] = '\0';
                    if(len == 0)
                    {
                        printf("客户端断开连接\n");
                        close(i);
                        FD_CLR(i, &temp);
                        break;
                    }
                    else if(len == -1)
                    {
                        perror("recv error");
                        break;
                    }
                    else 
                    {
                        printf("recv buf: %s\n",buf);
                        write(i, buf,strlen(buf));
                    }   
                }
            }
        }
    }
    close(listen_sock);
    return 0;
}




























