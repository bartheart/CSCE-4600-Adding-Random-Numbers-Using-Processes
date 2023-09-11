#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>


int randomGenerator() {
    //seed the random generator
    srandom(time(NULL));

    //random number between 1 and 100
    int randomNumber = rand() % 100 + 1; 

    //generate a random delay b/n 200 and 600 
    int delayMicroSeconds = 200 + (rand() % 401);
    usleep(delayMicroSeconds);

    return randomNumber;
}

int main() {
    int total = 0;
    int childCount = 100;
    
    //create a 100 child processess
    for (int i = 0; i < childCount; i++) {
        pid_t child_pid = fork();

        //error handling
        if (child_pid < 0) {
            perror("Fork failed\n");
            return 1;
        }

        if (child_pid == 0) {
            //child process
            int randomNumber = randomGenerator();
            exit(randomNumber);
        }
    }

    //parent process to wait on all child processess to exit
    while (childCount > 0) {
        int status;

        //wait call 
        pid_t exitedPid = wait(&status);

        if (exitedPid < 0) {
            perror("Wait failed\n");
            return 1;
        }

        //check normal exit status of the child
        if (WIFEXITED(status)) {
            int randomNumber = WEXITSTATUS(status);
            printf("Child %d exited with random number: %d\n", exitedPid, randomNumber);
            //total sum accumulator
            total += randomNumber;
        }

        else{
            fprintf(stderr, "Child %d did not exit normally.\n", exitedPid);
        }
        //decrement child count
        childCount --;
    }

    //output the final sum value 
    printf("The total sum of random 100 numbers is: %d\n", total);

    return 0;
}
