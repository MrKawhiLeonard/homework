#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

int Help();
int Quit();

static tDataNode head[] =
{
	{"help","this is help cmd!",Help,&head[1]},
	{"version","this is version cmd!",NULL,&head[2]},
	{"quit","this is quit cmd!",Quit,NULL}
};

int main()
{
	while(1)
	{
		char cmd[CMD_MAX_LEN];
		printf("Input a cmd : ");
		scanf("%s",cmd);
		tDataNode *p = FindCmd(head,cmd);
		if(p == NULL)
		{
			printf("this is a wrong cmd!\n");
			continue;
		}
		if(p->handler != NULL)
		{
			p->handler();	
		}
	}
	return 0;
}

int Help()
{
	ShowAllCmd(head);
	return 0;
}

int Quit()
{
	exit(0);
}
