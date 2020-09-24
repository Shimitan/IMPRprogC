/* Jeg skal med dette program løse den stillede opgave 3.4. 
I denne opgave skal jeg skrive et program, som indlæser sekunder, hvor den så skal omregene til timer, minutter og sekunder 
Derudover ønsker vi at blive fri for '0 timer' og '0 minutter'. Plus vi skal have korrekt angivelse af ental og flertal
Det er også vigtigt at pointere, at jeg IKKE anvender betingede udtryk, da jeg synes denne løsning var lidt mere elegant*/

#include <stdio.h>

/* Definerer nogle konstante, som beskriver hvad sekunder er tilsvarende*/
#define SEK_PR_MIN 60
#define SEK_PR_TIME 3600

int main(void) {
    /* Assigner variable */
    int time,
        min,
        sek,
        input;

    char *t = "timer",
         *m = "minutter",
         *s = "sekunder",
         *i = "sekunder";

    /* Spørger om sekund input */
    printf("Hvor mange sekunder?: \n");
    scanf("%d", &sek);
    input = sek;

    /* Programmet omregner input */
    min = (sek / SEK_PR_MIN) % (SEK_PR_TIME / SEK_PR_MIN);
    time = (sek / SEK_PR_TIME);
    sek = (sek % SEK_PR_MIN);

    /* Finder ud af, om vi har 1 time, minut og/eller sekund */
    if (time == 1)
        t = "time"; 
    if (min == 1)
        m = "minut";
    if(sek == 1)
        s = "sekund";
    if(input == 1)
        i = "sekund";

    /* Programmet giver endeligt output */
    if (time == 0 && min > 0)
        printf("%d %s er tilsvarende %d %s og %d %s \n", input, i, min, m, sek, s);
    else if (min == 0 && time == 0)
        printf("%d %s er tilsvarende %d %s \n", input, i, sek, s);
    else
        printf("%d %s er tilsvarende %d %s, %d %s og %d %s \n", input, i, time, t, min, m, sek, s);

    /* Frem for char, så kan man bruge betingede udtryk, til at finde ud af, om det er flertal eller ental, eks.:
        printf("%d %s", input, input != 1 ? "sekunder" : "sekund");
    */
}