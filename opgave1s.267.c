#include <stdio.h>

int main (void){

    int n,
        i,
        sum1 = 0,
        sum2 = 0;

    printf("Tildel værdi n: \n");
    scanf("%d", &n);
    printf("Tildelt værdi af n: %d \n", n);
    

    for (i = 0; i <= n; i++) {
        sum1 += i;
    }
    
    sum2 = (n*(n+1))/2;

    printf("Value of sum1: %d \n", sum1);
    printf("Value of sum2: %d \n", sum2);

    if (sum1 == sum2) {       
        printf("True \n");
    } 
    else {
        printf("False \n");
    }

    return(0);

}
