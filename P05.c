//Question: Write a program to show attaching and detaching shared memory.
// Note: I do hereby declare that I'll be not responsible if the program fails to run properly.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
    int i;
    void *shared_memory;
    char buff[100];
    int shmid;
    shmid=shmget((key_t)2345, 1024, 0666|IPC_CREAT);

    printf("Key of shared memory is %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);

    printf("Process attached at %p\n",shared_memory);

    printf("Enter some data to write to shared memory\n");
    read(0,buff,100);//get some input from user  
    strcpy(shared_memory,buff);//data written to shared memory  
    printf("You wrote : %s\n",(char *)shared_memory);
    
    shmdt(shared_memory);
    printf("\nProcess detached");
}