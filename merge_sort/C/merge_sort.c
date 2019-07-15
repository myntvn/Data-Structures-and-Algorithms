#include "merge_sort.h"

void merge(int *arr, int p, int q, int r) {
    /* left half size */
    int n1 = q - p + 1;
    /* right half size */
    int n2 = r - q;

    /* left half with one more element for sentinel - the infinity */
    int left[n1+1];

    /* right half with one more element for sentinel - the infinity */
    int right[n2+1];

    /* copy from p to q of arr to the left array */
    for(int i = 0; i < n1; i++) {
        left[i] = arr[p+i];
    }
    /* set sentinel at last element */
    left[n1] = INT_MAX;

    /* copy from q+1 to r from arr to the right array */
    for (int i = 0; i < n2; i++) {
        right[i] = arr[q+1+i];
    }
    /* set sentinel at last element */
    right[n2] = INT_MAX;

    int i = 0;
    int j = 0;

    for(int k = p; k <= r; k++) {
        if(left[i] < right[j]) {
            arr[k] = left[i++];
        } else {
            arr[k] = right[j++];
        }
    }
}

void merge_sort(int *arr, int p, int r) {
    /* if the array has more than one element */
    if(p < r) {
        int q = (p + r) / 2;

        /* sort the left half */
        merge_sort(arr, p, q);

        /* sort the right half */
        merge_sort(arr, q+1, r);

        /* merge two sorted array */
        merge(arr, p, q, r);
    }
}
