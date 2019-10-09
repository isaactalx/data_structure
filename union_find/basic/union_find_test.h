#ifndef __UNION_FIND_TEST__
#define __UNION_FIND_TEST__
#include <ctime>
#include <iostream>
#include "union_find_array.h"
#include "union_find_tree.h"
#include "union_find_tree_rank.h"
namespace DS {
class UnionFindTest {
 public:
  void test_array(int n) {
    DS::UnionFind* union_find = new DS::UnionFindArray(n);
    srand(time(NULL));
    time_t start_time = clock();
    for (int i = 0; i < n; ++i) {
      int a = rand() % n;
      int b = rand() % n;
      union_find->Union(a, b);
    }
    for (int i = 0; i < n; ++i) {
      int a = rand() % n;
      int b = rand() % n;
      // std::cout<<a<<"=="<<b<<std::endl;
      union_find->IsConnected(a, b);
    }
    time_t end_time = clock();
    std::cout << "UnionFind Arrays: number of n:" << n << " time consuming:"
              << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC
              << std::endl;
    delete union_find;
  }
  void test_tree(int n) {
    DS::UnionFind* union_find = new DS::UnionFindTree(n);
    srand(time(NULL));
    time_t start_time = clock();
    for (int i = 0; i < n; ++i) {
      int a = rand() % n;
      int b = rand() % n;
      union_find->Union(a, b);
    }
    for (int i = 0; i < n; ++i) {
      int a = rand() % n;
      int b = rand() % n;
      // std::cout<<a<<"=="<<b<<std::endl;
      union_find->IsConnected(a, b);
    }
    time_t end_time = clock();
    std::cout << "UnionFind Arrays: number of n:" << n << " time consuming:"
              << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC
              << std::endl;
    delete union_find;
  }

  void test_tree2(int n) {
    DS::UnionFind* union_find = new DS::UnionFindTree2(n);
    srand(time(NULL));
    time_t start_time = clock();
    for (int i = 0; i < n; ++i) {
      int a = rand() % n;
      int b = rand() % n;
      union_find->Union(a, b);
    }
    for (int i = 0; i < n; ++i) {
      int a = rand() % n;
      int b = rand() % n;
      // std::cout<<a<<"=="<<b<<std::endl;
      union_find->IsConnected(a, b);
    }
    time_t end_time = clock();
    std::cout << "UnionFind Arrays: number of n:" << n << " time consuming:"
              << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC
              << std::endl;
    delete union_find;
  }
};
}  // namespace DS
#endif