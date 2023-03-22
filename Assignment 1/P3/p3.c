#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Enter a number: %s <number> <n>\n", argv[0]);
        exit(1);
    }

    int x = atoi(argv[1]);
    int n = atoi(argv[2]);

// reads list of integers from input
    int numbers[1000];
    int num_count = 0;
    int num;

// reads integers from standard input and divides the input array into n chunks
// search for number in list 
    while (scanf("%d", &num) == 1 && num_count < 1000) {
        numbers[num_count++] = num;
    }

    int segment_size = num_count / n;
    int remaining_size = num_count % n;

// child process starts
// print the index of the element and exit with the return code 0 if found
    for (int i = 0; i < n; i++) {
        int start = i * segment_size;
        int end = start + segment_size + (i == n - 1 ? remaining_size : 0);
        if (fork() == 0) {
            for (int j = start; j < end; j++) {
                if (numbers[j] == x) {
                    printf("Found at: %d\n", j);
                    exit(0);
                }
            }
            exit(1);
        }
    }

// child processes ends when number is found in one of the seperated list
    int status;
    for (int i = 0; i < n; i++) {
        wait(&status);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            for (int j = i + 1; j < n; j++) {
// child processes must killed cause number is found
                kill(0, SIGTERM);
            }
            printf("Number found! \n");
            exit(0);
        }
    }

// if number not found exit with returning 1 and exit
    printf("Error: number not found.\n");
    exit(0);
    return 0;
}
