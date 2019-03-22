#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

#define MAX 1024
#define NUM 16

int main()
{
    char *myargv[NUM];
    char cmd[MAX];
    while(1)
    {
        printf("[bit@localhost myshell]# ");
        fgets(cmd,sizeof(cmd),stdin);
        cmd[strlen(cmd)-1]='\0';
        //scanf("%s",cmd);
        int i=0;
        myargv[i++]=strtok(cmd," ");
        char *ret=NULL;
        while(ret = strtok(NULL," "))
        {
            myargv[i++]=ret;
        }
        myargv[i]= NULL;
        pid_t id =fork();
        if(id == 0){//child
            execvp(myargv[0],myargv);
            exit(1);
        }
        else{//parent
            waitpid(id,NULL,0);
        }
    }
    /*int j=0;
    for(;j<i;j++)
    {
        printf("%s\n",myargv[j]);
    }
    */

    return 0;
}
