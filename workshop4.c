#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "primes.h"
#include <assert.h>

int is2mod5(int x){
    int result, value = 1, i;
    for (i = 0; i < x; i++)
    {
        value = 9 * value;
        value = value % 10;
    }
    if (((value % 5) - 2) == 2)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}
int isPrime(int x){
    int result = 1, i;
    for (i = 2; i <= x / 2; ++i) {

        // condition for non-prime
        if (x % i == 0) {
            result = 0;
            break;
        }
    }

    return result;
}
int isGcd1(int x){
    int i, gcd, result;

    for(i=1; i <= x && i <= 2; ++i)
    {
        // Checks if i is factor of both integers
        if(x%i==0 && 2%i==0)
            gcd = i;
    }
    if (gcd == 1)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }


    return result;
}


int main(void){
  int x;
  int p, q, r;

  printf("Hvilket heltal vil du tjekke?\n");
  scanf("%d", &x);
  printf("x er %d\n", x);

  p = isPrime(x);
  q = isGcd1(x);
  r = is2mod5(x);

  if ((p && !r) || !(p || !q || r) || (!p && !q && r)){
    printf("Du fandt et x\n");
    printf("p er %d, q er %d, and r er %d\n", p,q,r);
  } else {
    printf("Proev igen\n");
  }

  return EXIT_SUCCESS;
}