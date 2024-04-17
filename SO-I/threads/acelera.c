#include <stdio.h>
#include <time.h> 
#include <pthread.h>

#define A 501
#define B 613 
#define C 707
#define LACO1 600
#define LACO2 5000000

void *calcula(void *arg);
    
int main (int argc, char **argv){   
    int i, j;
    long sum;
    time_t tpi, tpf; 
    pthread_t thid;

    printf ("MAIN: Simulação de um processamento qualquer, com duas threads ... \n");
    pthread_create(&thid, NULL, calcula, NULL);
    printf ("MAIN: Criada thread para acelelar o processamento ... \n");

    time(&tpi);
    for (j = 0; j < LACO1/2; j++ ) { // apenas para simular tempo de processamento
        for (i =0; i < LACO2; i++) {
            sum = A * i + B * i * i + C;
            sum %= 543;
        }
        if (j % 100 == 0){
        	time(&tpf);
        	printf("MAIN: Valor parcial de j: %d transcorrido %lds\n", j, (long)tpf-tpi);
        }
    }
    pthread_join(thid, NULL);
    time(&tpf);
    printf("MAIN: Loops demoraram %lds\n", (long)tpf-tpi);

    return (0);
}

void *calcula(void *arg){
    int i, j;
    long sum;
    time_t tpi, tpf; 

    printf("THREAD: Vou ajudar a realizar o processamento ...\n");
    time(&tpi);
    for (j = LACO1/2; j < LACO1; j++ ) { // apenas para simular tempo de processamento
        for (i =0; i < LACO2; i++) {
            sum = A * i + B * i * i + C;
            sum %= 543;
        }
        if (j % 100 == 0){
        	time(&tpf);
        	printf("THREAD: Valor parcial de j: %d transcorrido %lds\n", j, (long)tpf-tpi);
        }
    }
    time(&tpf);
    printf("THREAD: Loops demoraram %lds\n", (long)tpf-tpi);
    return NULL;
}