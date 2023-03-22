p1a: C program that calls fork() n times consecutively where n is an integer parameter
provided as a command-line argument. Then each of the forked processes prints its ID, its
parent’s ID and its level in the process tree (The level of the main process is 0).

p1b:  C program that forks a child process that immediately becomes a zombie process.
This zombie process must remain in the system for at least 5 seconds.
• Use the sleep() call for the time requirement
• Run the program in the background (using the & feature of your shell) and then run
the command ps − l to see if the child has become a zombie.
• Kill the parent with the kill command if you create too many zombie processes.
• Provide the source code and screenshots of the ps command
