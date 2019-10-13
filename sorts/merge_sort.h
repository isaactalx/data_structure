#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__
namespace DS {

template <typename T>
void Merge(T array[], int l, int mid, int r) {
  int *tmp=new(std::nothrow) int[r - l + 1];  //临时空间保存归并的结果,数据量太大时应该考虑堆上内存
  int l_idx = l, r_idx = mid + 1, tmp_idx = 0;
  while (l_idx <= mid && r_idx <= r) {  //两路归并
    if (array[l_idx] < array[r_idx]) {
      tmp[tmp_idx++] = array[l_idx++];
    } else {
      tmp[tmp_idx++] = array[r_idx++];
    }
  }
  while (l_idx <= mid) {
    tmp[tmp_idx++] = array[l_idx++];
  }
  while (r_idx <= r) {
    tmp[tmp_idx++] = array[r_idx++];
  }
  for (int i = l, k = 0; i <= r; ++i, ++k) {  //这里要注意
    array[i] = tmp[k];
  }
  delete[] tmp;
}

template <typename T>
void MergeSort(T array[], int l, int r) {
  if (l >= r) {  //序列过小时可用插入排序替代
    return;
  }
  int mid = l + (r - l) / 2;
  MergeSort(array, l, mid);
  MergeSort(array, mid + 1, r);
  Merge(array, l, mid, r);
}

template <typename T>
void MergeSort(T array[], int nums) {
  MergeSort(array, 0, nums - 1);
}

template <typename T>
void MergeSortIterative(T array[], int nums) { //归并排序的迭代实现(自底向上)
  for (int curr_size = 1; curr_size <= nums - 1; curr_size *= 2) {
    for (int left_start = 0; left_start < nums - 1;
         left_start += 2 * curr_size) {
      int mid = std::min(left_start + curr_size - 1, nums - 1);
      int r_end = std::min(left_start + 2 * curr_size - 1, nums - 1);
      Merge(array, left_start, mid, r_end);
    }
  }
}
}  // namespace DS
#endif