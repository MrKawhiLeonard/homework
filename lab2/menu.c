#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void CmdHelp()
{
	printf("this is help command.\n");
	printf("command lists:hello,max,help,min,ls,pwd,quit,date\n");
}

void CmdHello()
{
	printf("this is hello command.\n");
}
void CmdMax()
{
	printf("This is max command.\n");
}
void CmdMin()
{
	printf("This is min command.\n");
}

int main()
{
	char cmd[128];
	while(1)
	{
		scanf("%s",cmd);
		if(strcmp(cmd,"help")==0)
		{
			CmdHelp();	
		}
		else if(strcmp(cmd,"hello")==0)
		{
			CmdHello();
		}
		else if(strcmp(cmd,"pwd")==0)
		{
			system(cmd);
		}
		else if(strcmp(cmd,"quit")==0)
		{
			exit(0);
		}
		else if(strcmp(cmd,"date")==0)
		{
			system(cmd);
		}
		else if(strcmp(cmd,"ls")==0)
		{
			system(cmd);
		}
		else if(strcmp(cmd,"max")==0)
		{
			CmdMax();
		}
		else if(strcmp(cmd,"min")==0)
		{
			CmdMin();
		}
		else
		{
			printf("Your command is undefined,please re-enter!");
		}
	}
}
