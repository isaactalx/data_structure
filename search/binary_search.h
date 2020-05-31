#ifndef __BINARY_SEARCH__
#define __BINARY_SEATCH__

namespace DS {
template <typename T>
int binary_search(T array[], int length, T target) {
  int l = 0;
  int r = length - 1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (array[mid] == target) {
      return mid;
    }
    if (array[mid] > target) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return -1;
}

// recursion
template <typename T>
int binary_search_recursion(T array[], int left, int right, T target) {
  if (left > right) {
    return -1;
  }
  int mid = left + (right - left) / 2;
  if (array[mid] == target) {
    return mid;
  }
  if (array[mid] < target) {
    return binary_search_recursion(array, mid + 1, right, target);
  } else {
    return binary_search_recursion(array, left, mid - 1, target);
  }
}

}  // namespace DS

#endif