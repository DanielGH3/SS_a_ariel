#include <stdio.h>
#include "NumClass.h"
#include <stdlib.h>

int main(int argc, char *argv[]){
    int min = 0;
    int max = 0;
    
    scanf("%d", &min);
    scanf("%d", &max);
    
    if(min > max){
        int temp = min;
        min = max;     
        max = temp;
    }
    
    printf("The Armstrong numbers are:");
    for(int i = min; i <= max; i++){
        if(isArmstrong(i)){
            printf(" %d", i);
        }
    }

    printf("\nThe Palindromes are:");
    for(int i = min; i <= max; i++){
        if(isPalindrome(i)){
            printf(" %d", i);
        }
    }   

    printf("\nThe Prime numbers are:");
    for(int i = min; i <= max; i++){
        if(isPrime(i)){
            printf(" %d", i);
        }
    }    

    printf("\nThe Strong numbers are:");
    for(int i = min; i <= max; i++){
        if(isStrong(i)){
            printf(" %d", i);
        }
    }

    return 1;
}
