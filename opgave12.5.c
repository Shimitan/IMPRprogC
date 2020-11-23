#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Broeker {
    unsigned int taeller;
    unsigned int naevner;
};

int printBroek(struct Broeker Broek);
int broekGangning(struct Broeker *Broek, struct Broeker *gangeBroek);
int gangning(struct Broeker *Broek);

int main() {

    struct Broeker Broek1 = {.taeller = 4, .naevner = 8};
    struct Broeker Broek2 = {.taeller = 2, .naevner = 3};

    printBroek(Broek1);
    printBroek(Broek2);
    broekGangning(&Broek1, &Broek2);
    printBroek(Broek1);
    gangning(&Broek1);
    printBroek(Broek1);

    return 0;
}

int printBroek(struct Broeker Broek){
    printf("Brøken er: %u/%u\n", Broek.taeller, Broek.naevner);
}

int gangning(struct Broeker *Broek){
    int gange = 5;
    Broek->taeller *= gange;
    Broek->naevner *= gange;
}

int broekGangning(struct Broeker *Broek, struct Broeker *gangeBroek){
    Broek->taeller *= gangeBroek->taeller;
    Broek->naevner *= gangeBroek->naevner;
}