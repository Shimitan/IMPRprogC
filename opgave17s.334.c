/* Mike Jensen - Eksamensopgave 1 */
/* maltow20@student.aau.dk */
/* A400b Software */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int trap(double *a, double *b, double *n, double *f, int input);

int main(){

    double a, b, n, f;
    int input;

    printf("For area under g(x) type 1. For area under h(x) type 2.\n");
    scanf("%d", &input);

    if(input == 1){
        int trap(a, b, n, f, input);
        printf("The area under the function g(x) is: \n");
    } 
    else if(input == 2){
        
        printf("The area under the function h(x) is: \n");
    } 
    else {
        printf("ERROR: Input was not equal to 1 or 2\n");
    }


    return(0);
}

int trap(double *a, double *b, double *n, double *f, int input){

    if(input == 1){
        printf("The area under the function g(x) is: \n");
    } 
    else if(input == 2){
        printf("The area under the function h(x) is: \n");
    } 
    else {
        printf("ERROR: Input was not equal to 1 or 2\n");
    }

}