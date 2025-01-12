#include <stdio.h>
#include <stdlib.h>

#define TOTAL_CARDS 55

struct card{
    int suit;
    int pip;
};
typedef struct card card;

enum suits{clubs, diamonds, hearts, spades};
enum pips{two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace, joker};

int compare(const void *p1, const void *p2);
void printfnc(card cardSet[]);

int main(void) {
    
    int j, i, k;
    struct card cardSet[TOTAL_CARDS];
    printf("her1");
    for (j = 0; j < 3; j++){
        cardSet[j].pip = joker;
        cardSet[j].suit = joker;
    }
    
    for (k = spades; k >= diamonds; k--){
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

int compare(const void *p1, const void *p2){
    card *cp1 = (card*)p1, *cp2 = (card*)p2;
    int result;
    if (cp1->suit < cp2->suit){
    result = -1;
  } else if (cp1->suit > cp2->suit){
    result = 1;
  } else {
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

void printfnc(card cardSet[]){
    char *suits[] = {"clubs", "diamonds", "hearts", "spades"}, 
    *pips[] = {"two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace", "joker"};
    int i;
    for (i = 0; i < TOTAL_CARDS; i++){
        printf("%s %s", suits[cardSet[i].suit], pips[cardSet[i].pip]);
    }
}