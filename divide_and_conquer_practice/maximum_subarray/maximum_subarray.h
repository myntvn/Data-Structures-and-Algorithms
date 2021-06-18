#ifndef MAXIMUM_SUBARRAY
#define MAXIMUM_SUBARRAY

#include <stdio.h>

typedef struct {
    int left_index;
    int right_index;
    int sum;
} MaximumEntity;

/*
 * Find maximum subarray over the mid point
 */
MaximumEntity max_crossing_subarray(int *arr, int low, int mid, int high);

/*
 * Find maximum subarray: recursion version
 */
MaximumEntity maximum_subarray_recursion(int *arr, int low, int high);

/*
 * Find maximum subarray: brute-force version
 */
MaximumEntity maximum_subarray_brute_force(int *arr, int size);

#endif
