#include"comm.h"
int main()
{
    int msgid = CreatMsgQueue();
    printf("msgid is : %d\n",msgid);
    char *msg="hello msg queue!\n";
    SendMsg(msgid,msg,SERVER_TYPE);
    sleep(1);
    SendMsg(msgid,msg,SERVER_TYPE);
    sleep(1);
    SendMsg(msgid,msg,SERVER_TYPE);
    sleep(1);
    SendMsg(msgid,msg,SERVER_TYPE);
    sleep(1);
    SendMsg(msgid,msg,SERVER_TYPE);
    sleep(1);
    
    char buf[64];
    RecvMsg(msgid,buf,SERVER_TYPE);
    sleep(1);
    printf("%s\n",buf);
    RecvMsg(msgid,buf,SERVER_TYPE);
    sleep(1);
    printf("%s\n",buf);
    RecvMsg(msgid,buf,SERVER_TYPE);
    sleep(1);
    printf("%s\n",buf);
    RecvMsg(msgid,buf,SERVER_TYPE);
    sleep(1);
    printf("%s\n",buf);
    RecvMsg(msgid,buf,SERVER_TYPE);
    sleep(1);
    printf("%s\n",buf);
    DestroyMsgQueue(msgid);

    return 0;
}
