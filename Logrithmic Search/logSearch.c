#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
  int lo = 0;
  int hi = n - 1;
  while (lo <= hi) {
    int mid = lo + ((hi - lo) / 2);
    if (arr[mid] == target)
      return mid;
    if (arr[mid] < target)
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  return -1;
}

int main() {
  int n = 4;
  int arr[] = {5, 10, 11, 15};
  printf("%d\n", binarySearch(arr, n, 10));
  printf("%d\n", binarySearch(arr, n, 21));
  printf("%d\n", binarySearch(arr, n, 5));
  printf("%d\n", binarySearch(arr, n, 15));
  printf("%d\n", binarySearch(arr, n, 11));
  return 0;
}