#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 20

int main(void) {

    char input[TABLE_SIZE];
    char *noun;
    char outputy[TABLE_SIZE];
    
    printf("Give noun: ");
    scanf("%s", input);
    printf("Noun is: %s\n", input);
    
    int len = strlen(input);

    if(input[len-1] == 'y'){
        strcpy(outputy, input)
    } 
    else if(input[len-1] == 's' || (input[len-2] == 'c' && input[len-1] == 'h') || (input[len-2] == 's' && input[len-1] == 'h')){
        printf("Obama2\n");
    }
    else{
        printf("Obama3\n");
    }

    return 0;
}
