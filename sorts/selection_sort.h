#ifndef __SELECTION_SORT_H__
#define __SELECTION_SORT_H__
namespace DS {
template <typename T>
void SelectionSort(T array[], int n) {
  for (int i = 0; i < n; ++i) {
    int min_idx = i;
    for (int j = i + 1; j < n; ++j) {
      if (array[j] < array[min_idx]) {
        min_idx = j;
      }
    }
    std::swap(array[i], array[min_idx]);
  }
}
}  // namespace DS

#endif