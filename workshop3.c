#include <stdio.h> 
#include <stdlib.h> 

void Merge(int L[], int start, int slut, int midt);
void MergeSort(int L[], int start, int slut);
void printList(int L[], int size);

int main(void){ 
  int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 }; 
  int L_size = sizeof(L) / sizeof(L[0]); 
  	
  printf("Givet listen \n"); 
  printList(L, L_size); 
  
  MergeSort(L, 0, L_size - 1); 

  
  printf("Er den sorterede liste \n"); 
  printList(L, L_size); 
  return 0; 
} 

void Merge(int L[], int start, int slut, int midt){
  /* Start med at kopiere de to dellister ind i to nye lister L1 og L2, så vi ikke sletter nogle elementer fra L når vi begynder at flette elementerne derind */
    int i, j, k;
    int n1 = midt - start + 1;
    int n2 = slut - midt;
    int L1[n1], R1[n2];
	
    /* Data kopires over til temp arrays */
    for (i = 0; i < n1; i++){
        L1[i] = L[start + i];
    }
    for (j = 0; j < n2; j++){
        R1[j] = L[midt + 1 + j];
    }

/* Herefter skal vi kopiere elementer fra L1 og L2 ind på pladserne i L mellem start og slut men i sorteret rækkefølge */

    i = 0;
    j = 0;
    k = start;

    /*  */
    while (i < n1 && j < n2){
        if (L1[i] <= R1[j]){
            L[k] = L1[i];
            i++;
        }
        else{
            L[k] = R1[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) { 
        L[k] = L1[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) { 
        L[k] = R1[j]; 
        j++; 
        k++; 
    }


}

void MergeSort(int L[], int start, int slut){
    
    if (start < slut){
        
        double midt = (start + slut) / 2;

        /* Sorterer første halvdel */
        MergeSort(L, start, midt);
        /* Sorterer anden halvdel */
        MergeSort(L, midt + 1, slut);

        Merge(L, start, slut, midt);
    }
    
}

void printList(int L[], int size){ 
  int i; 
  for (i = 0; i < size; i++) 
    printf("%d ", L[i]); 
  printf("\n"); 
} 