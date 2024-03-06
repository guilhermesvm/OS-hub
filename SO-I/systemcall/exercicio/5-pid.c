//Criar um programa que informa o pid dele próprio na saída padrão.

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>



int main(void){
    pid_t pid = getpid();

    printf("O pid do programa é: %i\n", (int) pid);


    write(1, pid, strlen(pid));
}   