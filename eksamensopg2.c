/* Mike Jensen - Eksamensopgave 2: Yatzy */
/* maltow20@student.aau.dk */
/* A400b Software */

/* Inkluderer biblioteker */
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* Programmets funktioner precalles, så programmet ved de er der */
int* allocation_of_array(int antalTerninger);
int roll_multiple_dice(int antalTerninger, int antalKast, int *kast);

int main(int *terninger, int *kast){
    
    srand(time(NULL));
    int antalTerninger = 5, antalKast = 2;
    

    /*printf("Hvor mange terninger?(mindst 5) ");
    scanf("%d", &antalTerninger);

    printf("Hvor mange kast?(mindst 1) ");
    scanf("%d", &antalKast);  */

    allocation_of_array(antalTerninger);
    roll_multiple_dice(antalTerninger, antalKast, kast);

    free(kast);
    kast = NULL;

    return(0);
}

int* allocation_of_array(int antalTerninger){

    int *kast = (int*)malloc(antalTerninger * sizeof(int));

    if(kast == NULL){
        printf("Kan ikke allokere hukkomelse.\n");
        exit(EXIT_FAILURE);
    }
    return kast;
}

int roll_multiple_dice(int antalTerninger, int antalKast, int *kast){
    for(int k = 0; k < antalKast; k++){
        for(int i = 0; i < antalTerninger; i++){
            kast[i] = (double)(rand() % 6 + 1);
            printf("%d ", kast[i]);
        }
        printf("\n");
    }
}
    