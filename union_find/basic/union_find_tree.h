#ifndef __UNION_FIND_TREE__
#define __UNION_FIND_TREE__
#include <iostream>
#include "union_find_basic.h"
namespace DS {
class UnionFindTree : public UnionFind {
 public:
  UnionFindTree(int n) {
    if (n <= 0) {
      std::cout << "input error!" << std::endl;
    }
    count = n;
    arrays = new int[count];
    for (int i = 0; i < count; ++i) {  //初始化
      arrays[i] = i;
    }
  }
  ~UnionFindTree() { delete[] arrays; }
  virtual int Find(int p) {
    while (p != arrays[p]) {
      p = arrays[p];
    }
    return p;
  }
  virtual void Union(int p, int q) {  // quick union
    int p_idx = Find(p);
    int q_idx = Find(q);
    if (p_idx == q_idx) {
      return;
    }
    arrays[q_idx] = p_idx;
  }
  virtual bool IsConnected(int p, int q) { return Find(p) == Find(q); }

 private:
  int* arrays;
  int count;
};

}  // namespace DS

#endif