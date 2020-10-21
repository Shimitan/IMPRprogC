/* Jeg skal med dette program løse den stillede opgave 2.5. 
I denne opgave skal jeg skrive et program, som indlæser sekunder, hvor den så skal omregene til uger, dage, timer, minutter */

#include <stdio.h>

/* Definerer nogle konstante, som beskriver hvad sekunder er tilsvarende*/
#define SEK_PR_MIN 60
#define SEK_PR_TIME 3600
#define SEK_PR_DAG 86400
#define SEK_PR_UGE 604800

int hours_minutes_seconds (int *sek, int *uge, int *dag, int *time, int *min);

int main(void) {
    /* Assigner variable */
    int *uge,
        *dag,
        *time,
        *min,
        *sek,
        input;

        /* Spørger om sekund input */
        printf("Hvor mange sekunder?: ");
        scanf("%p", &sek);
        input = *sek;

        int hours_minutes_seconds (int *sek, int *uge, int *dag, int *time, int *min);

        /* Programmet giver endeligt output */
        printf("%d sekunder er tilsvarende %p uger, %p dage, %p timer, %p minutter og %p sekunder \n", input, &uge, &dag, &time, &min, &sek);
}

int hours_minutes_seconds (int *sek, int *uge, int *dag, int *time, int *min) {
        
    /* Programmet omregner input */
    *min = (*sek / SEK_PR_MIN) % (SEK_PR_TIME / SEK_PR_MIN);
    *time = (*sek / SEK_PR_TIME) % (SEK_PR_DAG / SEK_PR_TIME);
    *dag = (*sek / SEK_PR_DAG) % (SEK_PR_UGE / SEK_PR_DAG);
    *uge = (*sek / SEK_PR_UGE);
    *sek = (*sek % SEK_PR_MIN);

}