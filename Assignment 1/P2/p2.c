#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>

void child(int n, int fd[]) {
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL); // records the start and end times
    sleep(rand() % 5 + 1);
    gettimeofday(&end_time, NULL);
    write(fd[1], &start_time, sizeof(start_time));
    write(fd[1], &end_time, sizeof(end_time));
    printf("Child %d executed in %.2f millis\n", n+1, (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec) / 1000.0);
    exit(0);
}

// create a pipe for each child process and forks a new process for each child
int main(int argc, char *argv[]) {
    int num_children = atoi(argv[1]);
    int fd[num_children][2];
    pid_t pid[num_children];
    double max = 0.0, min = 1e9, sum = 0, avg; //execution times are stored in these variables
    srand(time(NULL));

    for (int i = 0; i < num_children; i++) {
        if (pipe(fd[i]) < 0) {
            printf("Error occured!");
            return 1;
        }
// another process, if pid equals 0, close the end of pipe
        pid[i] = fork();
        if (pid[i] == 0) {
            close(fd[i][0]);
            child(i, fd[i]);
        }
        else {
            close(fd[i][1]);
        }
    }
// parent process waits for all child processes to finish and reads the start-end times from the pipe for each child

    for (int i = 0; i < num_children; i++) {
        waitpid(pid[i], NULL, 0);
        struct timeval start_time, end_time;
        read(fd[i][0], &start_time, sizeof(start_time));
        read(fd[i][0], &end_time, sizeof(end_time));
        double runtime = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec) / 1000.0;
        if (runtime > max){
            max = runtime;
        }
        if (runtime < min) {
            min = runtime;
        }
        sum += runtime;
        printf("Child %d execution time: %.2f millis\n", i+1, runtime);
        close(fd[i][0]); // close read end of pipe
    }
//printing stored and calculated variables
    avg = sum / num_children;
    printf("Max execution time: %.2f millis\n", max);
    printf("Min execution time: %.2f millis\n", min);
    printf("Average execution time: %.2f millis\n", avg);

    return 0;
}

