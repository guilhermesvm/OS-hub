#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>

int main(int argc, char **argv){     
    int x = 1;
    pid_t pid; 

    pid = fork();
  	if (pid < 0) {
        printf("Erro na criação do fork\n");
        exit(1);
    }
    if (pid == 0){
    	++x; 
        printf("Filho tem x = %d. Endereço de x no filho %p\n", x, &x); 
        exit(2);
    }
    else{
    	printf("Pai vai dormir 1 segundo\n"); 
    	sleep(1);
    	--x;
        printf("Pai  tem x = %d. Endereço de x no filho %p\n", x, &x);         
    }
} 
