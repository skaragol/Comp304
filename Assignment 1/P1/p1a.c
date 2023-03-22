
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void print_process_info(int level) {
    printf("Process ID: %d, Parent ID: %d, Level: %d\n", getpid(), getppid(), level);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s n\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    int level = 0;
    print_process_info(level);

// calling fork, both parent and child processes start executing
    for (int i = 1; i <= n; i++) {
        pid_t pid = fork();

// there is a error when pid is smaller than 0
        if (pid < 0) {
            fprintf(stderr, "Fork failed\n");
            return 1;
        }
// if pid equals 0, child process
        else if (pid == 0) {
            level++;
            print_process_info(level);
        }
//if not parent process starts
        else {
            wait(NULL);
            break;
        }
    }

    return 0;
}