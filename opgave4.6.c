#include <stdio.h>
#include <stdlib.h>

int main(void) {

    //Assigner variable
    int a,
        b,
        i,
        gcd;

    //Laver en while-løkke, således mit program vil fortsætte med at finde største fælles divisor, indtil den får et negativt input
    while (1) {
        
        //Spørger om input
        printf("Assign two integers (divide with space): \n");
        scanf("%d %d", &a, &b);

        //Finder største fælles divisor
        for (i = 1; i <= a && i <= b; ++i) {
            if((a % i == 0) && (b % i == 0)) {
                gcd = i;
            }
        }

        //Her giver programmet en fejlmeddelelse, hvis et input er negativt
        if (a < 0 || b < 0) {
            printf("ERROR: The input of a and/or b can't be negative \n");
            break;
        }
        
        //Programmet givet endeligt output, hvorefter den gentager løkken
        printf("Greatest common divisor of %d and %d is %d \n", a, b, gcd);
    }
}
//Læs venligst supplerende kommentar for selvreflektion