#include<iostream>
#include<signal.h>
#include<unistd.h>

using namespace std;
void handler(int signo)
{

}
int MySleep(int sec)
{
    struct sigaction act,oact;
    act.sa_handler=handler;
    sigemptyset(&act.sa_mask);

    sigaction(SIGALRM,&act,&oact);
    
    alarm(sec);
    pause();
    
    int ret = alarm(0);
    sigaction(SIGALRM,&oact,NULL);
    
    return ret;
}
int main()
{
    while(1){
        MySleep(1);
        cout << "wake up... " << endl;
    }
    return 0;
}
