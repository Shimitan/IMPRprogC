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
int find_threeKind(int antalTerninger, int *kast);
int find_fourKind(int antalTerninger, int *kast);
int find_smallStraight(int antalTerninger, int *kast, int tal);
int find_largeStraight(int antalTerninger, int *kast, int tal);
int find_fullHouse(int antalTerninger, int *kast);
int find_chance(int antalTerninger, int *kast);
int find_yatzy(int antalTerninger, int *kast);

int main(int *terninger, int *kast, int *score){
    srand(time(NULL));
    int antalTerninger = 0, done = 0;
    char svar;
    while (!done){

        /* Input scannes */
        printf("Hvor mange terninger?(mindst 5) ");
        scanf("%d", &antalTerninger);
        while(antalTerninger < 5){
            printf("Prøv igen (mindst 5 terninger) ");
            scanf("%d", &antalTerninger);
        }
        
        /* Der gøres plads i hukkomelsen til mit terningekast og hvad scoren er på */
        kast = allocation_of_memory(antalTerninger);
        score = allocation_of_memory(ANTAL_SPIL);
        if(kast == NULL || score == NULL){
            printf("Kan ikke allokere hukkomelse.\n");
            exit(EXIT_FAILURE);
        }

        /* Yatzy spilles */
        play_yatzy(antalTerninger, kast, score);

        /* Når spillet er færdi, så befries brugt hukkomelse */
        free(kast);
        kast = NULL;
        free(score);
        score = NULL;

        /* Spørger om genspil */
        printf("\nSpil igen? (y/n)\n");
        scanf(" %c", &svar);
        done = (svar == 'n' ? 1 : 0);
    }
    return(0);
}

/* Her allokeres hukkomelse ift. antal terninger */
int* allocation_of_memory(int antalTerninger){
    int *allocate = (int*)malloc(antalTerninger * sizeof(int));
    return allocate;
}

/* Array med n antal terninger laves */
int roll_multiple_dice(int antalTerninger, int *kast){
        for(int i = 0; i < antalTerninger; i++){
            kast[i] = (double)(rand() % 6 + 1);
        }
}

/* Her spilles alle de forskellige spil som er i yatzy */
int play_yatzy(int antalTerninger, int *kast, int *score){

    int i, j, k, temp;

    /* Forlykken sikrer sig alle spil gennemføres, hvor den starter ved spil et */
    for (i = Ones; i <= ANTAL_SPIL; i++){

        /* Der kastes n-antal terninger */
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

                /* Her beregnes bonusen, hvis spil 1-6 er over 62 */
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
                printf("%-12s", "Et par");
                for (j = 0; j < antalTerninger; j++){
                    printf("%d ", *(kast + j));
                }
                *(score + i) = find_pair1(antalTerninger, kast);
                printf("%6d\n", *(score + i));
                break;

            case twoPair:
                printf("%-12s", "To par");
                for (j = 0; j < antalTerninger; j++){
                    printf("%d ", *(kast + j));
                }
                *(score + i) = find_pair2(antalTerninger, kast);
                printf("%6d\n", *(score + i));
                break;
                
             case threeKind:
                printf("%-12s", "Tre ens");
                for (j = 0; j < antalTerninger; j++){
                    printf("%d ", *(kast + j));
                }
                *(score + i) = find_threeKind(antalTerninger, kast);
                printf("%6d\n", *(score + i));
                break;
            
            case fourKind:
                printf("%-12s", "Fire ens");
                for (j = 0; j < antalTerninger; j++){
                    printf("%d ", *(kast + j));
                }
                *(score + i) = find_fourKind(antalTerninger, kast);
                printf("%6d\n", *(score + i));
                break;

            case smallStraight:
                printf("%-12s", "Lav");
                for (j = 0; j < antalTerninger; j++){
                    printf("%d ", *(kast + j));
                }
                *(score + i) = find_smallStraight(antalTerninger, kast, 1);
                printf("%6d\n", *(score + i));
                break;

            case largeStraight:
                printf("%-13s", "Høj");
                for (j = 0; j < antalTerninger; j++){
                    printf("%d ", *(kast + j));
                }
                *(score + i) = find_largeStraight(antalTerninger, kast, 2);
                printf("%6d\n", *(score + i));
                break;

            case fullHouse:
                printf("%-12s", "Fuld hus");
                for (j = 0; j < antalTerninger; j++){
                    printf("%d ", *(kast + j));
                }
                *(score + i) = find_fullHouse(antalTerninger, kast);
                printf("%6d\n", *(score + i));
                break;

            case Chance:
                printf("%-12s", "Chance");
                for (j = 0; j < antalTerninger; j++){
                    printf("%d ", *(kast + j));
                }
                *(score + i) = find_chance(antalTerninger, kast);
                printf("%6d\n", *(score + i));
                break;

            case Yatzy:
                printf("%-12s", "Yatzy");
                for (j = 0; j < antalTerninger; j++){
                    printf("%d ", *(kast + j));
                }
                *(score + i) = find_yatzy(antalTerninger, kast);
                printf("%6d\n", *(score + i));
                break;

            default:
                break;
        }
    }
    temp = 0;
    for (j = Ones; j <= Yatzy; j++){
        temp += *(score + j);
    }
    printf("Total: %d\n", temp);
}

/* Finder gentagelser af tal op til 5 gange i et array */
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
/* En lille ændring er, at denne funktion sammenligner omvendt, for at sortere efter størst først */
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

/* Finder det største par i et array */
int find_pair1(int antalTerninger, int *kast){
    int score = 0;
    /* Sorterer listen fra størst til mindst */
    qsort(kast, antalTerninger, sizeof(int), &int_compare);
    /* Finder ud af om 2 sammenhængende tal er ens */
    for (int i = 0; i <= antalTerninger; i++){
        if (kast[i] == kast[i+1]){
            score = kast[i]*2;
            break;
        }
    } 
    return score;
}

/* Finder de to største par i et array */
int find_pair2(int antalTerninger, int *kast){
    int score = 0, score1 = 0, score2 = 0, i;
    /* Finder første par */
    qsort(kast, antalTerninger, sizeof(int), &int_compare);
    for (i = 0; i <= antalTerninger; i++){
        if (kast[i] == kast[i+1]){
            score1 = kast[i]*2;
            break;
        }
    } 
    /* Sætter første pars værdier til 0, så parret ikke gentages */
    for (int k = 0; k < antalTerninger; k++){
        if (kast[k] == kast[k+1]){
            kast[k] = 0;
            kast[k+1] = 0;
            break;
        }
    }
    /* Finder andet par */
    qsort(kast, antalTerninger, sizeof(int), &int_compare);
    for (int j = 0; j <= antalTerninger; j++){
        if (kast[j] != kast[i]){
            if (kast[j] == kast[j+1]){
                score2 = kast[j]*2;
                break;
            }
        }
    }
    /* Score variablen ændres kun, hvis den har fundet to par */
    if (score1 != 0 && score2 != 0){
        score = score1 + score2;
    } 
    else{
        score = 0;
    }
    return score;
}

/* Finder tre ens */
int find_threeKind(int antalTerninger, int *kast){
    int score = 0;
    /* Sorterer listen fra størst til mindst */
    qsort(kast, antalTerninger, sizeof(int), &int_compare);
    /* Finder ud af om 2 sammenhængende tal er ens */
    for (int i = 0; i <= antalTerninger; i++){
        if (kast[i] == kast[i+2]){
            score = kast[i]*3;
            break;
        }
    } 
    return score;
}

/* Finder fire ens */
int find_fourKind(int antalTerninger, int *kast){
    int score = 0;
    /* Sorterer listen fra størst til mindst */
    qsort(kast, antalTerninger, sizeof(int), &int_compare);    
    /* Finder ud af om 2 sammenhængende tal er ens */
    for (int i = 0; i <= antalTerninger; i++){
        if (kast[i] == kast[i+3]){
            score = kast[i]*4;
            break;
        }
    } 
    return score;
}

/* Fik hjælp af et gruppemedlem, til løsningen af smallStraight og largeStraight funktionerne, ift. brugen af binary search */
/* Finder lille straight (1,2,3,4,5)*/
int find_smallStraight(int antalTerninger, int *kast, int tal){
    int score = 0;
    qsort(kast, antalTerninger, sizeof(int), &int_compare);
    for (int i = tal; i <= (tal + 4); i++){
        if (bsearch(&i, kast, antalTerninger, sizeof(int), &int_compare) != NULL){
            score += i;
        }
        else {
            score = 0;
            break;
        }        
    }
    return score;
}

/* Finder stor straight (2,3,4,5,6) */
int find_largeStraight(int antalTerninger, int *kast, int tal){

    int score = 0;

    qsort(kast, antalTerninger, sizeof(int), &int_compare);
    for (int i = tal; i <= (tal + 4); i++){
        if (bsearch(&i, kast, antalTerninger, sizeof(int), &int_compare) != NULL){
            score += i;
        }
        else {
            score = 0;
            break;
        }        
    }
    return score;
}

/* Finder fuld hus */
int find_fullHouse(int antalTerninger, int *kast){
    int score = 0, score1, score2, i;
    /* Finder største 3-ens */
    qsort(kast, antalTerninger, sizeof(int), &int_compare);
    for (i = 0; i <= antalTerninger; i++){
        if (kast[i] == kast[i+2]){
            score1 = kast[i]*3;
            break;
        }
    } 
    /* Sætter største 3-ens værdier til 0, så de ikke kan genbruges */
    for (int k = 0; k < antalTerninger; k++){
        if (kast[k] == kast[k+2]){
            kast[k] = 0;
            kast[k+1] = 0;
            kast[k+2] = 0;
            break;
        }
    }
    /* Finder største par, som ikke har samme øjne som største 3-ens */
    qsort(kast, antalTerninger, sizeof(int), &int_compare);
    for (int j = 0; j <= antalTerninger; j++){
        if (kast[j] != kast[i]){
            if (kast[j] == kast[j+1]){
                score2 = kast[j]*2;
                break;
            }
        }
    }
    /* Score variablen ændres kun, hvis den har fundet to par */
    if (score1 != 0 && score2 != 0){
        score = score1 + score2;
    } 
    else{
        score = 0;
    }
    return score;
}

/* Finder chancen */
int find_chance(int antalTerninger, int *kast){
    int score = 0;
    /* Sorterer listen fra størst til mindst */
    qsort(kast, antalTerninger, sizeof(int), &int_compare);    
    for (int i = 0; i < 5; i++){
        score += kast[i];
    } 
    return score;
}

/* Finder fire ens */
int find_yatzy(int antalTerninger, int *kast){
    int score = 0;
    /* Sorterer listen fra størst til mindst */
    qsort(kast, antalTerninger, sizeof(int), &int_compare);
    /* Finder ud af om 2 sammenhængende tal er ens */
    for (int i = 0; i <= antalTerninger; i++){
        if (kast[i] == kast[i+4]){
            score = kast[i]*5 + 50;
            break;
        }
    } 
    return score;
}