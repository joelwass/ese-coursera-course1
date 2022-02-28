#include "data.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  uint8_t count = 0;
  uint8_t temp2 = 0;
  bool isNegative = false;

  if (base == 2) {
    int32_t tmp = 0;
    for (int i = 31; i >= 0; i--) {
      tmp = data >> i;
      *(ptr + count) = tmp == 1 ? 1+'0' : 0+'0';
      count++;
    }
    *(ptr + count) = '\0';
  } else if (base == 16 || base == 10) {
    if (data < 0) {
      data = ~data + 1;
      isNegative = true;
    }
    while (data != 0) {
      int remainder = data % base;
      // 65 is 'A', 48 is 0. hex is base 16 which is numbers 0-9 and letters A-F;
      // we subtract 10 cause we want to start at A
      *(ptr + count) = (remainder > 9) ? (remainder - 10) + 65 : remainder + 48;
      data = data / base;
      count++;
    }
    if (isNegative){
			*(ptr + count) = 45;
			count++;
		}
    //code to reverse the the characters
		for (int i = 0; i < count/2; i++) {
			temp2 = *(ptr + i);
			*(ptr + i) = *(ptr + count - 1 - i);
			*(ptr + count - 1 - i) = temp2;
		}
		*(ptr + count) = '\0';
  }
  return count;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
  int32_t result = 0;
	int temp;
	int count = 0;

	//if it is a negative number in 2's compliment representation
	if(base == 2 && *ptr == '1')
	{
		temp = *ptr - '0';
		result = (result*base + temp)*(-1);
		count++;
		for (int i=0; i < digits-1; i++) {
			if(*(ptr+count) >= '0' && *(ptr+count) <= '9') {
				temp = *(ptr+count) - 48;
			}else{
				temp = *(ptr+count) - 65 + 10;
			}
      result = result * base + temp;
      count++;
		}
	//if it is a negative number in hex or base 10 format
	} else if ((base == 10 || base == 16) && *ptr == '-') {
		count++;
    // Minus 1 on the digits so we don't count the negative sign
		for(int i = 0; i < digits - 1; i++) {
			if (*(ptr+count) >= '0' && *(ptr+count) <= '9') {
				temp = *(ptr+count) - 48;
			} else {
				temp = *(ptr+count) - 65 + 10;
			}
      result = result * base + temp;
      count++;
		}
		result = -1 * result;
	//else it is a positive number(the procedure is the same for any base
	} else {
		for(int i=0; i<digits; i++) {
			if(*(ptr+count) >= '0' && *(ptr+count) <= '9') {
				temp = *(ptr+count) - '0';
			}else{
				temp = *(ptr+count) - '7';
			}
      result = result * base + temp;
      count++;
		}
	}

  return result;
}



