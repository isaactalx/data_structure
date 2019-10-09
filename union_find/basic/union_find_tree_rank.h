#ifndef __UNION_FIND_TREE_RANK__
#define __UNION_FIND_TREE_RANK__
#include <iostream>
#include "union_find_basic.h"
namespace DS {
class UnionFindTree2 : public UnionFind {
 public:
  UnionFindTree2(int n) {
    if (n <= 0) {
      std::cout << "input error!" << std::endl;
    }
    count = n;
    arrays = new int[count];
    ranks = new int[count];
    for (int i = 0; i < count; ++i) {  //初始化
      arrays[i] = i;
    }
    for (int i = 0; i < count; ++i) {
      ranks[i] = 1;
    }
  }
  virtual ~UnionFindTree2() { delete[] arrays; }
  virtual int Find(int p) {
    while (p != arrays[p]) {
      arrays[p]=arrays[arrays[p]]; // pass compression
      p = arrays[p];
    }
    return p;
  }
  virtual void Union(int p, int q) {  // quick union with rank
    int p_idx = Find(p);
    int q_idx = Find(q);
    if (p_idx == q_idx) {
      return;
    }
    if (ranks[p_idx] < ranks[q_idx]) {
      arrays[p_idx] = q_idx;
    } else if (ranks[q_idx] < ranks[p_idx]) {
      arrays[q_idx] = p_idx;
    } else {
      arrays[q_idx] = p_idx;
      ranks[p_idx]++;
    }
  }
  virtual bool IsConnected(int p, int q) { return Find(p) == Find(q); }

 private:
  int* arrays;
  int* ranks;
  int count;
};

}  // namespace DS

#endif