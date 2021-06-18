#include "maximum_subarray.h"
#include <stdlib.h>
#include <time.h>

/*
 * Check the correctness of algorithms by using
 * infinite loop which generates random array and
 * check the result of recursion and brute-force
 * algorithms matching or not.
 */
void check_correctness();

/*
 * Find the size of array at which recursion
 * algorithm beats the brute-force algorithm
 */
void find_crossover_point();


int main() {
    /* int arr1[] = {40, -14, 2, -44, -7, 35, -21, 7, -31, 49};
    MaximumEntity res1 = maximum_subarray_brute_force(arr1, 10);
    printf("left %d ", res1.left_index);
    printf("right %d ", res1.right_index);
    printf("sum %d ", res1.sum);
    return 0; */

    printf("Press 1 to check correctness\n");
    printf("Press 2 to find the size at which recursion beats brute-force\n");

    char c;

    while((c = getchar()) != '1' && c != '2') {
        printf("Please input 1 or 2\n");
        getchar();
    }

    if (c == '1')
        check_correctness();
    else
        find_crossover_point();
    
    return 0;
}

void check_correctness() {
    srand(time(0));

    int size = 100;
    int arr[size];

    /* loop until get a wrong result or stopped by by user */
    printf("Checking the results of recursion and brute-force algorithm\n");
    for (int i = 1;; i++) {

        printf("\rTimes: %d", i);

        /* generate random array */
        for (size_t i = 0; i < size; i++) {
            arr[i] = (rand() % 101) - 50;
        }

        /* get the sub max array by recursion and brute-force algorithms */
        MaximumEntity rec_res = maximum_subarray_recursion(arr, 0, size - 1);
        MaximumEntity bf_res = maximum_subarray_brute_force(arr, size);

        /* stop if results from two algorithms mismatch */
        if (rec_res.sum != bf_res.sum) {
            printf("\nSomething went wrong!!!!!!\n");

            printf("\nThe array which gives wrong answer:\n");
            for (int j = 0; j < size; j++) {
                printf("%d  ", arr[j]);
            }

            printf("Resursion algorithm result: \n");
            printf("- left inex: %d\n", rec_res.left_index);
            printf("- right index: %d\n", rec_res.right_index);
            printf("- sum: %d\n", rec_res.sum);

            printf("\nBrute-force algorithm result: \n");
            printf("- left inex: %d\n", bf_res.left_index);
            printf("- right index: %d\n", bf_res.right_index);
            printf("- sum: %d\n", bf_res.sum);
            
            break;
        }

    }
}


void find_crossover_point() {

    clock_t start, end;

    double recursion_time, brute_force_time;

    int size = 10;

    while (1) {
        int arr[size];

        for (size_t i = 0; i < size; i++) {
            arr[i] = (rand() % 101) - 50;
        }

        start = clock();
        maximum_subarray_recursion(arr, 0, size - 1);
        end = clock();

        recursion_time = ((double) (end - start)) / CLOCKS_PER_SEC;

        start = clock();
        maximum_subarray_brute_force(arr, size);
        end = clock();

        brute_force_time = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("\nsize: %d ", size);
        printf("recursion_time %f ", recursion_time);
        printf("brute_force_time %f", brute_force_time);

        if (recursion_time < brute_force_time) {
            printf("\nThe size at which recursion beats brute-force is %d\n", size);
            break;
        } else {
            size += 1;
        }
    }

}
