// Note: I do hereby declare that I'll be not responsible if the program fails to run properly.

#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

using namespace std;

int main() {
   key_t my_key = ftok("shmfile",65); //used to generate unique key
   int shmid = shmget(my_key,1024,0666|IPC_CREAT); // shmget returns an id in shmid
   char *str = (char*) shmat(shmid,(void*)0,0); // to attach the process to shared memory
   printf("Data read from memory: %s\n",str);
   shmdt(str);
   shmctl(shmid,IPC_RMID,NULL); // to deallocate the shared memory
}