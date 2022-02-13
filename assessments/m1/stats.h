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
 * @file stats.h
 * @brief Header file for stats
 *
 * @author Joel Wasserman
 * @date 2/1/2022
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param unsigned char * arr Array of integers
 *
 * @return void
 */
void print_statistics(unsigned char arr[]);

/**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * @param unsigned char * arr Array of integers
 * @param unsigned int len Length of the array
 *
 * @return void
 */
void print_array(unsigned char arr[], unsigned int len);

/**
 * @brief Given an array of data and a length, returns the median value
 *
 * @param unsigned char * arr Array of integers
 * @param unsigned int len Length of the array
 *
 * @return int
 */
int find_median(unsigned char arr[], unsigned int len);

/**
 * @brief Given an array of data and a length, returns the mean
 *
 * @param unsigned char * arr Array of integers
 * @param unsigned int len Length of the array
 *
 * @return int
 */
int find_mean(unsigned char arr[], unsigned int len);

/**
 * @brief Given an array of data and a length, returns the maximum
 *
 * @param unsigned char * arr Array of integers
 * @param unsigned int len Length of the array
 *
 * @return int
 */
int find_maximum(unsigned char arr[], unsigned int len);

/**
 * @brief Given an array of data and a length, returns the minimum
 *
 * @param unsigned char * arr Array of integers
 * @param unsigned int len Length of the array
 *
 * @return int
 */
int find_minimum(unsigned char arr[], unsigned int len);

/**
 * @brief Sorts an array from largest to smallest
 *
 * @param unsigned char * arr Array of integers
 * @param unsigned int len Length of the array
 *
 * @return void
 */
void sort_array(unsigned char arr[], unsigned int len);

#endif /* __STATS_H__ */
