#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int maaltid();
enum forret{guacamole, tarteletter, lakserulle, graeskarsuppe};
enum hovedret{gyldenkaal, hakkeboef, gullash, forlorenHare};
enum dessert{pandekageIs, gulerodskage, chokolademousse, citronfromage};

int main(){

    time_t t;
    srand((unsigned int) time(&t));

    for (int i = 0; i <= 25; i++) {
        maaltid();
    }
}

int maaltid(){
    
    int ret1, ret2, ret3;

    ret1 = rand() % 4;
    ret2 = rand() % 4;
    ret3 = rand() % 4;

    switch (ret1) {
        case guacamole:
            printf("Forret: Guacamole\n");
            break;
        case tarteletter:
            printf("Forret: Tarteletter\n");
            break;
        case lakserulle:
            printf("Forret: Lakseruller\n");
            break;
        case graeskarsuppe:
            printf("Forret: Græskarsuppe\n");
            break;  
        default:
            break;
    }

    switch (ret2) {
        case gyldenkaal:
            printf("Hovedret: Gyldenkål\n");
            break;
        case hakkeboef:
            printf("Hovedret: Hakkebøf\n");
            break;
        case gullash:
            printf("Hovedret: Gullash\n");
            break;
        case forlorenHare:
            printf("Hovedret: Forloren hare\n");
            break;  
        default:
            break;
    }

    switch (ret3) {
        case pandekageIs:
            printf("Dessert: Pandekage m. is\n \n");
            break;
        case gulerodskage:
            printf("Dessert: Gulerodskage\n \n");
            break;
        case chokolademousse:
            printf("Dessert: Chokolademousse\n \n");
            break;
        case citronfromage:
            printf("Dessert: Citronfromage\n \n");
            break;  
        default:
            break;
    }
}