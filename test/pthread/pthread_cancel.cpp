#include<iostream>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

using namespace std;


void *tfn(void * arg)
{
    while(1)
    {
        printf("pthread: pid = %d,tid = %lu\n",getpid(),pthread_self());
        sleep(1);
    }
}

int main()
{
    pthread_t tid;
    struct thrd *retval;

    int ret = pthread_create(&tid, NULL, tfn, NULL);
    if(ret != 0)
        printf("create error");
    printf("main pthread:pid = %d,tid = %lu\n",getpid(),pthread_self());
    sleep(5);

    ret = pthread_cancel(tid);
    if(ret != 0)
        printf("cancel error");
    pthread_exit(NULL);
    return 0;
}
