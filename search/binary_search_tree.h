#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

namespace DS {

template <typename K, typename V>
class BST {
 public:
  BST() : root_(nullptr), count_(0) {}
  ~BST() { destructor(root_); }
  void insert(K key, V value) { root_ = insert(root_, key, value); }
  bool contains(K key) {
    Node *p = root_;
    while (p != nullptr) {
      if (p->key_ == key) {
        return true;
      }
      if (p->key_ > key) {
        p = p->left;
      } else {
        p = p->right;
      }
    }
    return false;
  }
  V *search(K key) {
    Node *p = root_;
    while (p != nullptr) {
      if (p->key_ == key) {
        return &p->value_;
      }
      if (p->key_ > key) {
        p = p->left;
      } else {
        p = p->right;
      }
    }
    return nullptr;
  }
  int size() { return count_; }

 private:
  struct Node {
    Node(K key, V value) : key_(key), value_(value) {}
    K key_;
    V value_;
    Node *left = nullptr;
    Node *right = nullptr;
  };

  void destructor(Node *n) {
    if (n != nullptr) {
      destructor(n->left);
      destructor(n->right);
      delete n;
    }
  }
  Node *insert(Node *root, K key, V value) {
    if (root = nullptr) {
      root = new Node(key, value);
      count_++;
    } else if (root->key_ == key) {
      root->value_ = value;
    } else if (root->key_ > key) {
      root->left = insert(root_->left, key, value);
    } else {
      root->right = insert(root_->right, key, value);
    }

    return root;
  }

  // TODO insert recursion
  Node *root_;
  int count_;
};

}  // namespace DS

#endif