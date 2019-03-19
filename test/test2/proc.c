#include<stdio.h>
#include<unistd.h>
int main()
{
    int i=0;
    char bar[102]={0};
    const char* lable="|/-\\";
    while(i <= 100)
    {
        bar[i]='#';
        printf("[%-100s][%d%%][%c]\r",bar,i,lable[i%4]);
        fflush(stdout);
        i++;
        usleep(50000);
    }
    return 0;
}
