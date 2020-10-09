#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int i,
        k,
        count;

    scanf("%d", &count);

    for (k = 0; k <= count; k++) {

        for (i = 0; i <= k; i++) {
            printf("%d ", i);
        }

    printf("\n");
    }

    for (k = count - 1; k >= 0; k--) {

        for (i = 0; i <= k; i++) {
            printf("%d ", i);
        }
        
    printf("\n");
    }

}