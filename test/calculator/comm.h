#ifndef _COMM_H_
#define _COMM_H_ 


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<pthread.h>

typedef struct request{
    int x;
    int y;
    int op; //1 2 3 4 5
}request_t;

typedef struct response{
    int status;
    int result;
}response_t;


#endif
