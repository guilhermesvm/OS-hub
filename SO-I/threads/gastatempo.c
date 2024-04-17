#include <stdio.h>
#include <time.h> 

#define A 501
#define B 613 
#define C 707
#define LACO1 600
#define LACO2 5000000
    
int main (int argc, char **argv){   
    int i, j;
    long sum;
    time_t tpi, tpf; 

    printf ("Simulação de um processamento qualquer ... \n");

    time(&tpi);
    for (j = 0; j < LACO1; j++ ) { // apenas para simular tempo de processamento
        for (i =0; i < LACO2; i++) {
            sum = A * i + B * i * i + C;
            sum %= 543;
        }
        if (j % 100 == 0){
        	time(&tpf);
        	printf("Valor parcial de j: %d transcorrido %lds\n", j, (long)tpf-tpi);
        }
    }
    time(&tpf);
    printf("Loops demoraram %lds\n", (long)tpf-tpi);

    return (0);
}