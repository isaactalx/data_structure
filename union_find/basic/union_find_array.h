#ifndef __UNION_FIND_ARRAY__
#define __UNION_FIND_ARRAY__
#include <iostream>
#include "union_find_basic.h"
namespace DS {
class UnionFindArray : public UnionFind {
 public:
  UnionFindArray(int n) {
    if (n <= 0) {
      std::cout << "input error!" << std::endl;
    }
    count = n;
    arrays = new int[count];
    for (int i = 0; i < count; ++i) {  //初始化
      arrays[i] = i;
    }
  }
  virtual ~UnionFindArray() { delete[] arrays; }
  virtual int Find(int p) { return arrays[p]; } //quick find
  virtual void Union(int p, int q) {
    int p_idx = arrays[p];
    int q_idx = arrays[q];
    if (p_idx == q_idx) {
      return;
    }
    for (int i = 0; i < count; ++i) {
      if (arrays[i] == q_idx) {
        arrays[i] = p_idx;
      }
    }
  }
  virtual bool IsConnected(int p, int q){
      return Find(p)==Find(q);
  }

 private:
  int* arrays;
  int count;
};

}  // namespace DS

#endif