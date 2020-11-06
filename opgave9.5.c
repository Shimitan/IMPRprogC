#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TABLE_SIZE 100

int compare(const void *a, const void *b);

int main(void) {

    double *numbers = (double*)malloc(TABLE_SIZE * sizeof(double));

    if(numbers == NULL){
        printf("Cannot allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    for(int i = 0; i < TABLE_SIZE; i++){
        numbers[i] = (double)(rand() % 1000);
        printf("Sorted %d: %lf\n", i, numbers[i]);
    }

    qsort(numbers, TABLE_SIZE, sizeof(double), compare);

    for(int i = 0; i < TABLE_SIZE; i++){
        printf("Sorted %d: %lf\n", i, numbers[i]);
    }

    free(numbers);
    numbers = NULL;

    return 0;
}

int compare(const void *a, const void *b) {
   return (*(double*)a - *(double*)b);
}