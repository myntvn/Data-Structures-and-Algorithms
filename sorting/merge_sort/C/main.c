#include "merge_sort.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/* helper function to print the array */
void print_array(int[], int);

/* helper function to check if array is in sorted order */
void check_sorted(int arr[], int size);

int main (int argc, char const *argv[]) {

    /* get the size input from command line */
    const char *str = argv[1];
    int size = atoi(str);

    /* create an array with specified size */
    int arr[size];

    /* randomly initialize the array with integer from 0 to 99 */
    srand(time(0));
    for(size_t i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    /* print the array before sorting */
    printf("The initial array is: \n");
    print_array(arr, size);

    /* sort the array using merge sort */
    merge_sort(arr, 0, size - 1);

    /* print the sorted array */
    printf("The sorted array is:\n");
    print_array(arr, size);

    /* check if the sort procedure correct or not */
    check_sorted(arr, size);
}

void print_array(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void check_sorted(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        if(arr[i] > arr[i+1]) {
            printf("Wronggggggggg\n");
            return;
        }
    }

    printf("Correct!\n");
}
