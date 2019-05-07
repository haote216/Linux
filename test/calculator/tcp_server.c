#include"comm.h"


void serviceIO(int sock)
{
    /*char buf[128];
    while(1)
    {
        ssize_t s = read(sock, buf, sizeof(buf)-1);
        if(s > 0)
        {
            buf[s]= 0;
            printf("client### %s\n", buf);
            write(sock, buf, strlen(buf));
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
    }*/
    while(1)
    {

        request_t r;
        ssize_t s = read(sock,&r,sizeof(r));
        if(s <= 0)
        {
            printf("client quit!\n");
            break;
        }

        response_t rp = {0, 0};
        switch(r.op)
        { 
            case 1:
                rp.result = r.x + r.y;
                break;
            case 2:
                rp.result = r.x - r.y;
                break;
            case 3:
                rp.result = r.x * r.y;
                break;
            case 4:
                {
                    if(r.y == 0)
                    {
                        rp.status = -1;
                    }
                    else{
                        rp.result = r.x / r.y;
                    }
                }
                break;
            case 5:
                rp.result = r.x % r.y;
                break;
            default:
                rp.status = -2;
                break;
        }
        write(sock,&rp,sizeof(rp));
    }
}
void *service(void *arg)
{
    int sock =(int)arg;
    serviceIO(sock);
}

// ./tcp_server ip port
int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage: %s ip port\n",argv[0]);
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
        pthread_t tid;
        pthread_create(&tid, NULL, &service, (void *)new_sock);
        pthread_detach(tid);
    }
}



























