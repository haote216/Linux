#include<iostream>
#include<stdio.h>
//   ./udp_server 192.x.x.x 8080
int main(int argc, char *argv[])
{
    if(argc != 3){
        printf("Usage: %s ip port\n", argv[0]);
        return 1;
    }
    return 0;
}
