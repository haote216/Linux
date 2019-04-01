#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
int main()
{
    key_t k = ftok(".",0x7777);
    if(k < 0){
        printf("ftok error!\n");
        return 1;
    }
    int shmid = shmget(k,4096,IPC_CREAT|IPC_EXCL|0666);
    if(shmid < 0){
        printf("shmget error!\n");
    }

    char *buf=(char *) shmat(shmid,NULL,0);
    
    int i = 0;
    memset(buf,'\0',4096);
    while(i < 26)
    {
        sleep(1);
        buf[i] = 'A'+i;
        i++;
    }

    shmdt(buf);
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
}
