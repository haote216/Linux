#include<iostream>
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
using namespace std;

#define MAX 10000

int number = 0;
pthread_mutex_t mutex;

void *funA(void *arg)
{
    for(int i = 0;i<MAX;++i)
    {
        pthread_mutex_lock(&mutex);
        int cur = number;
        cur++;
        number = cur;
        printf("pthread A,id = %lu,number = %d\n",pthread_self(),number);
        pthread_mutex_unlock(&mutex);
        usleep(10);
    }
    return NULL;
}

void *funB(void *arg)
{
    for(int i = 0;i<MAX;++i)
    {
        pthread_mutex_lock(&mutex);
        int cur = number;
        cur++;
        number = cur;
        printf("pthread B,id = %lu,number = %d\n",pthread_self(),number);    
        pthread_mutex_unlock(&mutex);
        usleep(10);
    }  
    return NULL;
}

int main()
{
    pthread_t tid1,tid2;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&tid1, NULL, funA, NULL);
    pthread_create(&tid2, NULL, funB, NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    pthread_mutex_destroy(&mutex);
    
    return 0;
}
