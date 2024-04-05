#include <stdlib.h>

/* Arrange the N elements of ARRAY in random order.
   Only effective if N is much smaller than RAND_MAX;
   if this may not be the case, use a better random
   number generator. */
void shuffle(short int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int main(){
    srand(time(NULL));
    short int colour_bottom[5] = {0xFEB4DD, 0xA9D5B2, 0xD9FEB4, 0xB4D0FE, 0xFEECB4};
    for (int i = 0; i < 5; i++) {
        printf("%hd ", colour_bottom[i]);
    } 

    printf("\n");
    shuffle(colour_bottom, 5);

    for (int i = 0; i < 5; i++) {
        printf("%hd ", colour_bottom[i]);
    } 
}