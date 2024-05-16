#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int ret1,ret2,ret3,ret4,ret5,child_pid,s;
	ret1=fork();
	if(ret1==0)
	{
		for(int i=0;i<5;i++)
		{
			printf("Process ID: %d and count: %d\n",getpid(),i);
		}
		_exit(0);
	}
	ret2=fork();
	if(ret2==0)
	{
		for(int i=0;i<5;i++)
		{
			printf("Process ID: %d and count: %d\n",getpid(),i);
		}
		_exit(0);
	}
	ret3=fork();
	if(ret3==0)
	{
		for(int i=0;i<5;i++)
		{
			printf("Process ID: %d and count: %d\n",getpid(),i);
		}
		_exit(0);
	}
	ret4=fork();
	if(ret4==0)
	{
		for(int i=0;i<5;i++)
		{
			printf("Process ID: %d and count: %d\n",getpid(),i);
		}
		_exit(0);
	}
	ret5=fork();
	if(ret5==0)
	{
		for(int i=0;i<5;i++)
		{
			printf("Process ID: %d and count: %d\n",getpid(),i);
		}
		_exit(0);
	}
	for(int i=1;i<=5;i++)
	{
		child_pid = wait(&s);
		printf("Child exiting PID: %d and status: %d\n",child_pid,WEXITSTATUS(s));
	}
}
