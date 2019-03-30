#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    int fds[2];
    if(pipe(fds)<0){
        printf("pipe error!\n");
        return 1;
    }
    pid_t id =fork();
    if(id == 0){
        //child  w
        close(fds[0]);
        const char *str="I am a child,my math is 100!\n";
        int i=0;
        while(1){
            write(fds[1],str,strlen(str));
            printf("child write done...!:%d\n",i++);
        }
        close(fds[1]);
        exit(0);
    }
    else{
        //parent  r
        close(fds[1]);
        char buf[1024];
        sleep(3);
        close(fds[0]);
        int status = 0;
        waitpid(id,&status,0);
        printf("%d\n",status&0x7F);
        /*while(1){
            ssize_t s = read(fds[0],buf,sizeof(buf)-1);
            if(s > 0){
                buf[s]=0;
                printf("father recv done: %s",buf);
            }
            else if(s == 0){
                printf("child quit! father quit too");
                break;
            }
            else{

            }
        }*/
        return 0;
    }
}
