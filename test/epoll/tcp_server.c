#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<sys/epoll.h>

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

    int epfd = epoll_create(3000);
    struct epoll_event all[3000];
    
    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = listen_sock;

    epoll_ctl(epfd,EPOLL_CTL_ADD,listen_sock,&ev);

    while(1)
    {
        struct sockaddr_in client;
        socklen_t client_len = sizeof(client);
        
        int ret = epoll_wait(epfd,all,3000,-1);
        int i = 0;    
        for(;i<ret;++i)
        {
            int cfd =all[i].data.fd;
            char buf[1024];
            if(cfd == listen_sock)//建立新的连接，把连接上树
            {
                int cfd = accept(listen_sock,(struct sockaddr*)&client,& client_len);
                printf("有新的客户端建立连接\n");

                ev.events = EPOLLIN;
                ev.data.fd = cfd;
                epoll_ctl(epfd,EPOLL_CTL_ADD,cfd,&ev);
            }
            else //已有的连接传输数据
            {
                //while(1)
                //{
                    if(!(all[i].events & EPOLLIN))
                        continue;
                    else{
                        int len = read(all[i].data.fd, buf, sizeof(buf)-1); 
                        printf("recv buf: %s\n", buf);

                        if(len == 0)
                        {
                            printf("客户端断开连接\n");
                            close(cfd);
                            epoll_ctl(epfd, EPOLL_CTL_DEL,cfd,&ev);
                            break;
                        }
                        write(all[i].data.fd, buf,strlen(buf));
                        }
                //}
             }
        }
    }
    close(listen_sock);
    return 0;
}




























