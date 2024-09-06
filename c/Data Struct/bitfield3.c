/*
    ~ this operator used to invert bit 
    uint8_t bit = 0x01;        // 0b00000001
    uint8_t invertBit = ~bit;  // 0b11111110
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t arrayOfBit = 0;

#define SET_BIT(BF, N) BF |= ((uint64_t)0x0000000000000001 << N) // BF = BF | ((uint64_t)0x0000000000000001 << N)
#define CLR_BIT(BF, N) BF &= ~((uint64_t)0x0000000000000001 << N) // BF = BF & ~((uint64_t)0x0000000000000001 << N)
#define IS_BIT_SET(BF, N)((BF >> N) & 0x01)

int main(void){
    SET_BIT(arrayOfBit, 0);
    SET_BIT(arrayOfBit, 4);
    SET_BIT(arrayOfBit, 34);
    SET_BIT(arrayOfBit, 23);
    SET_BIT(arrayOfBit, 56);
    SET_BIT(arrayOfBit, 14);
    SET_BIT(arrayOfBit, 63);

    CLR_BIT(arrayOfBit, 34);
    for (int i =0; i<64; i++){
        if (IS_BIT_SET(arrayOfBit, i)){
            printf("+");
        }else {
            printf(".");
        }
    }
    printf("\n%d", arrayOfBit);
    printf("\n size of array : %lu", sizeof(arrayOfBit));

    return 0;
}