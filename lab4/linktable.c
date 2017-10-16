#include<stdio.h>
#include<stdlib.h>
#include"linktable.h"

tLinkTable *CreateLinkTable()
{
	tLinkTable *pLinkTable = (tLinkTable*)malloc(sizeof(tLinkTable));
	pLinkTable->pHead = NULL;
	pLinkTable->SumOfNode = 0;
	return pLinkTable;
}

int DeleteLinkTable(tLinkTable *pLinkTable)
{
	if(pLinkTable == NULL)
	{
		return FAILURE;
	}
	if(pLinkTable->pHead == NULL)
	{
		free(pLinkTable);
		return SUCCESS;
	}
	tLinkTableNode *pNode = GetLinkTableHead(pLinkTable);
	tLinkTableNode *pTempNode;
	while(pNode)
	{
		pTempNode = pNode;
		pNode = GetNextLinkTableNode(pLinkTable,pNode);
		free(pNode);	
	}
	free(pNode);
	return SUCCESS;
}

int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode)
{
	if(pLinkTable == NULL || pNode == NULL)
	{
		return FAILURE;
	}
	if(pLinkTable->pHead == NULL)
	{
		pLinkTable->pHead = pNode;
		return SUCCESS;
	}
	tLinkTableNode *pTempNode = GetLinkTableHead(pLinkTable);
	while(pTempNode->pNext  != NULL)
	{
		pTempNode = pTempNode->pNext;
	}
	pTempNode->pNext = pNode;
	return SUCCESS;
}

int DeleteLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode)
{
	if(pLinkTable == NULL || pNode == NULL)
	{
		return FAILURE;
	}
	if(pLinkTable->pHead == NULL || pLinkTable->pHead ==pNode)
	{
		free(pLinkTable->pHead);
		return SUCCESS;
	}
	tLinkTableNode *ptrNode = GetLinkTableHead(pLinkTable);
	while(ptrNode->pNext != pNode)
	{
		ptrNode = ptrNode->pNext;
	}
	tLinkTableNode *pTempNode = ptrNode->pNext;
	ptrNode->pNext = pTempNode->pNext;
	free(pTempNode);
	return SUCCESS;
}

tLinkTableNode *GetLinkTableHead(tLinkTable *pLinkTable)
{
	if(pLinkTable == NULL || pLinkTable->pHead == NULL)
	{
		return NULL;
	}
	tLinkTableNode *pNode = pLinkTable->pHead;
	return pNode;
}

tLinkTableNode *GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode)
{
	if(pLinkTable == NULL || pLinkTable->pHead == NULL)
	{
		return NULL;
	}
	return pNode->pNext;
}
