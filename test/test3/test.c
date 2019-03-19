#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
int g_val = 100;
//int main()
//{
    //pid_t id =fork();
    //if(id == 0)
    //{
    //    g_val = 300;
    //    printf("i am child ,pid is: %d %d %p\n",getpid(),g_val,&g_val);
    //    sleep(2);
    //}
    //else if(id >0)
    //{
    //    sleep(3);
    //    printf("i am parent ,pid is: %d %d %p\n",getpid(),g_val,&g_val);
    //}
    //return 0;
//}
//int main()
//{
//   printf("I am a proc!");
//    sleep(1);
//    exit(22);
//}
int main()
{
    pid_t id = fork();
    if (id == 0)
    {
        //child
        printf("hello I am child\n");
        sleep(3);
        exit(1);
    }
    else{
        //parent
        sleep(5);
        pid_t ret = wait(NULL);
        printf("wait success,ret is : %d\n",ret);
        sleep(5);
    }
}
