//Criar um programa que informa o pid dele próprio na saída padrão.

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>



int main(void){
    pid_t pid = getpid();

    //printf("O PID do processo é: %i\n", (int) pid);

    char message[50];
    sprintf(message, "O PID do processo eh %d\n", (int) pid);

    write(1, message, strlen(message));
    return 0;
}   