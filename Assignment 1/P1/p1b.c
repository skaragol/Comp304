#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

// Fork process starts
    pid_t pid = fork();

// there is a error when pid is smaller than 0
    if (pid == -1) { 
        printf("Fork failed!");
        exit(1);

    } else if (pid == 0) {
// when pid equals to 0, child process
	printf("Child process executing.");
        exit(0);

    } else {
//parent process
//zombie process must remain in the system for at least 5 seconds
	printf("Parent process executing.");
	printf("Zombie process created.\n");
	sleep(5);

    }
    return 0;
}