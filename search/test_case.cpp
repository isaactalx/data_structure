#include "binary_search_tree.h"
#include <assert.h>
#include<string>
#include "file_reader.h"
#include <iostream>
using namespace std;
using DS::BST;

int main(){
    vector<string> words;
    FileOps::readFile("test_file.txt",words);
    BST<string,int> bst;
    for(const auto& word:words){
        int *value=bst.search(word);
        if(value!=nullptr){
            (*value)++;
        }else{
            bst.insert(word,1);
        }
    }

    cout<<words.size()<<","<<bst.size()<<endl;

}