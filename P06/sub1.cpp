// Note: I do hereby declare that I'll be not responsible if the program fails to run properly.

#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

using namespace std;
int main() {

   key_t my_key = ftok("shmfile",65); // used to generate unique key
   int shmid = shmget(my_key,1024,0666|IPC_CREAT); // It returns an id in shmid
   char *str = (char*) shmat(shmid,(void*)0,0); // shmat to attach to shared memory
   cout<<"Write Data : ";
   fgets(str, 50, stdin);
   printf("Data written in memory: %s\n",str);
   shmdt(str); // to detach from the shared memory
}