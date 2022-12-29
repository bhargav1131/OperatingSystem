// Question: Write a program to show that a process can ignore a signal.
// Note: I do hereby declare that I'll be not responsible if the program fails to run properly.

#include <signal.h>
#include <stdio.h>
#include<unistd.h>

int main(void) {
// catch SIGINT which is sent if user types cntrl-d
struct sigaction action = {.sa_handler = SIG_IGN};
sigaction(SIGINT, &action, NULL);

while (1) {
    printf("Can't interrupt me, I'm ignoring ctrl-C\n");
    sleep(1);
    }
}
