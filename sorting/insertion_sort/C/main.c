#include "insertion_sort.h"
#include <stdlib.h>
#include <time.h>

void print_array(int[], int);

int main(int argc,char const *argv[]) {

  /* get the size from command line */
  const char *str = argv[1];
  int size = atoi(str);

  /* initialize an array with specified size */
  int arr[size];

  /* randomly initialize the array with integer from 0 to 99 */
  srand(time(0));
  for (size_t i = 0; i < size; i++) {
    arr[i] = rand() % 100;
  }

  /* print the array before sorting */
  printf("The initial array is:\n");
  print_array(arr, size);

  /* sort the array of integers by insertion sort*/
  insertion_sort(arr, size);

  /* print the sorted array */
  printf("The sorted array is:\n");
  print_array(arr, size);

  return 0;
}

void print_array(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
