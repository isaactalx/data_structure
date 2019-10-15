#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>
#include "insert_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
using namespace std;

void DataGenerator(int arr[], int n) {
  srand(time(NULL));
  for (int i = 0; i < n; ++i) {
    arr[i] = rand() % n;
  }
}

void DataPrint(int arr[], int n) {
  cout << "print data:" << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout<<endl;
}

template <typename T>
void CopyData(T arr1[], T arr2[], int n) {
  for (int i = 0; i < n; i++) {
    arr2[i] = arr1[i];
  }
}

template <typename T>
void DoSort(string name, void (*fn)(T[], int), T arr[], int len) {
  clock_t start_time = clock();
  fn(arr, len);
  clock_t end_time = clock();
  cout << "[func name: " << name << "] time consuming:"
       << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC << "s"
       << endl;
}

template <typename T>
bool IsSorted(T arr, int n) {
  for (int i = 1; i < n; ++i) {
    if (arr[i] < arr[i < 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  int n = 1000000;
  int* nums1 = new int[n];
  int* nums2 = new int[n];
  DataGenerator(nums1, n);
  CopyData(nums1, nums2, n);
 // DoSort("SelectonSort", DS::SelectionSort, nums1, n);
  DoSort("QuickSort", DS::QuickSort, nums1, n);
  DoSort("MergeSortIterative", DS::MergeSortIterative, nums2, n);
  
  // if (IsSorted(nums, n)) {
  //   cout << "sorted successfully!" << endl;
  // } else {
  //   cout << "failed to sort!" << endl;
  // }
  delete[] nums1;
  delete[] nums2;
  return 0;
}