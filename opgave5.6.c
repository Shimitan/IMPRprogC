#include <math.h>
#include <stdio.h>

int main(void){

    double a, x_n, x_n1;
    int n = 10;

    printf("Estimer en x-værdi: ");
    scanf("%lf", &x_n1);

    for (int i = 0; i <= n; i++) {
        x_n1 = (1/2) * (x_n + a/x_n);
    }
    
    printf("%lf \n", x_n1);

}