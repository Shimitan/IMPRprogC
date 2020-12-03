/* Mike Jensen - Eksamensopgave 3 */
/* maltow20@student.aau.dk */
/* A400b Software */

/* Biblioteker */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definitioner */
/* Der antages, at der er 182 kampe spillet af 14 hold */
#define ANTAL_KAMPE 182
#define ANTAL_HOLD 14
#define DAG_LAENGDE 4
#define DATO_LAENGDE 6
#define TIDSPUNKT_LAENGDE 6
#define HOLDNAVN_LAENGDE 4

/* Structs */
struct kamp{
    char ugedag[DAG_LAENGDE];
    char dato[DATO_LAENGDE];
    char tidspunkt[TIDSPUNKT_LAENGDE];
    char hjemmebaneHold[HOLDNAVN_LAENGDE]; 
    char udebaneHold[HOLDNAVN_LAENGDE];
    int hjemmeScore;
    int udeScore;
    int tilskuertal;
};
typedef struct kamp kamp;

struct hold{
    char *holdnavn;
    int point;
    int holdScoret;
    int modstanderScoret;
};
typedef struct hold hold;

/* Prototyper */
void read_data(kamp *kampe);
void data(FILE *fp, char *buff, kamp *kampe);
void print_games_played(kamp *kampe);
void sum_games(kamp *kampe, hold *hold);
void input_game(hold *hold, char *is, int point, int holdScoret, int modstanderScoret);
int find_index(hold *hold, char *input);
int hash_function(const char *is);
char* allocate_team_name(int laengde);
int compare_teams(const void *p1, const void *p2);
void print_team_standings(hold *hold);
void free_dynamic_memory(hold *holdene);

/* Main - læser data, summere spillene, printer endelige resultater */
int main() {
    kamp kampe[ANTAL_KAMPE];
    hold holdene[ANTAL_HOLD];

    read_data(kampe); 
    sum_games(kampe, holdene);
    print_team_standings(holdene);
    free_dynamic_memory(holdene);

    return EXIT_SUCCESS;
}

/* Her indlæses dataen fra .txt filen */
void read_data(kamp *kampe){
    char buff[1000];
    int i;
    FILE *fp;

    fp = fopen("files/kampe-2019-2020.txt", "r");
    if (fp == NULL){
        printf("Kunne ikke åbne filen\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Dag     Dato   Kl.        Hold        Score   Tilskuere\n");
    printf("-------------------------------------------------------\n");
    for (i = 0; i < ANTAL_KAMPE; i++){
        data(fp, buff, &kampe[i]);
    }
    printf("-------------------------------------------------------\n");
    
    fclose(fp);
    fp = NULL;
}

/* Her scannes og printes .txt filen */
void data(FILE *fp, char *buff, kamp *kampe){
    fgets(buff, 1000, fp);
    sscanf(buff, "%[^ ] %[^ ] %[^ ] %[^ ] - %[^ ] %d - %d %d", kampe->ugedag, kampe->dato, kampe->tidspunkt, kampe->hjemmebaneHold, kampe->udebaneHold, &kampe->hjemmeScore, &kampe->udeScore, &kampe->tilskuertal);
    print_games_played(kampe);
}

/* Print funktion til .txt filen */
void print_games_played(kamp *kampe) {
    printf("%-8s", kampe->ugedag);
    printf("%s ", kampe->dato);
    printf("%s", kampe->tidspunkt);
    printf("%8s - ", kampe->hjemmebaneHold);
    printf("%-3s", kampe->udebaneHold);
    printf("%6d - ", kampe->hjemmeScore);
    printf("%d", kampe->udeScore);
    printf("     %d\n", kampe->tilskuertal);
}

/* I denne funktion bliver point talt sammen til holdene */
void sum_games(kamp *kampe, hold *holdene){
    int hjemmeholdPoint, udeholdPoint, i;

    for (i = 0; i < ANTAL_KAMPE; i++){
        if (kampe[i].hjemmeScore > kampe[i].udeScore){
            hjemmeholdPoint = 3;
            udeholdPoint = 0;
        }
        else if (kampe[i].hjemmeScore == kampe[i].udeScore){
            hjemmeholdPoint = 1;
            udeholdPoint = 1;
        }
        else{
            hjemmeholdPoint = 0;
            udeholdPoint = 3;
        }
        input_game(holdene, kampe[i].hjemmebaneHold, hjemmeholdPoint, kampe[i].hjemmeScore, kampe[i].udeScore);
        input_game(holdene, kampe[i].udebaneHold, udeholdPoint, kampe[i].udeScore, kampe[i].hjemmeScore);
    }
    qsort(holdene, ANTAL_HOLD, sizeof(hold), &compare_teams);
}

/* Denne funktion er til associativt input af hold navnene */
void input_game(hold *holdene, char *is, int point, int holdScoret, int modstanderScoret){
    int index;
    index = find_index(holdene, is);

    if (index != -1){
        holdene[index].point += point;
        holdene[index].holdScoret += holdScoret;
        holdene[index].modstanderScoret += modstanderScoret;
    }
    else{
        index = hash_function(is);

        while (holdene[index].holdnavn != NULL && strcmp(holdene[index].holdnavn, is) != 0){
            index = (index + 1) % ANTAL_HOLD;
        }
        
        holdene[index].holdnavn = allocate_team_name(strlen(is));
        if(holdene[index].holdnavn == NULL){
            printf("Kan ikke allokere hukkomelse.\n");
            exit(EXIT_FAILURE);
        }
        strcpy(holdene[index].holdnavn, is);

        holdene[index].point = point;
        holdene[index].holdScoret = holdScoret;
        holdene[index].modstanderScoret = modstanderScoret;
    }
}

/* Index funktion - hjælp modtaget fra gruppemedlem (Arthur Osnes) */
int find_index(hold *holdene, char *input){
    int index = hash_function(input);
    while (holdene[index].holdnavn != NULL && strcmp(holdene[index].holdnavn, input) != 0){
        index = (index + 1) % ANTAL_HOLD;
    }
    if (holdene[index].holdnavn == NULL){
        return -1;
    }
    else if (strcmp(holdene[index].holdnavn, input) == 0){
        return index;
    }
    else{
        return -1;
    }
}

/* Hash funktion - hjælp modtaget fra gruppemedlem (Arthur Osnes) */
int hash_function(const char *is){
    int index, laengde;
    laengde = strlen(is);
    index = is[0] + is[laengde/2] + is[laengde-1];
    return (index % ANTAL_HOLD);
}

/* Pladser allokeres til hold navnene */
char* allocate_team_name(int laengde){
    char *holdnavn = (char *) malloc(laengde * sizeof(char));
    return holdnavn;
}

/* Taget fra tidligere afleveringsopgave om spillekort (12.4), med omdøbning af variable */
/* Holdene sammenlignes, for at finde ud af hvilket hold har flest point */
int compare_teams(const void *p1, const void *p2){
    hold *hp1 = (hold*)p1, *hp2 = (hold*)p2;
    int result;

    if (hp1->point < hp2->point){
        result = 1;
    } 
    else if (hp1->point > hp2->point){
        result = -1;
    }
    else {
        if ((hp1->holdScoret - hp1->modstanderScoret) < (hp2->holdScoret - hp2->modstanderScoret)){
            result = 1;
        } 
        else if ((hp1->holdScoret - hp1->modstanderScoret) > (hp2->holdScoret - hp2->modstanderScoret)) {
            result = -1;
        } 
        else {
            result = 0;
        }
    }
    return result;
}

/* Efterspurgt print af hold stillinger udskrives i denne funktion */
void print_team_standings(hold *holdene){
    int i;
    char holdnavn[9] = {"Holdnavn"}, point[6] = {"Point"}, maalAfHold[13] = {"Mål-af-hold"}, maalModHold[14] = {"Mål-mod-hold"};
    printf("%-10s %7s %16s %15s\n", holdnavn, point, maalAfHold, maalModHold);
    for (i = 0; i < ANTAL_HOLD; i++){
        printf("  %-8s %5d %12d %13d\n", holdene[i].holdnavn, holdene[i].point, holdene[i].holdScoret, holdene[i].modstanderScoret);
    }
}

/* Her frigøres den dynamisk allokerede hukkomelse, brugt til holdnavnene */
void free_dynamic_memory(hold *holdene){
    int i;
    for (i = 0; i < ANTAL_HOLD; i++){
        free(holdene[i].holdnavn);
        holdene[i].holdnavn = NULL;
    }
}