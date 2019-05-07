#include"comm.h"
// ./tcp_client ip port
int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage: %s ip port\n",argv[0]);
        return 1;
    }

    int sock = socket(AF_INET,SOCK_STREAM, 0 );
    if(sock < 0)
    {
        perror("socket");
        return 2;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    if(connect(sock,(struct sockaddr*)&server, sizeof(server)) < 0)
    {
        perror("connect");
        return 3;
    }

    printf("connect success ...\n");

    request_t r;
    response_t rp;
    for(;;) 
    {
        printf("Please Enter<x,y>: ");
        scanf("%d%d",&r.x,&r.y);
        printf("Please Enter Op<1[+] 2[-] 3[*] 4[/] 5[%]>:");
        scanf("%d",&r.op);

        write(sock, &r,sizeof(r));
        ssize_t _s = read(sock,&rp,sizeof(rp));
        if(_s > 0)
        {
            printf("status:%d\n result:%d\n",rp.status,rp.result);
        }
    }
    return 0;
}


























