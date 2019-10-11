#ifndef __INSERT_SORT_H__
#define __INSERT_SORT_H__
namespace DS {
template <typename T>
void InsertSort(T array[], int n) {
  for (int i = 1; i < n; ++i) {
    T tmp = array[i];
    int j = i;
    while (j > 0 && array[j - 1] > tmp) {
      array[j] = array[j - 1];
      --j;
    }
    array[j] = tmp;
  }
}
}  // namespace DS
#endif