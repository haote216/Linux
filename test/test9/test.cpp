#include<iostream>
#include<unistd.h>
#include<signal.h>
using namespace std;
/*int count = 1;
void show(sigset_t *const &pending)
{
    int i=1;
    for(;i <= 31; i++)
    {
        if(sigismember(pending , i))
        {
            cout << "1";
        }
        else 
        {
            cout << "0";
        }
    }
    cout << endl;
}
int main()
{
    alarm(1);
    while(1)
    {
        cout << count++ <<endl;
    }

    sigset_t set;
    sigset_t oset;
    sigset_t pending;
    sigemptyset(&set);
    sigemptyset(&oset);
    sigemptyset(&pending);
    sigaddset(&set,2);
    sigprocmask(SIG_SETMASK,&set,&oset);  //读取或更改进程的信号屏蔽字，这里是更改。设置当前信号屏蔽字为
                                          //set所指向的值。
    while(1)
    {
        sigpending(&pending);
        show(&pending);
        sleep(1);
    }
    return 0;

}*/

/*void handler(int signo)
{
    cout << "catch a sig :" << signo <<endl;
}
int main()
{
    struct sigaction act,oact;
    act.sa_handler = SIG_DFL;
    sigemptyset(&act.sa_mask);

    sigaction(2,&act,&oact);
    int ret = pause();
    cout << ret << endl;
    //while(1)
    //{
    //    cout << "hello world" << endl;
    //    sleep(1);
    //}
    return 0;
}*/

void handler(int signo)
{

}
int MySleep(int sec)
{
    struct sigaction act, oact;
    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);
    sigaction(SIGALRM ,&act, &oact);

    alarm(sec);
    pause();
    
    int ret = alarm(0);
    sigaction(SIGALRM, &oact, NULL);

    return ret;
}

int main()
{
    while(1)
    {
        MySleep(1);
        cout << "Wake up..." << endl;
    }
    return 0;
}

