#include <stdio.h> 
#include <unistd.h> 

int main(){  
    fork(); 
    fork(); 
    fork(); 
  
    printf("Hello world!\n"); 
    return 0; 
} 
