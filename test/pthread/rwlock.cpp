#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
using namespace std;

int number = 100;
pthread_rwlock_t lock;
void* writefunc(void *arg)
{
    while(1)
    {
        pthread_rwlock_wrlock(&lock);
        number++;
        printf("write pthread: %lu %d\n",pthread_self(),number);
        pthread_rwlock_unlock(&lock);
        usleep(500);
    }
    return NULL;
}

void* readfunc(void *arg)
{
    while(1)
    {
        pthread_rwlock_wrlock(&lock);
        printf("read pthread: %lu %d\n",pthread_self(),number);
        pthread_rwlock_unlock(&lock);
        usleep(500);
    }
    return NULL;
}

int main()
{
    pthread_t p[8];
    pthread_rwlock_init(&lock, NULL);

    for(int i = 0;i<3;++i)
    {
        pthread_create(&p[i], NULL, writefunc, NULL);
    }

    for(int i =3;i<8;++i)
    {
        pthread_create(&p[i], NULL, readfunc, NULL);
    }

    for(int i = 0; i <8; ++i)
    {
        pthread_join(p[i], NULL);
    }
    pthread_rwlock_destroy(&lock);
    return 0;
}
