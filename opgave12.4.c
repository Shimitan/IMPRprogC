/* Mike Jensen - Eksamensopgave 2: Yatzy */
/* maltow20@student.aau.dk */
/* A400b Software */
#include <stdio.h>
#include <stdlib.h>

#define TOTAL_CARDS 55

/* Laver struct til kulør og pip */
struct card{
    int suit;
    int pip;
};
typedef struct card card;

/* Laver enumerationslite over kulør og pip */
enum suits{clubs, diamonds, hearts, spades, jokersuit};
enum pips{two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace, joker};

/* precaller funktioner som prototyper */
int compare(const void *p1, const void *p2);
void printfnc(card cardSet[]);

/* Her skabes mit array, hvorefter det sorteres og printes */
int main(void) {
    
    int j, i, k;
    struct card cardSet[TOTAL_CARDS];

    /* Indsætter jokere i mit array */
    for (j = 0; j < 3; j++){
        cardSet[j].pip = joker;
        cardSet[j].suit = jokersuit;
    }
    /* Indsætter resterende kort i mit array */
    for (k = spades; k >= clubs; k--){
        for (i = ace; i >= two; i--){
            cardSet[j].pip = i;
            cardSet[j].suit = k;
            j++;
        }
    }
    printfnc(cardSet);
    qsort(cardSet, TOTAL_CARDS, sizeof(card), &compare);
    printfnc(cardSet);

    return 0;
}

/* Denne funktion sammenligner 2 værdier */
int compare(const void *p1, const void *p2){
    card *cp1 = (card*)p1, *cp2 = (card*)p2;
    int result;
    if (cp1->suit < cp2->suit){
    result = -1;
    } 
    else if (cp1->suit > cp2->suit){
      result = 1;
    }
    else {
      if (cp1->pip < cp2->pip){
        result = -1;
      } else if (cp1->pip > cp2->pip) {
        result = 1;
      } else {
        result = 0;
      }
    }
    return result;
}

/* Denne funktion printer alle pip med dens tilhørende kulør */
void printfnc(card cardSet[]){
    char *suits[] = {"clubs", "diamonds", "hearts", "spades", "jokersuit"}, 
    *pips[] = {"two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace", "joker"};
    int i;
    for (i = 0; i < TOTAL_CARDS; i++){
        printf("%s %s\n", suits[cardSet[i].suit], pips[cardSet[i].pip]);
    }
}