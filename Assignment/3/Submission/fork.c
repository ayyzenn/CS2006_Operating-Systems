/* fork: create a new process */
#include <stdlib.h> /* needed to define exit() */
#include <unistd.h> /* needed for fork() */
#include <sys/wait.h> /* needed for wait() */
#include <stdio.h> /* needed for printf() */
int main(int argc, char **argv) 
{
    int pid; /* process ID */
    pid = fork();

    if (pid == -1) 
    {
        perror("Error");
    }

    if (pid == 0)
    {
        printf("In child.\n");
        printf("Child ID: %d\n", getpid());
    }
    else
    {
        printf("In parent.\n");
        printf("Child ID: %d\n", getpid());
        printf("Parent ID: %d\n", getppid());
    }
    
    sleep(1);
    exit(0);
}