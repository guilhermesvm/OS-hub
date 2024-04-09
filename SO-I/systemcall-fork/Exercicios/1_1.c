#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>

int main(int agrc, char* argv[]){
    int status;

    printf("P1\n");
    printf("P2\n");

    pid_t pid = fork();

    if(pid==0){
        printf("P4\n");
        exit(0);
    }

    printf("P3\n");
    waitpid(pid, &status, 0);
    printf("P5\n");

    return 0;
}