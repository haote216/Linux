#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>
using namespace std;
/*void hander(int signo)
{
    cout << "catch a sig , signo :"<< signo <<" pid: "<<getpid()<< endl;
}
int main(int argc,char *argv[])
{
    //kill(atoi(argv[1]),atoi(argv[2]));
    //signal(6,hander);
    //abort();
    while(1){
        raise(2);
        sleep(1);
    }
    



    //signal(SIGFPE,hander);
    int i =0;
    while(1)
    {
        ++i;
        if( i == 5 ){
            i /= 0;
        }

        cout << "hello world ,pid :" << getpid() << endl;
    }
    return 0;
}*/
void handler(int signo)
{
    cout << "catch a sig : " << signo << endl;
}
int main()
{
    struct sigaction act, oact;
    act.sa_handler = SIG_DFL;
    sigemptyset(&act.sa_mask);
    sigaction(2,&act,&oact);
    int ret = pause();
    cout << ret <<endl;
    /*while(1)
    {
        cout <<" hello world " << endl;
        sleep(1);
    }*/
    return 0;
}
