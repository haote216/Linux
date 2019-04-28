#include<iostream>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct thrd {
    int var;
    char str[256];
};

void *tfn(void *arg )
{
    struct thrd *tval;

    tval =(thrd *)malloc(sizeof(tval));

    tval->var = 110;
    strcpy(tval->str, "hello thread");
    return (void *)tval;
}

int main()
{
    pthread_t tid;
    struct thrd *retval;

    int ret = pthread_create(&tid, NULL, tfn, NULL);
    if(ret != 0)
        printf("create error");

    ret = pthread_join(tid, (void **)&retval);
    if(ret != 0)
        printf("pthread_join error");

    printf("child pthread exit with var = %d, str = %s\n",retval->var, retval->str);
    pthread_exit(NULL);
    return 0;
}
