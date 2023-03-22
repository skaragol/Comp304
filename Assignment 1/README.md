P1: FORKS
In Unix/Linux, new processes can be created using the fork() system call. 
Calling fork() creates a copy of calling process and the new process starts executing immediately. 
After the fork() call, both parent and child processes start executing the same code.

P2: PIPES
Rather than duplicating the parent process, we can create a new process for the children to execute 
using the exec() family of calls, which the parent can monitor. In this part you will write a simple 
benchmarking program that measures how long programs take to execute.
C program that forks n child processes simultaneously, each executing a given
command name concurrently.

P3: SHARED MEMORY
A program to search for a given number in a sequence
using multiple processes.
• The parent process reads a newline-delimited sequence of at most 1000 numbers from
stdin and parses them into an array.
• The parent creates n child processes that go through disjoint portions of the array to
search a given number x. Both n and x are provided as command-line arguments. For
example, the program should search for the number 98 with 3 children if invoked as
follows: $ ./search 98 3
• Each forked child must sequentially search for x in their portion of the array, and print
the index of the element and exit with the return code 0 if found. If a child does not
find the given number in its portion, it should instead exit with the return code 1.
• When any child exits with a success the parent should kill other running children and
terminate
