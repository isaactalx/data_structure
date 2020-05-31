#include "binary_search.h"
#include <assert.h>

int main(){
    int nums[]={1,3,4,5,6,7,11,35,67};
    int idx=DS::binary_search_recursion(nums,0,8,1);
    assert(idx==0);
    int idx1=DS::binary_search_recursion(nums,0,8,45);
    assert(idx1==-1);


}