#include <cassert>
#include <iostream>
#include <queue>
#include <memory>
#include <vector>


using std::cout;
using std::endl;
using std::equal;
using std::move;
using std::queue;
using std::unique_ptr;
using std::vector;

vector<vector<int>> results;
vector<int> one_line_result;

template <typename T>
struct BinaryTreeNode {
T data;
unique_ptr<BinaryTreeNode<T>> left, right;
};

// @include
void PrintBinaryTreeDepthOrder(const unique_ptr<BinaryTreeNode<int>>& root) {
    std::queue<  BinaryTreeNode<int> * > q;
    q.push(root.get() );
    while (!q.empty()) {
        BinaryTreeNode<int>* node = q.front();
        q.pop();
        if (!node) continue;
        //one_line_result.push_back( node->data );
        q.push(node->left.get());
        q.push(node->right.get());
    }

    
}
// @exclude

int main(int argc, char* argv[]) {
  //      3
  //    2   5
  //  1    4 6
  unique_ptr<BinaryTreeNode<int>> root = unique_ptr<BinaryTreeNode<int>>(
      new BinaryTreeNode<int>{3, nullptr, nullptr});
  root->left = unique_ptr<BinaryTreeNode<int>>(
      new BinaryTreeNode<int>{2, nullptr, nullptr});
  root->left->left = unique_ptr<BinaryTreeNode<int>>(
      new BinaryTreeNode<int>{1, nullptr, nullptr});
  root->right = unique_ptr<BinaryTreeNode<int>>(
      new BinaryTreeNode<int>{5, nullptr, nullptr});
  root->right->left = unique_ptr<BinaryTreeNode<int>>(
      new BinaryTreeNode<int>{4, nullptr, nullptr});
  root->right->right = unique_ptr<BinaryTreeNode<int>>(
      new BinaryTreeNode<int>{6, nullptr, nullptr});
  // should output 3
  //               2 5
  //               1 4 6
  PrintBinaryTreeDepthOrder(root);
  vector<vector<int>> golden_res = {{3}, {2, 5}, {1, 4, 6}};
  assert(golden_res.size() == results.size() &&
         equal(golden_res.begin(), golden_res.end(), results.begin()));
  return 0;
}
