# CSCE-4600-Adding-Random-Numbers-Using-Processes

A program which adds 100 random numbers together and prints the result using  multiple child processes.

                        The Child Program
Each random number will be created by a child process (a separate program) and returned as the exit status. 

Create a child program that generates a random number between 1 and 100 (inclusive).
If you are using C++, you might consider std::mt19937
This is a Mersenne Twister which generates 32-bit numbers with a state size of 19937 bytes.
See: https://en.wikipedia.org/wiki/Mersenne_TwisterLinks to an external site.
Your program should introduce a delay within a random interval of 200-600 microseconds.
You may utilize usleep(3) for this delay.
Your program will return the generated number as the exit status from the main() function.
You can return this value.
You can also pass it as a parameter to exit(2)
You can test your program by running it from the shell.
Echo ‘$?’ in the shell to display the exit status of the last executed program.
                      The Parent Program
The parent program will create 100 child processes, each running the program created above.

You must create all 100 processes before doing anything else.
The fork(2) and execve(2) system calls should be used.
After creating ALL of the child processes, the parent program will wait for each child to exit.
Your children will exit in a random order.
Use the wait(2) system call to obtain the exit status.
Add this to your running total.
Keep track of how many children are still running (or how many have exited)
After ALL of the child processes have exited, print out the sum of their generated values.
