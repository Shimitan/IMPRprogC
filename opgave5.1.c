#include <stdio.h>
#include <math.h>

/* Programmets funktioner precalles, så den ved de er der */
double findDisc (double a, double b, double c);
double findRoot1(double a, double b, double discriminant);
double findRoot2(double a, double b, double discriminant);
void solveQuadraticEquation(double a, double b, double c);

int main(void) {
    
    double a, b, c;

    /* En lykke beregner rødder, indtil a, b og er lig 0 */
    while((a != 0) && (b != 0) && (c != 0)) {
        printf("Enter coeficients a, b, and c: ");
        scanf("%lf %lf %lf", &a, &b, &c);
        solveQuadraticEquation(a, b, c);  
    }

    return 0;
}

/* Her printes rødderne af kvadratsætningen: a * x*x + b * x + c = 0 */
void solveQuadraticEquation(double a, double b, double c){

    /* Variabler assignes og funktioner calles */
    double discriminant = findDisc(a,b,c);
    double root1 = findRoot1(a,b,discriminant);
    double root2 = findRoot2(a,b,discriminant);

    /* Rødder printes afhængigt af discriminanten */
    if (discriminant < 0) {
        printf("No roots\n");
    }
    else if (discriminant == 0){
        printf("One root: %f\n", root1);
    }
    else {
        printf("Two roots: %f and %f\n", root1, root2);
    }
} 

/* Diskriminant funktionen */
double findDisc(double a, double b, double c) {
    return((b * b - 4 * a * c)); /* Diskriminanten findes og tilbagesendes */
}

/* Første rod */
double findRoot1(double a, double b, double discriminant) {
    return((-b + sqrt(discriminant))/(2*a)); /* Første rod findes og tilbagesendes */
}

/* Anden rod */
double findRoot2(double a, double b, double discriminant) {
    return((-b - sqrt(discriminant))/(2*a)); /* Anden rod findes og tilbagesendes */
}