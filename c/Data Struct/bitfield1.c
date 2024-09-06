/* & operator working 
    00000001        01110010
  & 00000001      & 00101001
  = 00000001      = 00100000

    00000010
  & 00000001
  = 00000000
  
IF YOU KNOW YOU KNOW :)
*/

#include <stdint.h>
#include <stdio.h>

#define PRINT_NAME 0x01      // 0b00000001
#define PRINT_CODENAME 0x02  // 0b00000010
#define PRINT_POSITION 0x04  // 0b00000100
#define PRINT_ALT_SKILL 0x08 // 0b00001000
#define PRINT_ALL 0xFF       // 0b11111111

void print(uint8_t options){
    if (options & PRINT_NAME){printf("Name is Gokul\n");}
    if (options & PRINT_CODENAME){printf("Codename is Osmic\n");}
    if (options & PRINT_POSITION) {printf("Position is Dev\n");}
    if (options & PRINT_ALT_SKILL){printf("Alt Skill is Trader\n");}

}

int main(void){
    print(PRINT_ALL);
    return 0;
}