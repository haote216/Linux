#include"comm.h"
static int CommGetMsgQueue(int flag)
{
    key_t k = ftok(PATHNAME,PROJID);
    if(k < 0){
        printf("ftok error!\n");
        return -1;
    }
    int msgid = msgget(k,flag);
    if(msgid < 0){
        printf("msgget error!\n");
    }
    return msgid;
}
int CreatMsgQueue()
{
    return CommGetMsgQueue(IPC_CREAT | IPC_EXCL | 0666);
}

int OpenMsgQueue()
{
    return CommGetMsgQueue(IPC_CREAT);
}

void SendMsg(int msgid,char msg[],int type)
{
    struct msgbuf _msg;
    _msg.mtype = type;
    strcpy(_msg.mtext, msg);
    if(msgsnd(msgid,(void*)&_msg,sizeof(_msg.mtext),0) < 0){
        printf("msgsnd error!\n");
    }
}

void RecvMsg(int msgid,char msg[],int type)
{
    struct msgbuf _msg;
    if(msgrcv(msgid, &_msg, sizeof(_msg.mtext),type,0) > 0)
    {
        strcpy(msg,_msg.mtext);
    }
}

void DestroyMsgQueue(int msgid)
{
    msgctl(msgid,IPC_RMID,NULL);
}
