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

    if(pid > 0){
        printf("P3\n"); //Sou o processo pai
        waitpid(pid, &status, 0); // espera pelo filho
        printf("P5\n");
    } 
    else if (pid == 0){
        printf("P4\n"); //Sou o processo filho, criado pelo fork
    }

    return 0;
}