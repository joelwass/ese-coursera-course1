/******************************************************************************
 * Copyright (C) 2022 by Joel Wasserman 
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Main file 
 *
 * Implementation of methods to analyze an array of unsigned char data items 
 * and report analytics on the maximum, minimum, mean, and median of the data set
 *
 * @author Joel Wasserman
 * @date 2/1/2022
 *
 */



#include <stdio.h>
#include <limits.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

void print_statistics(unsigned char arr[]) {
  printf("median: %d%c", find_median(arr, SIZE), '\n');
  printf("mean: %d%c", find_mean(arr, SIZE), '\n');
  printf("minimum: %d%c", find_minimum(arr, SIZE), '\n');
  printf("maximum: %d%c", find_maximum(arr, SIZE), '\n');
	printf("Sorting array...\n");
  sort_array(arr, SIZE);
	print_array(arr, SIZE);
  return;
}

void print_array(unsigned char arr[], unsigned int len) {
  #ifdef VERBOSE
					int i = 0;
					printf("Printing array contents:%c", '\n');
					for (i = 0; i < len; i++) {
						printf("%d ", arr[i]);
					}
					printf("\n");
  #endif
}

int find_median(unsigned char arr[], unsigned int len) {
  // sort the array
  sort_array(arr, len); 
  
  if (len%2 == 0) {
    return (arr[(len-1)/2] + arr[len/2]) / 2.0;
  } else {
    return arr[len/2];
  }
}

int find_mean(unsigned char arr[], unsigned int len) {
  int i=0, sum=0;
  
  // sum up all values of the array
  for (i=0; i < len; i++) {
    sum += arr[i];
  }

  return sum / len;
}

int find_maximum(unsigned char arr[], unsigned int len) {
  int i=0, max=-1;

  for (i=0; i < len; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  return max;
}

int find_minimum(unsigned char arr[], unsigned int len) {
  int i=0, min=INT_MAX;

  for (i=0; i < len; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }

  return min;
}

void sort_array(unsigned char arr[], unsigned int len) {
  int i=0, j=0, temp=0;

  for (i=0 ; i< len ; i++) {
    for (j=0 ; j< len-1 ; j++) {
      if (arr[j]>arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}


