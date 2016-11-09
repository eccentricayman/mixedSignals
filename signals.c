#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/**********************************************************************************************/
/* Runs constantly inside a forever while loop.                                               */
/* Print out the process' PID inside the loop.                                                */
/* Use the sleep(1) function to have the program wait 1 second between inner loop iterations. */
/* Catch the following signals                                                                */
/* SIGINT                                                                                     */
/* -Before exiting,append a message to a file noting that the program exited due to SIGINT    */
/* -To make your program quit,look up the exit function.                                      */
/* SIGUSR1                                                                                    */
/* -Print out the PID of the parent process.                                                  */
/* -Should not cause the program to exit.                                                     */
/**********************************************************************************************/

static void sighandler(int signo) {
    
    if (signo == SIGINT) {
        printf("\nProgram interrupted, because you're a rude person. (SIGINT) \n");
        exit(0);
    }
    if (signo == SIGUSR1) {
        printf("PID: %d \n", getpid());
    }
    
}

int main() {

    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    
    //just to make sure the program hasn't frozen
    int ctr = 1;

    while (ctr) {
        printf("Iteration %d - PID: %d \n", ctr, getpid());
        ctr++;
        sleep(1);
    }
    
}
