/* Mike Jensen - Eksamensopgave 2: Yatzy */
/* maltow20@student.aau.dk */
/* A400b Software */

/* Inkluderer biblioteker */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    /* Her antages størrelsen af vores table ud fra, at et varehus altid er betegnet med 3 bogstaver, der ikke er over 9999 produkter, samt over 99 qualifiers */
    char input[10], warehouse[10+3], id[13+4], qualifiers[17+3];
    int i, lenInput;

    /* Input modtages */
    printf("Insert product code: ");
    scanf("%s", input);
    
    lenInput = strlen(input);
    /* Tjekker om længden af inputtet passer med den forventede længde på 10 */
    if (lenInput != 10){
        printf("ERROR: Invalid Product Code\n");
        exit(EXIT_FAILURE);
    }

    /* Anvender strncpy til kopiring af arrays */
    strncpy(warehouse, input, 3);
    
    /* Gør det nu uden strncpy */
    for (i = 3; i < 7; i++){
        id[i-3] = input[i]; 
    }
    id[i-3] = '\0';
    
    for (i = 7; i < 10; i++){
        qualifiers[i-7] = input[i]; 
    }
    qualifiers[i-7] = '\0';

    /* Giver endeligt output */
    printf("Warehouse: %s\n", warehouse);
    printf("ID: %s\n", id);
    printf("Qualifiers: %s\n", qualifiers);

    return(0);
}

/* Efterfølgende kommentarer: Jeg kunne nemt forbedre dette program. */
/* Jeg kunne have lavet seperate funktion til hhv. indlæsning, kopiring af strings, og endeligt output. */
/* Derudover kunne jeg tage forbehold for nogle flere ting. Jeg tjekker om længden af input stemmer overens med forventet længde. */
/* Jeg tjekker IKKE om warehouse er bogstaver, ID er tal og qualifers er et bogstav efterfulgt af 2 tal. */
/* Heldigvis viste jeg hvordan man kunne kopire strings, på to forskellige måder. */
