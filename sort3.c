#include <stdio.h>
// Function to merge two sorted subarrays
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
   int i = 0, j = 0, k = 0;
   // Merge elements of left[] and right[] in arr[]
   while (i < leftSize && j < rightSize) {
      if (left[i] <= right[j]) arr[k++] = left[i++];
      else arr[k++] = right[j++];
    }
    // Copy any remaining elements of left[]
    while (i < leftSize) arr[k++] = left[i++];
    // Copy any remaining elements of right[]
    while (j < rightSize) arr[k++] = right[j++];
  }

  // Recursive function to perform merge sort
  void mergeSort(int arr[], int size) {
    if (size < 2) return;
    int mid = size / 2;
    int left[mid];
    int right[size - mid];
    // Fill left subarray
    for (int i = 0; i < mid; i++) left[i] = arr[i];
    // Fill right subarray
    for (int i = mid; i < size; i++) right[i - mid] = arr[i];
    // Recursively sort left and right subarrays
    mergeSort(left, mid);
    mergeSort(right, size - mid);
    // Merge the two sorted subarrays
    merge(arr, left, mid, right, size - mid);
  }

  // Function to print an array
  void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
  }

  int main() {
    int arr[] = {5, 2, 10, 9, 1, 7, 4};
    // int sizeofarr = sizeof(arr);
    // int sizeofarr0 = sizeof(arr[0]);
    int size = sizeof(arr) / sizeof(arr[0]);
    // printf("sizeof(arr): %i\n",sizeofarr);
    // printf("sizeof(arr[0]): %i\n",sizeofarr0);
    printf("Original array: ");
    printArray(arr, size);
    mergeSort(arr, size);
    printf("Sorted array: ");
    printArray(arr, size);
    return 0;
  }
