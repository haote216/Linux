#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
/*
int main()
{
    FILE *fp=fopen("myfile","w");
    if(!fp)
    {
        printf("fopen error!\n");
    }
    const char *msg = "hello bit!\n";
    int count =5;
    while(count--)
    {
        fwrite(msg,strlen(msg),1,fp);
    }
    fclose(fp);
    return 0;
}*/


/*
int main()
{
    FILE *fp=fopen("myfile","r");
    if(!fp)
    {
        printf("fopen error!\n");
    }
    char buf[1024];
    const char *msg = "hello bit!\n";

    while(1)
    {
        ssize_t s=fread(buf,1,strlen(msg),fp);
        if(s > 0)
        {
            buf[s]=0;
            printf("%s",buf);
        }
        if(feof(fp))
        {
            break;
        }
    }
    fclose(fp);
    return 0;
}*/
/*
int main()
{
    const char* msg ="hello fwrite\n";
    fwrite(msg,strlen(msg),1,stdout);

    printf("hello printf\n");
    fprintf(stdout,"hello fprintf\n");
    return 0;
}*/
/*
int main()
{
    umask(0);
    int fd = open("myfile.txt",O_WRONLY | O_CREAT,0644);
    if(fd < 0){
        printf("open error!\n");
        return 1;
    }
    const char *msg = "hello bit\n";
    int i =0;
    while(i < 10){
        write(fd,msg,strlen(msg));
        i++;
    }
    close(fd);
    return 0;
}*/
/*int main()
{
    close(1);
    umask(0);
    int fd = open("myfile.txt",O_WRONLY | O_CREAT,0644);
    if(fd < 0){
        printf("open error!\n");
        return 1;
    }
    int i= 0;
    while(i<10){
        i++;
        printf("hello bit\n");
        fflush(stdout);
    }
    close(fd);
    return 0;
}*/
/*int main()
{
    close(1);
    umask(0);
    int fd = open("myfile.txt",O_WRONLY | O_APPEND);
    if(fd < 0){
        printf("open error!\n");
        return 1;
    }
    int i=0;
    fprintf(stderr,"%d\n",fd);
    while(1){
        //i++;
        fprintf(stdout, "hello haote!\n");
        //write(fd, "hello world!\n", 13);
        // fflush(stdout);
    }
    close(fd);
    return 0;

}*/
/*int main()
{
    //close(1);
    const char *msg0="hello printf\n";
    const char *msg1="hello fwrite\n";
    const char *msg2="hello write\n";

    printf(msg0);
    fwrite(msg1,1,strlen(msg1),stdout);
    write(1,msg2,strlen(msg2));
    
    fork();
    return 0;
}*/
