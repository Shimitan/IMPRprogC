/* Mike Jensen - Eksamensopgave 1 */
/* maltow20@student.aau.dk */
/* A400b Software */


/* Inkluderer biblioteker */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANTAL_KAMPE 182
#define ANTAL_HOLD 14


struct kamp{
    char ugedag[4];
    char dato[6];
    char tidspunkt[6];
    char hjemmebaneHold[4];
    char udebaneHold[4];
    int hjemmeScore;
    int udeScore;
    int tilskuertal;
};
typedef struct kamp kamp;

struct hold{
    char holdnavn[4];
    int point;
    int holdScoret;
    int modstanderScoret;
};
typedef struct hold hold;

/* Programmets funktioner precalles, så programmet ved de er der */
int read_data();
int data(FILE *fp, char *buff, kamp *kampe);


int main() {
    read_data(); 
    return EXIT_SUCCESS;
}

int read_data(){

    char buff[1000];
    FILE *fp;

    kamp kampe[ANTAL_KAMPE];

    fp = fopen("files/kampe-2019-2020.txt", "r");

    for (int i = 0; i < ANTAL_KAMPE; i++){
        data(fp, buff, &kampe[i]);
    }
    fclose(fp);
}

int data(FILE *fp, char *buff, kamp *kampe){
        fgets(buff, 1000, fp);
        sscanf(buff, "%[^ ] %[^ ] %[^ ] %[^ ] - %[^ ] %d - %d %d", kampe->ugedag, kampe->dato, kampe->tidspunkt, kampe->hjemmebaneHold, kampe->udebaneHold, &kampe->hjemmeScore, &kampe->udeScore, &kampe->tilskuertal);
        printf("%-8s", kampe->ugedag);
        printf("%s ", kampe->dato);
        printf("%s", kampe->tidspunkt);
        printf("%8s - ", kampe->hjemmebaneHold);
        printf("%-3s", kampe->udebaneHold);
        printf("%6d - ", kampe->hjemmeScore);
        printf("%d", kampe->udeScore);
        printf("     %d\n", kampe->tilskuertal);
}