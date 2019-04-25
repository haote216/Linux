#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<pthread.h>
using namespace std;

void *tfn(void *arg)
{
    printf("thread: pid = %d, tid = %lu\n", getpid(), pthread_self());
    return NULL;
}

int main()
{
    pthread_t tid;
    
    int ret = pthread_create(&tid, NULL, tfn, NULL);
    if(ret != 0)
    {
        cout << "pthread_create error " <<endl;
    }
    printf("main: pid = %d, tid = %lu\n", getpid(), pthread_self());
    sleep(1);
    return 0;
}
