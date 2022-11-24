#include <stdio.h>
#include "NumClass.h"
#include <stdlib.h>

int main(int argc, char *argv[]){
    int min = atoi(argv[1]);
    int max = atoi(argv[2]);
    
    if(min > max){
        int temp = min;
        min = max;     
        max = temp;
    }
    
    FILE *f;
    f = fopen (argv[3], "mode");
    
    fprintf(f, "The Armstrong numbers are:");
    for(int i = min; i <= max; i++){
        if(isArmstrong(i)){
            fprintf(f, " %d", i);
        }
    }

    fprintf(f, "\nThe Palindromes are:");
    for(int i = min; i <= max; i++){
        if(isPalindrome(i)){
            fprintf(f, " %d", i);
        }
    }   

    fprintf(f, "\nThe Prime numbers are:");
    for(int i = min; i <= max; i++){
        if(isPrime(i)){
            fprintf(f, " %d", i);
        }
    }    

    fprintf(f, "\nThe Strong numbers are:");
    for(int i = min; i <= max; i++){
        if(isStrong(i)){
            fprintf(f, " %d", i);
        }
    }

    return 1;
}
