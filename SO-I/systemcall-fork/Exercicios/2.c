#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>

int main(int agrc, char* argv[]){
    int status;

    printf("S1\n");
    printf("S2\n");

    pid_t pid = fork();

    if(pid==0){
        printf("S4\n");

        pid_t pid3 = fork();

        if(pid3 ==0){
            printf("S8\n");
        }

        printf("S7\n");
        waitpid(pid3, &status, 0);
        printf("S10\n");
        printf("S11\n");
        exit(0);
    }

    printf("S3\n");

    pid_t pid2 = fork();
    if(pid2==0){
        printf("S6\n");
        exit(1);
    }

    printf("S5\n");

    waitpid(pid2, &status, 0);
    printf("S9\n");


    return 0;
}