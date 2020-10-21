#include <stdio.h>

int sum_iter (int n, int i);
int sum_formula (int n, int i, int sum1, int sum2);

int main (void){

    int n,
        i,
        sum1,
        sum2;

    printf("Tildel værdi n: \n");
    scanf("%d", &n);
    
    sum1 = sum_iter(n,i);
    sum_formula(n,i,sum1,sum2);

    return(0);
}

int sum_iter (int n, int i) {

    int sum1 = 0;

    printf("Tildelt værdi af n: %d \n", n);

    for (i = 0; i <= n; i++) {
        sum1 += i;
    }

    return(sum1);
}

int sum_formula (int n, int i, int sum1, int sum2) {

    sum2 = (n*(n+1))/2;

    printf("Value of sum1: %d \n", sum1);
    printf("Value of sum2: %d \n", sum2);

    if (sum1 == sum2) {       
        printf("True \n");
    } 
    else {
        printf("False \n");
    }
}