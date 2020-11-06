/* Mike Jensen - Eksamensopgave 1 */
/* maltow20@student.aau.dk */
/* A400b Software */
/* Jeg fik hjælp af min studiegruppe til brugen af pointers i min kode, men er stadig frisk på at forsvare det til eksamen */

/* Inkluderer biblioteker */
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* Programmets funktioner precalles, så programmet ved de er der */
double run_calculator();
void scan_data(char *operator, double *operant);
void do_next_op(double *akkumulatoren, double *operant, char *operator);

/* Her starter lommeregner ved kald af dens funktion */
int main(){
    run_calculator();
    return(0);
}

/* Denne funktion opfører sig som main, hvor alle funktionerne kaldes, indtil en ønsket værdi er opnået */
double run_calculator(){
   
    /* Variabler assignes */
    double operant, akkumulatoren = 0.0;
    char operator, c;

    /* En while-løkke kører, så længe stop inputtet ikke er givet */
    while(operator != 'q'){
        scan_data(&operator, &operant); 
        do_next_op(&akkumulatoren, &operant, &operator);

        /* Her eradikerer jeg input bufferen, da det ellers skaber komplikationer. Denne kode er lånt fra neden stående link: https://stackoverflow.com/questions/26192830/what-does-this-do-whilec-getchar-n-c-eof)/ */
        while((c = getchar()) != '\n' && c != EOF);
        
        /* Løbende eller endeligt resultat udskrives */
        if(operator != 'q'){
            printf("Result so far is %f\n", akkumulatoren);
        } else {
            printf("Final result is: %f\n", akkumulatoren);
        }
    }
    return(akkumulatoren);
}

/* Denne funktion scanner input */
void scan_data(char *operator, double *operant){

    /* Først indtastes en operator */
    printf("Enter operator, and an optional operand: ");
    scanf("%c", operator);

    /* Hvis operatoren er binær, så spørger den om evt. operand */
    if (*operator == '+'|| *operator == '-' || *operator == '*' || *operator == '/' || *operator == '^') {
        scanf("%lf", operant);
    }
}

/* Denne funktion behandler vores input */
void do_next_op(double *akkumulatoren, double *operant, char *operator){
    
    /* Dette switch case kigger på hvilken operator vi har givet som input, og giver en tilpasset udregning */
    switch (*operator) {
        /* Binære operatorer */
        case '+' :
            *akkumulatoren = *akkumulatoren + *operant; break;
        case '-' :
            *akkumulatoren = *akkumulatoren - *operant; break;
        case '*' :
            *akkumulatoren = *akkumulatoren * *operant; break;
        case '/' :
        if(*akkumulatoren != 0){
            *akkumulatoren = *akkumulatoren / *operant;
        } break;
        case '^' :
            *akkumulatoren = pow(*akkumulatoren, *operant); break;
        
        /* Unære operatorer */
        case '#' : /* Da det er antageligt, at vi ikke arbejder med irrationelle tal i denne kode, så sker der intet med tallet, når kvadratroden tages af en negativ værdi */
            if (*akkumulatoren < 0){
            } else *akkumulatoren = sqrt(*akkumulatoren); break;
        case '%' :
            *akkumulatoren = *akkumulatoren * -1; break;
        case '!' :
            if (*akkumulatoren != 0){
                *akkumulatoren = 1 / *akkumulatoren; 
            } break;

        default:
            break;
    }
}