#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#define MSGKEY 75

struct msgform
{
   long mtype;
   char mtext[256];
};

void main()
{
   struct msgform msg;
   int msgqid,pid,*pint;
   msgqid=msgget(MSGKEY,0777);
   pid=getpid();
   pint=(int*)msg.mtext;
   *pint=pid;
   msgsnd(msgqid,&msg,sizeof(int),0);
   msgrcv(msgqid,&msg,256,pid,0);
   printf("client: receive from pid %d\n",*pint);
}
