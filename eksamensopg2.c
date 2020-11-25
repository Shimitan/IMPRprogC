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
int play_yatzy(int antalTerninger, int *kast, int *score);
int find_number(int antalTerninger, int *kast, int tal);
int int_compare(const void *p1, const void *p2);
int find_pair1(int antalTerninger, int *kast);
int find_pair2(int antalTerninger, int *kast);

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

    play_yatzy(antalTerninger, kast, score);

    free(kast);
    kast = NULL;

    return(0);
}

int* allocation_of_memory(int antalTerninger){
    int *allocate = (int*)malloc(antalTerninger * sizeof(int));
    return allocate;
}

int roll_multiple_dice(int antalTerninger, int *kast){
        for(int i = 0; i < antalTerninger; i++){
            kast[i] = (double)(rand() % 6 + 1);
        }
}

int play_yatzy(int antalTerninger, int *kast, int *score){

    int i, j, k, temp;

    for (i = Ones; i <= ANTAL_SPIL; i++)
    {
        roll_multiple_dice(antalTerninger, kast);
        switch (i){
            case Ones:
                *(score + i) = find_number(antalTerninger, kast, 1);
                printf("%-12s", "1-ere");
                for (j = 0; j < antalTerninger; j++){
                    printf("%d ", *(kast + j));
                }
                printf("%6d\n", *(score + i));
                break;
            
            case Twos:
                *(score + i) = find_number(antalTerninger, kast, 2);
                printf("%-12s", "2-ere");
                for (j = 0; j < antalTerninger; j++){
                    printf("%d ", *(kast + j));
                }
                printf("%6d\n", *(score + i));
                break;

            case Threes:
                *(score + i) = find_number(antalTerninger, kast, 3);
                printf("%-12s", "3-ere");
                for (j = 0; j < antalTerninger; j++){
                    printf("%d ", *(kast + j));
                }
                printf("%6d\n", *(score + i));
                break;

            case Fours:
                *(score + i) = find_number(antalTerninger, kast, 4);
                printf("%-12s", "4-ere");
                for (j = 0; j < antalTerninger; j++){
                    printf("%d ", *(kast + j));
                }
                printf("%6d\n", *(score + i));
                break;

            case Fives:
                *(score + i) = find_number(antalTerninger, kast, 5);
                printf("%-12s", "5-ere");
                for (j = 0; j < antalTerninger; j++){
                    printf("%d ", *(kast + j));
                }
                printf("%6d\n", *(score + i));
                break;

            case Sixes:
                *(score + i) = find_number(antalTerninger, kast, 6);
                printf("%-12s", "6-ere");
                for (j = 0; j < antalTerninger; j++){
                    printf("%d ", *(kast + j));
                }
                printf("%6d\n", *(score + i));


                for (j = Ones; j <= Sixes; j++){
                    temp += *(score + j);
                }
                
                if (temp >= 63){
                    *(score + i) = 50;
                    printf("Du får bonus!\n");
                }
                else {
                    *(score + i) = 0;
                    printf("Du får ingen bonus :(\n");
                }
                break;

            case onePair:
                *(score + i) = find_pair1(antalTerninger, kast);
                printf("%-12s", "Et par");
                for (j = 0; j < antalTerninger; j++){
                    printf("%d ", *(kast + j));
                }
                printf("%6d\n", *(score + i));
                break;

            case twoPair:
                *(score + i) = find_pair2(antalTerninger, kast);
                printf("%-12s", "To par");
                for (j = 0; j < antalTerninger; j++){
                    printf("%d ", *(kast + j));
                }
                printf("%6d\n", *(score + i));
                break;
                
            
            default:
                break;
        }
    }
}


int find_number(int antalTerninger, int *kast, int tal){
    
    int score = 0, count = 0;

    for (int i = 0; i <= antalTerninger; i++){
            if (kast[i] == tal && count <= 4){
                score++;
                count++;
            }
    }
    score *= tal;
    return score;
}

/* Compare funktion taget fra Kurts powerpoint slide */
int int_compare(const void *p1, const void *p2){
    int result, *ip1 = (int *) p1, *ip2 = (int *) p2;
    if (*ip1 > *ip2){
        result = -1;
    }
    else if (*ip1 < *ip2) {
        result = 1;
    }
    else {
        result = 0;
    }
    return result;
}

int find_pair1(int antalTerninger, int *kast){

    int score = 0;


    qsort(kast, antalTerninger, sizeof(int), &int_compare);

    for (int i = 0; i <= antalTerninger; i++){
        if (kast[i] == kast[i+1]){
            score = kast[i]*2;
            break;
        }
    } 
    return score;
}

int find_pair2(int antalTerninger, int *kast){

    int score = 0;


    qsort(kast, antalTerninger, sizeof(int), &int_compare);

    for (int i = 0; i <= antalTerninger; i++){
        if (kast[i] == kast[i+1]){
            score = kast[i]*2;
            break;
        }
    } 
    return score;
}