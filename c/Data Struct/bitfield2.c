/* (case of unsigned int) n bit int can store 2^n +ve numbers (eg: 2 bit int can store :- 4 numbers)
   (case of signed int) n bit int can store (2^n)/2 in +ve direction and -ve direction (eg: 3 bit can store :- 2 -ve num and 2 +ve num (zero includes as +ve))
 */



#include <stdio.h>

#define NUM_LOOP 20
struct counter{
    int little:2; // 2 bit signed integer
    int medium:4; // 4 bit signed integer
    int large:6;  // 6 bit signed integer
} __attribute__((packed));

struct counter2{
    unsigned short int little:2; // 2 bit unsigned integer
    unsigned short int medium:4; // 4 bit unsigned integer
    unsigned short int large:6;  // 6 bit unsigned integer
};



int main(void){
    struct counter counts;
    counts.little = 0;
    counts.medium = 0;
    counts.large = 0;

    for (int i =0; i<NUM_LOOP; i++){
        printf("\n%d , %d , %d", counts.little, counts.medium, counts.large);
        counts.little++;
        counts.medium++;
        counts.large++;
    }
    printf("\n");
    printf("\n");
    printf("\n");
    struct counter2 counts2;
    counts2.little = 0;
    counts2.medium = 0;
    counts2.large = 0;

    for (int i =0; i<NUM_LOOP; i++){
        printf("\n%u , %u , %u", counts2.little, counts2.medium, counts2.large);
        counts2.little++;
        counts2.medium++;
        counts2.large++;   
    }

    printf("\nSize of counter: %lu", sizeof(counts));
    printf("\nSize of counter2: %lu", sizeof(counts2));

}