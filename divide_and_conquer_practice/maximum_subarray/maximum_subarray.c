#include "maximum_subarray.h"

MaximumEntity max_crossing_subarray(int *arr, int low, int mid, int high) {
    /* find the max index and max sum of the right part */
    int right_index = mid + 1;
    int max_sum_right = arr[mid+1];
    int total_sum_right = arr[mid+1];

    for (int i = mid+2; i <= high; i++) {
        total_sum_right += arr[i];
        if (total_sum_right > max_sum_right) {
            max_sum_right = total_sum_right;
            right_index = i;
        }
    }

    /* find the max index and max sum of the left part */
    int left_index = mid;
    int max_sum_left =arr[mid];
    int total_sum_left = arr[mid];

    for (int i = mid-1; i >= low; i--) {
        total_sum_left += arr[i];
        if (total_sum_left > max_sum_left) {
            max_sum_left = total_sum_left;
            left_index = i;
        }
    }
    

    MaximumEntity result;
    result.left_index = left_index;
    result.right_index = right_index;
    result.sum = max_sum_left + max_sum_right;

    return result;
}

MaximumEntity maximum_subarray_recursion(int *arr, int low, int high) {
    if (low == high) {
        return (MaximumEntity) {.left_index = low, .right_index = high, .sum = arr[low]};
    }

    int mid = (low + high) / 2;

    /* find maximum subarray of left half */
    MaximumEntity maximum_low = maximum_subarray_recursion(arr, low, mid);

    /* find maximum subarray across mid point */
    MaximumEntity maximum_crossing_mid = max_crossing_subarray(arr, low, mid, high);

    /* find maximum subarray of right half */
    MaximumEntity maximum_high = maximum_subarray_recursion(arr, mid + 1, high);

    if (maximum_low.sum >= maximum_crossing_mid.sum
            && maximum_low.sum >= maximum_high.sum)
        return maximum_low;

    if(maximum_crossing_mid.sum >= maximum_high.sum)
        return maximum_crossing_mid;

    return maximum_high;
}

MaximumEntity maximum_subarray_brute_force(int *arr, int size) {
    int left_index = 0;
    int right_index = 0;
    int max_sum = arr[0];

    for (int i = 0; i < size; i++) {
        int sum = arr[i];

        if (sum > max_sum) {
            left_index = i;
            right_index = i;
            max_sum = sum;
        }

        for (int j = i+1; j < size; j++) {
            sum += arr[j];
            if (sum > max_sum) {
                left_index = i;
                right_index = j;
                max_sum = sum;
            }
        }
    }

    return (MaximumEntity) {.left_index = left_index,
        .right_index = right_index, .sum = max_sum};

}
