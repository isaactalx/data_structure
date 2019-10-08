#include "union_find_test.h"

int main(){
    DS::UnionFindTest test;
    test.test_array(50000);
    test.test_tree(50000);
    return 0;
}