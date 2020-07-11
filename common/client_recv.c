/*************************************************************************
	> File Name: client_recv.c
	> Author:pujunsong 
	> Mail:2724967607@qq.com 
	> Created Time: Fri 10 Jul 2020 07:49:46 PM CST
 ************************************************************************/

#include "head.h"
extern int sockfd;


void *do_recv(void *arg) {
    while (1){
        struct ChatMsg msg;
        bzero(&msg, sizeof(msg));
        int ret =recv(sockfd, (void *)&msg, sizeof(msg), 0);
       // strcpy(msg.name,"pujunsong");
        if(msg.type & CHAT_WALL){
          //  printf("%s你好\n",msg.name);
            printf(""BLUE"%s"NONE" :%s\n",msg.name,msg.msg);
        }else if (msg.type&CHAT_MSG) {
            printf(""RED"%s"NONE" :%s\n",msg.name,msg.msg);
        } else if (msg.type & CHAT_SYS) {
            printf(YELLOW"Server Info"NONE" : %s\n", msg.msg);
        } else if (msg.type & CHAT_FIN) {
            printf(L_RED"Server Info"NONE"Server Down!\n");
            exit(1);
        }
    }
}

