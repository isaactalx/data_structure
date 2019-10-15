#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__
namespace DS {

template <typename T>
int Partition(T array[], int low, int high) {
  std::swap(array[low], array[rand() % (high - low + 1) + low]);
  T tmp = array[low];
  int l = low + 1, r = high;  //双路快速排序
  while (true) {
    while (l <= high && array[l] < tmp) ++l;
    while (r >= low + 1 && array[r] > tmp) --r;
    if (l > r) {
      break;
    }
    std::swap(array[l], array[r]);
    l++;
    r--;
  }
  std::swap(array[low], array[r]);
  return r;
}

template <typename T>
void QuickSort(T array[], int low, int high) {
  if (low >= high) return;
  int pos = Partition(array, low, high);
  QuickSort(array, low, pos - 1);
  QuickSort(array, pos + 1, high);
}

template <typename T>
void QuickSort(T array[], int n) {
  QuickSort(array, 0, n - 1);
}
}  // namespace DS
#endif