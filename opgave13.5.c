#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LGT 50
#define NUMBER_OF_PEOPLE 11

struct person{
    char fornavn[MAX_NAME_LGT];
    char efternavn[MAX_NAME_LGT];
    char vejnavn[MAX_NAME_LGT];
    int vejnummer;
    int postnummer;
    char bynavn[MAX_NAME_LGT];
};
typedef struct person person;


int data(FILE *fp, char *buff, person *people);
int read_data();


int main() {
    read_data(); 
    return 0;
}

int read_data(){

    char buff[1000];
    FILE *fp;

    struct person people[NUMBER_OF_PEOPLE];

    fp = fopen("files/personer13.5.txt", "r");

    for (int i = 0; i < NUMBER_OF_PEOPLE; i++){
        data(fp, buff, &people[i]);
    }
    fclose(fp);
}

int data(FILE *fp, char *buff, person *people){
        fgets(buff, 1000, fp);
        sscanf(buff, "%[^ ] %[^,], %[^0-9] %d, %d %[^.].", people->fornavn, people->efternavn, people->vejnavn, &people->vejnummer, &people->postnummer, people->bynavn);
        printf("%s: ", people->bynavn);
        printf("%s\n", people->efternavn);
}