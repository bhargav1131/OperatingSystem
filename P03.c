// Question: Write a program to create a thread in which prints "We are proud to be Indians" and terminates
// Note: I do hereby declare that I'll be not responsible if the program fails to run properly.

#include <stdio.h>
#include <string.h>
#include <pthread.h>

// Global variable:
int i = 2;

void* foo(void* p){
  // Print value received as argument:
  printf("a thread has been created..\n");
  printf("We are proud to be Indians\n");
  // Return reference to global variable:
  pthread_exit(&i);
}

int main(void){
  // Declare variable for thread's ID:
  pthread_t id;

  int j = 1;
  pthread_create(&id, NULL, foo, &j);
    
  int* ptr;

  // Wait for foo() and retrieve value in ptr;
  pthread_join(id, (void**)&ptr);
}
