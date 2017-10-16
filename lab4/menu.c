#include<stdio.h>
#include<stdlib.h>
#include"linktable.h"
#include<string.h>
#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

int Help();
int Quit();
int Add();

typedef struct DataNode
{
	tLinkTableNode *pNext;
	char *cmd;
	char *desc;
	int (*handler)();
	struct DataNode *next;
}tDataNode;

tDataNode *FindCmd(tLinkTable *head,char *cmd)
{
	tDataNode *pNode = (tDataNode*)GetLinkTableHead(head);
	while(pNode != NULL)
	{
		if(strcmp(pNode->cmd,cmd) == 0)
		{
			return pNode;
		}
		pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
	}
	return NULL;
}

int ShowAllCmd(tLinkTable *head)
{
	tDataNode *pNode = (tDataNode*)GetLinkTableHead(head);
	while(pNode != NULL)
	{
		printf("%s - %s\n",pNode->cmd,pNode->desc);
		pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
	}
	return 0;
}

int InitMenuData(tLinkTable **ppLinkTable)
{
	*ppLinkTable=CreateLinkTable();
	tDataNode *pNode = (tDataNode*)malloc(sizeof(tDataNode));
	pNode->cmd="help";
	pNode->desc="this is help command!";
	pNode->handler=Help;
	AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pNode);
	pNode = (tDataNode*)malloc(sizeof(tDataNode));
	pNode->cmd="quit";
	pNode->desc="this is quit command!";
	pNode->handler=Quit;
	AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pNode);
	pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="add";
    pNode->desc="this is add command!";
    pNode->handler=Add;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pNode);
	return 0;
}
tLinkTable *head = NULL;

int main()
{
	InitMenuData(&head);
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

int Add()
{
	int m,n,r;
	printf("Please input two numbers:");
	scanf("%d",&m);
	scanf("%d",&n);
	r=m+n;
	printf("the answer is %d\n",r);
	return 0;
}
