/* Mike Jensen - Eksamensopgave 2: Yatzy */
/* maltow20@student.aau.dk */
/* A400b Software */

/* Inkluderer biblioteker */
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ANTAL_SPIL 16

enum udfald{Ones, Twos, Threes, Fours, Fives, Sixes, onePair, twoPair, threeKind, fourKind, smallStraight, largeStraight, fullHouse, Chance, Yatzy};

/* Programmets funktioner precalles, så programmet ved de er der */
int* allocation_of_memory(int antalTerninger);
int roll_multiple_dice(int antalTerninger, int *kast);

int main(int *terninger, int *kast, int *score){
    
    srand(time(NULL));
    int antalTerninger = 5;
    
    /*printf("Hvor mange terninger?(mindst 5) ");
    scanf("%d", &antalTerninger);*/

    kast = allocation_of_memory(antalTerninger);
    score = allocation_of_memory(ANTAL_SPIL);

    if(kast == NULL || score == NULL){
        printf("Kan ikke allokere hukkomelse.\n");
        exit(EXIT_FAILURE);
    }

    roll_multiple_dice(antalTerninger, kast);

    free(kast);
    kast = NULL;

    return(0);
}

int* allocation_of_memory(int antalTerninger){
    int *allocate = (int*)malloc(antalTerninger * sizeof(int));
    return allocate;
}

int roll_multiple_dice(int antalTerninger, int *kast){
    //for(int k = 0; k < ANTAL_SPIL; k++){
        for(int i = 0; i < antalTerninger; i++){
            kast[i] = (double)(rand() % 6 + 1);
            printf("%d ", kast[i]);
        }
        printf("\n");
    //}
}
    