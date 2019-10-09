#include "union_find_test.h"

int main() {
  DS::UnionFindTest test;
  int n = 10000;
  test.test_array(n);
  test.test_tree(n);
  test.test_tree2(n);
  return 0;
}