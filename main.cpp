#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
//Google : cplusplus, stackoverflow, geeksforgeeks

#include "includes.h"

using namespace std;

int main(int argc, char **argv) {
  int testID = 1;

  if (argc < 2) {
    printf("use default testID %d", testID);
  } else {
    testID = atoi(argv[1]);
  }

  switch (testID) {
  case 0:
    printf("hello world\n");
    break;
  case 1:
    basic_binaryTree_creation_breathFirst();
    break;
  case 2:
    basic_binaryTree_creation_depthFirst();
    break;
  default:
    printf("not a supported testID %d\n", testID);
    exit(-1);
  }

  // data structure - binary tree
  //  binary tree (BT) creation - DF, BF
  //  BT traversal- DF

  // recursive
  //  top-down programming (backtracking)

  // class polymorphism
}

struct STreeNode {
  int val;
  STreeNode *left;
  STreeNode *right;

  STreeNode() : val(0), left(nullptr), right(nullptr) {}
  STreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// BT : complete, balanced tree
//    balanced : diff between depth of left tree and depth of right tree <= 1
//    complete : log( number of nodes) == maximum depth no
//          For example: data size = 6 , log(6) = 2.x
//               7     d= 0
//              / \
//             9   1   d= 1
//            / \    \
//           5   4    2  d= 2

void printNodes(vector<STreeNode> &nodes) {
  for (auto &ir : nodes) {
    printf("val=%d ", ir.val);
    if (ir.left)
      printf("left = %d ", ir.left->val);
    else
      printf("left = null ");

    if (ir.right)
      printf("right = %d ", ir.right->val);
    else
      printf("right = null ");

    printf("\n");
  }
  printf("\n");
}

STreeNode *createBFTree(vector<STreeNode> &nodes) {
  // METHOD 1: recursive programming (X)
  // METHOD 2: using index relationship to create tree

  for (int i = 1; i < nodes.size(); i++) {
    if (i % 2) {
      int parentIdx = (i - 1) / 2;
      nodes[parentIdx].left = &(nodes[i]);
    } else {
      int parentIdx = (i - 2) / 2;
      nodes[parentIdx].right = &(nodes[i]);
    }
  }

  return &(nodes[0]);
}

void basic_binaryTree_creation_breathFirst() {
  vector<int> vals({8, 5, 3, 2, 9, 1});

  // Breath-first / level-first binary tree
  //     8(0)
  //    /      \
  //   5(1)     3(2)
  //  /   \      /    \
  // 2(3) 9(4)  1(5)   null(6)

  // METHOD 1: allocation memory along initialization
  // METHOD 2: allocation memory at once

  vector<STreeNode> nodes;
  for (auto &ir : vals) {
    nodes.push_back(STreeNode(ir));
  }

  STreeNode *root = createBFTree(nodes);
  printf("root value = %d\n", root->val);
  printNodes(nodes);
}

STreeNode* createDFPreOrderRec(vector<STreeNode>&  nodes, int maxDepthNo, int depth, int & dataIdx)
{
  // f(x) = {root} + f(root->left) + f(root->right)
  STreeNode *root = nullptr;

  //excetion
  if(depth == maxDepthNo){
    if(dataIdx < nodes.size()){
      root = &(nodes[dataIdx]);
      dataIdx++;
    }
    return root;
  }

  //general
  root = &(nodes[dataIdx]);
  dataIdx++;

  root->left = createDFPreOrderRec(nodes, maxDepthNo, depth+1, dataIdx);
  root->right = createDFPreOrderRec(nodes, maxDepthNo, depth+1, dataIdx);
  
  return root; 
}




STreeNode* createDFTree_PreOrder(vector<STreeNode>& nodes)
{
  STreeNode* root= nullptr;
  int maxDepthNo = (int)log2((double)nodes.size());
  // Depth-first binary tree 1) Pre-order traversal  : Root, Left, Right
  //      8(0)
  //    /      \
  //   5(1)     9(4)
  //  /   \      /    \
  // 3(2) 2(3)  1(5)   null(6)
  
  //input/condition: maxDepthNo
  //output (return, reference) : return root
  //variables among iterations: depth, dataIdx
  // f(x) = {root} + f(root->left) + f(root->right)
  int depth = 0;
  int dataIdx = 0;
  root = createDFPreOrderRec(nodes, maxDepthNo, depth, dataIdx);
  return root;
}


STreeNode* createDFTree_InOrder(vector<STreeNode>& nodes){
  STreeNode* root= nullptr;
  //HW0829
  return root;
}
STreeNode* createDFTree_PostOrder(vector<STreeNode>& nodes){
  STreeNode* root= nullptr;
  //HW0829
  return root;
}


void basic_binaryTree_creation_depthFirst(){
  vector<int> vals({8, 5, 3, 2, 9, 1});
  vector<STreeNode> nodes;
  STreeNode* root = nullptr;

  printf("== Depth First: Pre-order ==\n");
  // Depth-first binary tree 1) Pre-order traversal  : Root, Left, Right
  //      8(0)
  //    /      \
  //   5(1)     9(4)
  //  /   \      /    \
  // 3(2) 2(3)  1(5)   null(6)
  for (auto &ir : vals) {
    nodes.push_back(STreeNode(ir));
  }
  root = createDFTree_PreOrder(nodes);
  printf("root value = %d\n", root->val);
  printNodes(nodes);
  

  printf("== Depth First: In-order ==\n");
  // Depth-first binary tree 2) In-order traversal : Left, Root, Right
  //      2(3)
  //    /      \
  //   5(1)     1(5)
  //  /   \      /    \
  // 8(0) 3(2)  9(4)   null(6)
  nodes.clear();
  for (auto &ir : vals) {
    nodes.push_back(STreeNode(ir));
  }
  root = createDFTree_InOrder(nodes);
  printf("root value = %d\n", root->val);
  printNodes(nodes);

  printf("== Depth First: Post-order ==\n");
  // Depth-first binary tree 3) Post-order traversal : Left, Right, Root
  //      null(6) ?
  //    /        \
  //   3(2)      1(5)
  //  /   \      /   \
  // 8(0) 5(1)  2(3)   9(4)

  //      1(5)
  //    /      \
  //   3(2)      9(4)
  //  /   \      /   \
  // 8(0) 5(1)  2(3)
  nodes.clear();
  for (auto &ir : vals) {
    nodes.push_back(STreeNode(ir));
  }
  root = createDFTree_PostOrder(nodes);
  printf("root value = %d\n", root->val);
  printNodes(nodes);
  
}