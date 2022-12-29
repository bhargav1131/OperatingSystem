// Question: Write a program to create a child process that starts looping and then terminates.
// Note: I do hereby declare that I'll be not responsible if the program fails to run properly.

#include<stdio.h>
#include <stdlib.h>

int main()
{
	for(int i=0;i<5;i++) // loop will run n times (n=5)
	{
		if(fork() == 0)
		{
			printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
			exit(0);
		}
	}
	for(int i=0;i<5;i++) // loop will run n times (n=5)
	wait(NULL);
	
}
