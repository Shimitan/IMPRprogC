#include <stdio.h>

int main(void) { int laengdeGrund, hoejdeGrund, laengdeHus,
        hoejdeHus, arealGrund, arealHus, arealGraes, klippeTid;
    printf("Hvor lang er grunden?: \n"); scanf("%d", &laengdeGrund);
    printf("Hvor høj er grunden?: \n"); scanf("%d", &hoejdeGrund);
    printf("Hvor lang er huset?: \n"); scanf("%d", &laengdeHus);
    printf("Hvor høj er huset?: \n"); scanf("%d", &hoejdeHus);
    arealGrund = laengdeGrund * hoejdeGrund;
    arealHus = laengdeHus * laengdeHus;
    arealGraes = arealGrund - arealHus; klippeTid = arealGraes / 2;
    printf("Klipningen tager %d sekunder \n", klippeTid); return(0); }