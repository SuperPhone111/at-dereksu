#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
// Google : cplusplus, stackoverflow, geeksforgeeks

#include "includes.h"

using namespace std;

int main(int argc, char **argv) {
  int testID = 11;

  if (argc < 2) {
    printf("use default testID %d\n", testID);
  } else {
    testID = atoi(argv[1]);
  }

  switch (testID) {
  case 0:
    printf("hello world\n");
    break;
  case 1: // binary tree - BF creation
    basic_binaryTree_creation_breathFirst();
    break;
  case 2: // binary tree- DF creation (1D -> tree)
    basic_binaryTree_creation_depthFirst();
    break;
  case 3: // binary tree- DF traversal (tree -> 1D)
    basic_binaryTree_traversal();
    break;
  case 5:
    leetcode_balanced_tree();
    break;
  case 6:
    leetcode_recursive_leafs();
    break;
  case 7:
    leetcode_bt_distanceK();
    break;
  case 8: // recursive, backtracking, caching
    leetcode_fibonacci_seq();
    break;
  case 9:
    leetcode_functionParsing();
    break;
  case 10: // heapify
    basic_heapify();
    break;
  case 11: // heap sort
    basic_heap_sort();
    break;
  case 12:
    leetcode_bt_findKthMin();
    break;
  case 14: // pivot partiion
    basic_pivot_partitioning();
    break;
  case 15: // quick Sort
    basic_quickSort();
    break;
  case 16:
    leetcode_merge_sorted_lists();
    break;
  case 17:
    basic_mergeSort();
    break;
    // digit processing
  case 18:
    leetcode_revert_integer();
    break;
  case 19:
    leetcode_even_odd_diff();
    break;
  case 20:
    leetcode_bits_resersal();
    break;
  case 21:
    leetcode_print_decimal_in_binary();
    break;

  // unordered_map, map, unordered_set, set
  // recursive example and principles
  default:
    printf("not a supported testID %d\n", testID);
    exit(-1);
  }
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

void heapifyMaxHeap(vector<int> &vecData, int rootIdx) {
  // exception

  // general :
  //  f(parent):
  //  if parent is the max node => end
  //  otherwise :  swap parent and max node => f(max node)

  // shift down
  int maxIdx = rootIdx;
  // compare w/ left
  int childIdx = 2 * rootIdx + 1;
  if (childIdx < vecData.size()) {
    if (vecData[childIdx] > vecData[maxIdx]) {
      maxIdx = childIdx;
    }
  }

  // compare w/ right
  childIdx = 2 * rootIdx + 2;
  if (childIdx < vecData.size()) {
    if (vecData[childIdx] > vecData[maxIdx]) {
      maxIdx = childIdx;
    }
  }

  if (maxIdx != rootIdx) {
    // swap
    int tmp = vecData[maxIdx];
    vecData[maxIdx] = vecData[rootIdx];
    vecData[rootIdx] = tmp;

    // recursive call
    heapifyMaxHeap(vecData, maxIdx);
  }
}

void buildMaxHeap(vector<int> &vecData) {
  // d=0 =>1              5(0)
  //                     /    \
  // d=1 =>1+2        4(1)    1(2)
  //                 /   \      /   \
  // d=2 =>1+2+4   9(3)  2(4)  3(5)  null(6)
  //
  // d= 3 => 1+2+4+8

  // int depth = (int)log2((double)vecData.size());
  int maxTestNodes = 0;

  // for (int i = 0; i < depth; i++) {
  //   maxTestNodes += (1 << i);
  // }
  maxTestNodes = (vecData.size() - 1 - 1) / 2;
  // printf("maxTestNodes = %d\n", maxTestNodes);

  // for (int idx = maxTestNodes - 1; idx >= 0; idx--) {
  for (int idx = maxTestNodes; idx >= 0; idx--) {
    heapifyMaxHeap(vecData, idx);
  }
}

void basic_heapify() {
  vector<int> vecData({5, 4, 1, 9, 2, 3});
  //      5(0)
  //      /    \
  //    4(1)    1(2)
  //   /   \      /   \
  //  9(3)  2(4)  3(5)  null(6)
  printf("== input data ==\n");
  for (auto &ir : vecData)
    printf("%d ", ir);
  printf("\n");

  printf("== Heapify (max heap) ==\n");
  // build max/min heapfied tree : O(NlogN)
  // Hepaify a heapified tree : O(logN)
  buildMaxHeap(vecData);
  for (auto &ir : vecData)
    printf("%d ", ir);
  printf("\n");

  printf("== Re-Heapify (max heap) ==\n");
  // log(N)
  vecData.erase(vecData.begin());
  vecData.insert(vecData.begin(), vecData.back());
  vecData.pop_back();
  heapifyMaxHeap(vecData, 0);
  for (auto &ir : vecData)
    printf("%d ", ir);
  printf("\n");
}

void basic_heap_sort() {
  vector<int> data({6, 2, 8, 1, 0, 7, 3});

  // HW0919: heap sort / ascending sort

  // build min heap: O(NlogN)
  // N heapify : O(NlogN)

  buildMaxHeap(data);

  printf("== Max Heap built ==\n");
  for (auto &val : data)
    printf("%d ", val);
  printf("\n");

  for (int i = data.size() - 1; i > 0; --i) {
    swap(data[0], data[i]);

    vector<int> subVec(data.begin(), data.begin() + i);
    heapifyMaxHeap(subVec, 0);

    copy(subVec.begin(), subVec.end(), data.begin());

    printf("== After re-heapify (i = %d) ==\n", i);
    for (auto &val : data)
      printf("%d ", val);
    printf("\n");
  }

  printf("== Sorted data (Ascending) ==\n");
  for (auto &val : data)
    printf("%d ", val);
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

  // METHOD 1: allocation memory along initialization (X)
  // METHOD 2: allocation memory at once (O)

  vector<STreeNode> nodes;
  for (auto &ir : vals) {
    nodes.push_back(STreeNode(ir));
  }

  STreeNode *root = createBFTree(nodes);
  printf("root value = %d\n", root->val);
  printNodes(nodes);
}

STreeNode *createDFPreOrderRec(vector<STreeNode> &nodes, int maxDepthNo,
                               int depth, int &dataIdx) {
  // f(x) = {root} + f(root->left) + f(root->right)
  STreeNode *root = nullptr;

  // excetion
  if (depth == maxDepthNo) {
    if (dataIdx < nodes.size()) {
      root = &(nodes[dataIdx]);
      dataIdx++;
    }
    return root;
  }

  // general
  root = &(nodes[dataIdx]);
  dataIdx++;

  root->left = createDFPreOrderRec(nodes, maxDepthNo, depth + 1, dataIdx);
  root->right = createDFPreOrderRec(nodes, maxDepthNo, depth + 1, dataIdx);

  return root;
}

STreeNode *createDFPreOrderRec(vector<STreeNode> &nodes, int startIdx,
                               int endIdx) {
  //  f(x) = {root} + f(root->left) + f(root->right)
  //   startIdx        startIdx +1              endIdx
  STreeNode *root = nullptr;
  // exception
  // only one node
  if (startIdx == endIdx) {
    return &(nodes[startIdx]);
  }
  // only two nodes
  if (startIdx + 1 == endIdx) {
    nodes[startIdx].left = &(nodes[endIdx]);
    return &(nodes[startIdx]);
  }

  // general case
  int rootIdx = startIdx;
  root = &(nodes[rootIdx]);

  int len = endIdx - (startIdx + 1) + 1;

  root->left =
      createDFPreOrderRec(nodes, startIdx + 1, startIdx + 1 + len / 2 - 1);
  root->right = createDFPreOrderRec(nodes, startIdx + 1 + len / 2, endIdx);

  return root;
}

STreeNode *createDFTree_PreOrder(vector<STreeNode> &nodes) {
  STreeNode *root = nullptr;

  enum IMPLT_ID_ {
    IMPLT_MAXDEPTH = 0,
    IMPLT_DIV_N_CONQ,
  };

  int impltID = IMPLT_DIV_N_CONQ;

  if (impltID == IMPLT_MAXDEPTH) {
    int maxDepthNo = (int)log2((double)nodes.size());
    // Depth-first binary tree 1) Pre-order traversal  : Root, Left, Right
    //      8(0)
    //    /      \
    //   5(1)     9(4)
    //  /   \      /    \
    // 3(2) 2(3)  1(5)   null(6)

    // input/condition: maxDepthNo
    // output (return, reference) : return root
    // variables among iterations: depth, dataIdx
    //  f(x) = {root} + f(root->left) + f(root->right)
    int depth = 0;
    int dataIdx = 0;
    root = createDFPreOrderRec(nodes, maxDepthNo, depth, dataIdx);
  } else if (impltID == IMPLT_DIV_N_CONQ) {
    // Depth-first binary tree 1) Pre-order traversal  : Root, Left, Right
    //      8(0)
    //    /         \
    //   5(1)         2(3)
    //  /   \         /    \
    // 3(2) null(6)   9(4)  1(5)
    //
    //  f(x) = {root} + f(root->left) + f(root->right)
    //         {  8 ,    5, 3, 2,        4, 1         }
    //
    // (1) input /condition : startIdx, endIdx, nodes
    // (2) output : return root
    // (3) variable among iterations :
    int startIdx = 0;
    int endIdx = nodes.size() - 1;
    root = createDFPreOrderRec(nodes, startIdx, endIdx);

  } else {
    printf("Not a supported implementation ID : %d\n", impltID);
    exit(-1);
  }

  return root;
}

STreeNode *createDFInOrderRec(vector<STreeNode> &nodes, int maxDepthNo,
                              int depth, int &dataIdx) {
  // f(x) = f(root->left) + {root} + f(root->right)
  STreeNode *root = nullptr;
  // if (depth > maxDepthNo || dataIdx >= nodes.size()) {
  //   return nullptr;
  // }
  if (depth == maxDepthNo) {
    if (dataIdx < nodes.size()) {
      root = &(nodes[dataIdx]);
      dataIdx++;
    }
    return root;
  }

  STreeNode *left = createDFInOrderRec(nodes, maxDepthNo, depth + 1, dataIdx);

  root = &nodes[dataIdx++];
  root->left = left;

  STreeNode *right = createDFInOrderRec(nodes, maxDepthNo, depth + 1, dataIdx);
  root->right = right;

  return root;
}

STreeNode *createDFInOrderRec(vector<STreeNode> &nodes, int startIdx,
                              int endIdx) {
  //  f(x) =  f(root->left) + {root} + f(root->right)

  STreeNode *root = nullptr;
  // exception
  // only one node
  if (startIdx == endIdx) {
    return &(nodes[startIdx]);
  }

  // only two nodes
  if (startIdx + 1 == endIdx) {
    nodes[endIdx].left = &(nodes[startIdx]);
    return &(nodes[endIdx]);
  }

  // general case
  int rootIdx = startIdx + (endIdx - startIdx + 1) / 2;
  root = &(nodes[rootIdx]);

  root->left = createDFInOrderRec(nodes, startIdx, rootIdx - 1);
  root->right = createDFInOrderRec(nodes, rootIdx + 1, endIdx);

  return root;
}

STreeNode *createDFTree_InOrder(vector<STreeNode> &nodes) {
  STreeNode *root = nullptr;

  enum IMPLT_ID_ {
    IMPLT_MAXDEPTH = 0,
    IMPLT_DIV_N_CONQ,
  };

  int impltID = IMPLT_DIV_N_CONQ;

  if (impltID == IMPLT_MAXDEPTH) {
    int maxDepthNo = (int)log2((double)nodes.size());
    // HW0829
    // vector<int> vals({8, 5, 3, 2, 9, 1});
    // Depth-first binary tree 2) In-order traversal : Left, Root, Right
    //      2(3)
    //    /      \
    //   5(1)     1(5)
    //  /   \      /    \
    // 8(0) 3(2)  9(4)   null(6)
    int depth = 0;
    int dataIdx = 0;
    root = createDFInOrderRec(nodes, maxDepthNo, depth, dataIdx);
  } else if (impltID == IMPLT_DIV_N_CONQ) {

    // vector<int> vals({8, 5, 3, 2, 9, 1});
    // Depth-first binary tree 2) In-order traversal : Left, Root, Right
    //      2(3)
    //    /      \
    //   5(1)     1(5)
    //  /   \      /    \
    // 8(0) 3(2)  9(4)   null(6)
    int startIdx = 0;
    int endIdx = nodes.size() - 1;
    root = createDFInOrderRec(nodes, startIdx, endIdx);

  } else {
    printf("Not a supported implementation ID : %d\n", impltID);
    exit(-1);
  }

  return root;
}

STreeNode *createDFPostOrderRec(vector<STreeNode> &nodes, int maxDepthNo,
                                int depth, int &dataIdx) {
  // f(x) = f(root->left) + {root->right} + f(root)
  STreeNode *root = nullptr;
  if (depth > maxDepthNo || dataIdx >= nodes.size()) {
    return nullptr;
  }

  STreeNode *left = createDFPostOrderRec(nodes, maxDepthNo, depth + 1, dataIdx);
  STreeNode *right =
      createDFPostOrderRec(nodes, maxDepthNo, depth + 1, dataIdx);

  root = &nodes[dataIdx];
  root->left = left;
  root->right = right;
  dataIdx++;

  return root;
}
STreeNode *createDFPostOrderRec(vector<STreeNode> &nodes, int startIdx,
                                int endIdx) {
  // f(x) = f(root->left) + {root->right} + {root}
  //  left, right root
  STreeNode *root = nullptr;

  // exception
  // only one node
  if (startIdx == endIdx) {
    return &(nodes[startIdx]);
  }

  // only two nodes
  if (startIdx + 1 == endIdx) {
    nodes[endIdx].left = &(nodes[startIdx]);
    return &(nodes[endIdx]);
  }

  // general case
  int rootIdx = endIdx;
  root = &(nodes[rootIdx]);
  int len = (endIdx - 1) - startIdx + 1;

  root->left = createDFPostOrderRec(nodes, startIdx, startIdx + len / 2 - 1);
  root->right = createDFPostOrderRec(nodes, startIdx + len / 2, endIdx - 1);

  return root;
}

STreeNode *createDFTree_PostOrder(vector<STreeNode> &nodes) {
  STreeNode *root = nullptr;

  enum IMPLT_ID_ {
    IMPLT_MAXDEPTH = 0,
    IMPLT_DIV_N_CONQ,
  };

  int impltID = IMPLT_DIV_N_CONQ;

  if (impltID == IMPLT_MAXDEPTH) {
    int maxDepthNo = (int)log2((double)nodes.size());
    // HW0829
    // vector<int> vals({8, 5, 3, 2, 9, 1});
    // Depth-first binary tree 3) Post-order traversal : Left, Right, Root
    //      null(6) ?
    //    /        \
  //   3(2)      1(5)
    //  /   \      /   \
  // 8(0) 5(1)  2(3)   9(4)

    // Derek how to construct this tree ??
    //      1(5)
    //    /      \
  //   3(2)      9(4)
    //  /   \      /   \
  // 8(0) 5(1)  2(3)
    int depth = 0;
    int dataIdx = 0;
    root = createDFPostOrderRec(nodes, maxDepthNo, depth, dataIdx);
  } else if (impltID == IMPLT_DIV_N_CONQ) {
    //      1(5)
    //    /      \
    //   5(1)      9(4)
    //  /   \      /   \
    // 8(0)  null  3(2)  2(3)
    int startIdx = 0;
    int endIdx = nodes.size() - 1;
    root = createDFPostOrderRec(nodes, startIdx, endIdx);

  } else {
    printf("Not a supported implementation ID : %d\n", impltID);
    exit(-1);
  }

  return root;
}

void basic_binaryTree_creation_depthFirst() {
  vector<int> vals({8, 5, 3, 2, 9, 1});
  vector<STreeNode> nodes;
  STreeNode *root = nullptr;

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

vector<int> traverseBTPreOrder(STreeNode *root) {

  //       8
  //    /     \
  //   5        3
  //  /   \    /
  // 2    9   1

  // Pre-order traversal : root, left, right:  {8, 5, 2, 9, 3, 1}
  //   f(x) = {root} + f(x->left) + f(x->right)
  vector<int> traversed;

  // exception
  if (root == nullptr)
    return traversed;

  // general
  traversed.push_back(root->val);

  vector<int> leftTraversed = traverseBTPreOrder(root->left);
  // traversed + leftTraversed
  traversed.insert(traversed.end(), leftTraversed.begin(), leftTraversed.end());

  vector<int> rightTraversed = traverseBTPreOrder(root->right);
  //+ rightTraversed
  traversed.insert(traversed.end(), rightTraversed.begin(),
                   rightTraversed.end());

  return traversed;
}

vector<int> traverseBTInOrder(STreeNode *root) {
  //       8
  //    /     \
  //   5        3
  //  /   \    /
  // 2    9   1
  // In-order traversal : left, root, right:  {2, 5, 9, 8, 1, 3}
  //   f(x) = f(x->left) +  {root} + f(x->right)
  vector<int> traversed;
  // exception
  if (root == nullptr)
    return traversed;

  // general
  vector<int> leftTraversed = traverseBTInOrder(root->left);
  // traversed + leftTraversed
  traversed.insert(traversed.end(), leftTraversed.begin(), leftTraversed.end());

  traversed.push_back(root->val);

  vector<int> rightTraversed = traverseBTInOrder(root->right);
  //+ rightTraversed
  traversed.insert(traversed.end(), rightTraversed.begin(),
                   rightTraversed.end());

  return traversed;
}

vector<int> traverseBTPostOrder(STreeNode *root) {
  //       8
  //    /     \
  //   5        3
  //  /   \    /
  // 2    9   1
  // traversal : left, right, root:  {5, 2, 9, 3, 1, 8}
  //   f(x) = f(x->left) +  f(x->right)+ {root}
  vector<int> traversed;
  // exception
  if (root == nullptr)
    return traversed;

  // general
  vector<int> leftTraversed = traverseBTPostOrder(root->left);
  // traversed + leftTraversed
  traversed.insert(traversed.end(), leftTraversed.begin(), leftTraversed.end());

  vector<int> rightTraversed = traverseBTPostOrder(root->right);
  //+ rightTraversed
  traversed.insert(traversed.end(), rightTraversed.begin(),
                   rightTraversed.end());

  traversed.push_back(root->val);

  return traversed;
}

void basic_binaryTree_traversal() {
  vector<int> vals({8, 5, 3, 2, 9, 1});

  STreeNode *root = nullptr;
  vector<STreeNode> nodes;
  for (auto &ir : vals) {
    nodes.push_back(STreeNode(ir));
  }

  root = createBFTree(nodes);
  printNodes(nodes);
  //       8
  //    /     \
  //   5        3
  //  /   \    /
  // 2    9   1

  // Pre-order traversal : root, left, right:  {8, 5, 2, 9, 3, 1}
  // In-order traversal : left, root, right:   {2, 5, 9, 8, 1, 3}
  // Post-order traversal : left, right, root: {2, 9, 5, 1, 3, 8}
  //

  vector<int> traversed;

  printf("== Pre-order traversal === \n");
  traversed = traverseBTPreOrder(root);
  for (auto &ir : traversed)
    printf("%d ", ir);
  printf("\n");

  printf("== In-order traversal === \n");
  traversed = traverseBTInOrder(root);
  for (auto &ir : traversed)
    printf("%d ", ir);
  printf("\n");

  printf("== Post-order traversal === \n");
  traversed = traverseBTPostOrder(root);
  for (auto &ir : traversed)
    printf("%d ", ir);
  printf("\n");
}

void leetcode_balanced_tree() {
  vector<STreeNode> nodeData(6);
  nodeData[0].val = 7;
  nodeData[0].left = &(nodeData[1]);
  nodeData[0].right = &(nodeData[2]);
  nodeData[1].val = 9;
  nodeData[1].left = &(nodeData[3]);
  nodeData[1].right = &(nodeData[4]);
  nodeData[2].val = 1;

  nodeData[3].val = 5;
  nodeData[4].val = 4;
  nodeData[4].left = &(nodeData[5]);
  nodeData[5].val = 6;

  //             7
  //            / \
  //           9   1
  //          / \
  //         5   4
  //             /
  //            6
  STreeNode *root = &(nodeData[0]);
  printf("root value is %d\n", root->val);
  printNodes(nodeData);
  //---------------//
  // Q:  Given an unbalanced binary tree, make it in-order balanced tree.

  //      6
  //     /  \
  //   5     1
  //  / \   / \
  // 9   4 7   NULL

  // HW0906
  vector<int> traversed;
  traversed = traverseBTInOrder(root);
  // traversed = traverseBTPreOrder(root);
  // traversed = traverseBTPostOrder(root);
  for (auto &ir : traversed)
    printf("%d ", ir);
  printf("\n");

  vector<STreeNode> nodes;
  for (auto &ir : traversed) {
    nodes.push_back(STreeNode(ir));
  }
  int startIdx = 0;
  int endIdx = traversed.size() - 1;
  root = createDFInOrderRec(nodes, startIdx, endIdx);
  // root = createDFPreOrderRec(nodes, startIdx, endIdx);
  // root = createDFPostOrderRec(nodes, startIdx, endIdx);
  printf("root value is %d\n", root->val);
  printNodes(nodes);
}

class CRecurLeafBase {
public:
  virtual vector<vector<int>> getLayeredLeaveValues(STreeNode *tree) {
    printf("No implementation\n");
    return vector<vector<int>>(0);
  }
};

class CRecurLeftVK : public CRecurLeafBase {
public:
  vector<vector<int>> getLayeredLeaveValues(STreeNode *tree) {
    //             7
    //            / \
    //           9   1
    //          / \    \
    //         5   4   2
    //             /
    //            6
    //
    // time complexity : O(N logN )

    vector<vector<int>> layers;
    bool isLastNode = false;
    while (!isLastNode) // logN
    {
      // general case
      //  input/ condition :
      //  output (return, reference) : return
      //  variable among recursion: tree
      vector<int> oneLayer = getOneLayerNodes(tree, isLastNode); // N
      layers.push_back(oneLayer);

      // ending contion (TBD)
      // if(isLastNode) break;
    }

    return layers;
  }

private:
  vector<int> getOneLayerNodes(STreeNode *root, bool &setNullPtrLater) {
    vector<int> leafs;

    // exception
    if (root == nullptr)
      return leafs;

    if (root->left == nullptr && root->right == nullptr) {
      leafs.push_back(root->val);
      setNullPtrLater = true;
      return leafs;
    }

    // general  - backtracking + get the feedback signal
    bool setNullPtrNow = false;
    vector<int> leftLeafs = getOneLayerNodes(root->left, setNullPtrNow);
    if (setNullPtrNow)
      root->left = nullptr;
    leafs.insert(leafs.end(), leftLeafs.begin(), leftLeafs.end());

    setNullPtrNow = false;
    vector<int> rightLeafs = getOneLayerNodes(root->right, setNullPtrNow);
    if (setNullPtrNow)
      root->right = nullptr;
    leafs.insert(leafs.end(), rightLeafs.begin(), rightLeafs.end());

    return leafs;
  }
};

class CRecurLeaf : public CRecurLeafBase {
public:
  vector<vector<int>> getLayeredLeaveValues(STreeNode *tree) {
    //             7
    //            / \
    //           9   1
    //          / \    \
    //         5   4   2
    //             /
    //            6
    //

    //     4
    //    /
    //   6
    // left {{6}}, right {}
    // res = left, shortest_side = right
    // res[0] = {{6}, {}}
    // {
    //  {6, },
    //  {4}
    // }
    //
    // HW0913:
    //  post-order traversol: f(x) = f(x->left) + f(x->right) + f(root)
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    // STEP1:
    // root = 1, recursive to left node 2 and right node 3
    // STEP2:
    // root = 2, left = [[4]], right = [[5]], res = [[4]], shortest_side =
    // [[5]], push_back(2) res [[4, 5], [2]] STEP3: return to root = 1 left =
    // [[4, 5], [2]], right = [[3]] res = [[4, 5], [2]], shortest_side = [[3]],
    // push_back(1) res = [[4, 5, 3], [2], [1]]

    // Pre-order : root, left, right  => f(x) = {root} + f(x->left) +
    // f(x->right)
    //
    // HW0913 : derive the recursive functions in polynomial expression: why
    // this method is backtracing? Further improved?
    //
    // time complexity : O(NlogN)
    //
    if (!tree) {
      return {};
    }
    vector<vector<int>> left = getLayeredLeaveValues(tree->left);
    vector<vector<int>> right = getLayeredLeaveValues(tree->right);
    vector<vector<int>> res = (left.size() >= right.size()) ? left : right;
    vector<vector<int>> shortest_side =
        (left.size() >= right.size()) ? right : left;
    for (int i = 0; i < shortest_side.size(); i++) {
      res[i].insert(res[i].begin(), shortest_side[i].begin(),
                    shortest_side[i].end());
    }
    res.push_back({tree->val});
    return res;
    // return vector<vector<int>>(0);
  }
};

void leetcode_recursive_leafs() {

  //             7
  //            / \
  //           9   1
  //          /     \
  //         5       2
  //     {5, 2}, {9, 1}, {7}

  //             7
  //            / \
  //           9   1
  //          /
  //         5
  //     {5, 1}, {9}, {7}

  vector<STreeNode> nodeData(7);
  nodeData[0].val = 7;
  nodeData[0].left = &(nodeData[1]);
  nodeData[0].right = &(nodeData[2]);
  nodeData[1].val = 9;
  nodeData[1].left = &(nodeData[3]);
  nodeData[1].right = &(nodeData[4]);
  nodeData[2].val = 1;
  nodeData[2].right = &(nodeData[6]);
  nodeData[3].val = 5;
  nodeData[4].val = 4;
  nodeData[4].left = &(nodeData[5]);
  nodeData[5].val = 6;
  nodeData[6].val = 2;
  //             7
  //            / \
  //           9   1
  //          / \    \
  //         5   4   2
  //             /
  //            6
  //
  printNodes(nodeData);

  //---------------//
  STreeNode *tree = &(nodeData[0]);

  // Q:  Given binary tree, print out the leaf values at different layers
  //   Examples: {5, 6, 2} {4, 1} {9}, {7}
  CRecurLeaf solDerived;
  CRecurLeafBase *sol = &solDerived;

  vector<vector<int>> vecOut;
  vecOut = sol->getLayeredLeaveValues(tree);
  for (auto ir : vecOut) {
    for (auto ir_t : ir) {
      printf("%d ", ir_t);
    }
    printf("\n");
  }
}
class CSolDistanceKInBTBase {
public:
  virtual vector<int> distanceK(STreeNode *root, STreeNode *target, int k) {
    return vector<int>();
  }
};
//
// Dynamic Programming : Top-down thinking => backtracking
//
// f(x) = {root} + f(x->left) + f(x->right) : decision tree (X)
// f(x) = f(x-1) + f(x-2) : numerical operation => backtracking O(2^N) =>
// memoization => O(N)
//
class CSolDistanceKInBT : public CSolDistanceKInBTBase {
public:
  vector<int> distanceK(STreeNode *root, STreeNode *target, int k) {
    // time complexity : O(logN K) (?)  To be discused.
    // HW0913 : to be discussed (no action item)
    // target = 3, k = 2
    // ans = [2, 7, 8]
    //             1
    //            / \
    //           2   3  <- target
    //          / \    \
    //         4   5    6
    //                 / \
    //                7   8
    //
    // dfs(1)
    // left = -1 -> dfs(2) -> left = dfs(4) return -1
    //                -> right = dfs(5) return -1
    // right = 1 -> dfs(3) return 1
    // looking for left sub-tree of node 1 is distance one from node 3
    // find all nodes that are distance one from node 1
    // HW0906
    vector<int> nodesDistanceK;
    find_distance_from_node_to_target(root, target->val, k, nodesDistanceK);
    // return vector<int>();
    return nodesDistanceK;
  }
  int find_distance_from_node_to_target(STreeNode *node, int target, int k,
                                        vector<int> &nodesDistanceK) {
    // exception / base
    if (node == nullptr) {
      return -1;
    }
    if (node->val == target) {
      add_subtree_node_at_distance_k(node, 0, k, nodesDistanceK);
      return 1;
    }

    // general
    int leftDistance = find_distance_from_node_to_target(node->left, target, k,
                                                         nodesDistanceK);
    int rightDistance = find_distance_from_node_to_target(node->right, target,
                                                          k, nodesDistanceK);

    if (leftDistance == k || rightDistance == k) {
      nodesDistanceK.push_back(node->val);
    }
    if (leftDistance != -1) {
      add_subtree_node_at_distance_k(node->right, leftDistance + 1, k,
                                     nodesDistanceK);
      return leftDistance + 1;
    }
    if (rightDistance != -1) {
      add_subtree_node_at_distance_k(node->left, rightDistance + 1, k,
                                     nodesDistanceK);
      return rightDistance + 1;
    }

    return -1;
  }
  void add_subtree_node_at_distance_k(STreeNode *node, int distance, int k,
                                      vector<int> &nodesDistanceK) {
    if (node == nullptr) {
      return;
    }
    if (distance == k) {
      nodesDistanceK.push_back(node->val);
    } else {
      add_subtree_node_at_distance_k(node->left, distance + 1, k,
                                     nodesDistanceK);
      add_subtree_node_at_distance_k(node->right, distance + 1, k,
                                     nodesDistanceK);
    }
  }
};

class CSolDistanceKVK : public CSolDistanceKInBTBase {
public:
  vector<int> distanceK(STreeNode *root, STreeNode *target, int k) {
    vector<int> kVals;

    // traverse to target and backtracking all parent nodes
    //  O(logN)
    int distance = 0;
    vector<STreeNode *> nodeList = traverseToTarget(root, target, distance);

    // traverse from target and all rotts
    int numRoots = (k + 1 < nodeList.size()) ? (k + 1) : nodeList.size();
    // O(logN * k)
    for (int i = 0; i < numRoots; i++, k--) {
      STreeNode *excludeNode = (i == 0) ? nullptr : nodeList[i - 1];
      vector<int> vals = traverseChildsWithK(nodeList[i], excludeNode, k);
      kVals.insert(kVals.end(), vals.begin(), vals.end());
    }

    return kVals;
  }

private:
  vector<int> traverseChildsWithK(STreeNode *root, STreeNode *excludeNode,
                                  int distance) {
    vector<int> traversed;
    // exception
    if (root == nullptr || root == excludeNode) {
      return traversed;
    }

    if (distance == 0) {
      traversed.push_back(root->val);
      return traversed;
    }

    // general
    vector<int> leftList =
        traverseChildsWithK(root->left, excludeNode, distance - 1);
    traversed.insert(traversed.end(), leftList.begin(), leftList.end());

    vector<int> rightList =
        traverseChildsWithK(root->right, excludeNode, distance - 1);
    traversed.insert(traversed.end(), rightList.begin(), rightList.end());

    return traversed;
  }

  vector<STreeNode *> traverseToTarget(STreeNode *root, STreeNode *target,
                                       int &distance) {
    vector<STreeNode *> traversed;
    // exception case
    if (root == nullptr) {
      return traversed;
    }

    if (root == target) {
      traversed.push_back(root);
      distance++;
      return traversed;
    }

    // general case
    traversed = traverseToTarget(root->left, target, distance);
    if (distance > 0) {
      traversed.push_back(root);
      distance++;
      return traversed;
    }

    traversed = traverseToTarget(root->right, target, distance);
    if (distance > 0) {
      traversed.push_back(root);
      distance++;
      return traversed;
    }

    return traversed;
  }
};

void leetcode_bt_distanceK() {

  CSolDistanceKInBT objDerived;
  CSolDistanceKInBTBase *obj;
  obj = &objDerived;

  int k;
  vector<int> kVals;

  STreeNode *root = nullptr;
  STreeNode *target = nullptr;
  vector<STreeNode> nodeData;
  printf("-- case 0 --\n");
  nodeData.clear();
  nodeData.resize(4);
  nodeData[0].val = 0;
  nodeData[1].val = 1;
  nodeData[2].val = 3;
  nodeData[3].val = 2;
  nodeData[0].left = &(nodeData[1]);
  nodeData[1].left = &(nodeData[2]);
  nodeData[1].right = &(nodeData[3]);

  root = &(nodeData[0]);
  target = &(nodeData[3]);
  k = 1;

  kVals = obj->distanceK(root, target, k);

  printf("[");
  for (auto ir : kVals) {
    printf("%d ", ir);
  }
  printf("] => ans: [1]\n");

  printf("-- case 1 --\n");
  nodeData.clear();
  nodeData.resize(7);
  nodeData[0].val = 7;
  nodeData[0].left = &(nodeData[1]);
  nodeData[0].right = &(nodeData[2]);
  nodeData[1].val = 9;
  nodeData[1].left = &(nodeData[3]);
  nodeData[1].right = &(nodeData[4]);
  nodeData[2].val = 1;
  nodeData[2].right = &(nodeData[6]);
  nodeData[3].val = 5;
  nodeData[4].val = 4;
  nodeData[4].left = &(nodeData[5]);
  nodeData[5].val = 6;
  nodeData[6].val = 2;
  //              7 (0)
  //            /      \
  //           9 (1)    1 (2)
  //          / \         /  \
  //       5(3)  4 (4)  null   2(6)
  //             /
  //            6 (5)

  printNodes(nodeData);

  root = &(nodeData[0]);
  target = &(nodeData[4]);
  k = 2;

  kVals = obj->distanceK(root, target, k);

  printf("[");
  for (auto ir : kVals) {
    printf("%d ", ir);
  }
  printf("] => ans: [5 7]\n");

  printf("-- case 2 --\n");
  nodeData.clear();
  nodeData.resize(9);

  nodeData[0].val = 3;
  nodeData[0].left = &(nodeData[1]);
  nodeData[0].right = &(nodeData[2]);

  nodeData[1].val = 5;
  nodeData[1].left = &(nodeData[3]);
  nodeData[1].right = &(nodeData[4]);

  nodeData[3].val = 6;

  nodeData[4].val = 2;
  nodeData[4].left = &(nodeData[7]);
  nodeData[4].right = &(nodeData[8]);
  nodeData[7].val = 7;
  nodeData[8].val = 4;

  nodeData[2].val = 1;
  nodeData[2].left = &(nodeData[5]);
  nodeData[2].right = &(nodeData[6]);
  nodeData[5].val = 0;
  nodeData[6].val = 8;
  //              3 (0)
  //            /      \
  //           5 (1)    1 (2)
  //          / \         /  \
  //       6(3)  2 (4)  null   2(6)
  //            /   \
  //           7 (5) 4 (8)
  printNodes(nodeData);

  root = &(nodeData[0]);
  target = &(nodeData[1]);
  k = 2;

  kVals = obj->distanceK(root, target, k);

  printf("[");
  for (auto ir : kVals) {
    printf("%d ", ir);
  }
  printf("] => ans: [7 4 1]\n");
}

int fibSeqHelper(int k, unordered_map<int, int> &memorize) {
  if (memorize.find(k) != memorize.end()) {
    return memorize[k];
  } else {
    memorize[k] = fibSeqHelper(k - 1, memorize) + fibSeqHelper(k - 2, memorize);
    return memorize[k];
  }
#if 0
  //exception | base
  if(k== 0) return 0;
  if(k== 1) return 1;

  //general: X(n) = X(n-1) + X(n-2)
  // without memo : O(2^N)
  // w/ memo : O(N)
  //
  if (memorize.find(k) != memorize.end()){
    return memorize[k];
  }
  return memorize[k] = fibSeqHelper(k - 1, memorize) + fibSeqHelper(k - 2, memorize);
#endif
}
int getFibSeq(int k) {
  // HW0913 : backtracking + memoization
  unordered_map<int, int> memorize{{1, 0}, {2, 1}};
  return fibSeqHelper(k, memorize); // please modify it.
}
void leetcode_fibonacci_seq() {

  // Fibonacci (費氏函數)
  // Formula : X(n) = X(n-1) + X(n-2)
  //           X(0) = 0, X(1) = 1
  //  {0,   1,   1,    2, 3, 5, 8....}
  //  X(0) X(1) X(2)  X(3) ........ X(N-1)
  //
  //
  //  Q: Given k, derive X(k)
  //.    For example : X(0) = 0, when k=0
  //.                  X(2) = 1, when k=2
  //                   X(4) = 3, when k=4
  // NOTE: time complexity must be O(N)

  int k = 10;
  int Xk = getFibSeq(k);

  printf("X%d= %d\n", k, Xk);
}

class CFuncParsingBase {
public:
  virtual int solveFunctions(string paramStr) { return -1; }
};

class CFuncBase {
public:
  virtual int getNum() { return -1; }
  virtual int getRes(vector<int> in) { return -1; }
};

class CFuncF : public CFuncBase {
  int getNum() { return 1; }
  int getRes(vector<int> in) { return (2 * in[0] - 3); }
};

// 𝑔(𝑥, 𝑦) = 2𝑥 + 𝑦 – 7
class CFuncG : public CFuncBase {
  int getNum() { return 2; }
  int getRes(vector<int> in) { return (2 * in[0] + in[1] - 7); }
};

// ℎ(𝑥, 𝑦, 𝑧) = 3𝑥 – 2𝑦 + 𝑧
class CFuncH : public CFuncBase {
  int getNum() { return 3; }
  int getRes(vector<int> in) { return (3 * in[0] - 2 * in[1] + in[2]); }
};

class CFuncParsingVK : CFuncParsingBase {
public:
  int solveFunctions(string paramStr) {
    // input string -> vector of parameters
    vector<string> paramList;
    string oneStr;
    for (auto &ir : paramStr) {
      if (ir == ' ') {
        paramList.push_back(oneStr);
        oneStr.clear();
      } else {
        oneStr.push_back(ir);
      }
    }
    paramList.push_back(oneStr);
    return recSolveFunc(paramList);
  }

private:
  int recSolveFunc(vector<string> &paramList) {
    // int res = -1;
    // exception
    if (isdigit(paramList.front().back())) {
      int oneParam = stoi(paramList.front());
      paramList.erase(paramList.begin());
      return oneParam;
    }

    // general
    char funcChar = paramList.front().front();
    CFuncBase *func = nullptr;

    switch (funcChar) {
    case 'f':
      func = &funcF;
      break;
    case 'g':
      func = &funcG;
      break;
    case 'h':
      func = &funcH;
      break;
    default:
      printf("not a defined implementation: %d\n", (int)funcChar);
      exit(-1);
    }
    paramList.erase(paramList.begin());
    vector<int> funcParams;
    for (int i = 0; i < func->getNum(); i++)
      funcParams.push_back(recSolveFunc(paramList));

    return func->getRes(funcParams);
  }

private:
  CFuncF funcF;
  CFuncG funcG;
  CFuncH funcH;
};

class CFuncParsingDerive : public CFuncParsingBase {
public:
  int solveFunctions(string paramStr) {
    // H@0913
    vector<string> tokens = tokenize(paramStr);
    int idx = 0;
    return evaluate(tokens, idx);
  }

private:
  int f(int x) { return 2 * x - 3; }

  int g(int x, int y) { return 2 * x + y - 7; }

  int h(int x, int y, int z) { return 3 * x - 2 * y + z; }

  vector<string> tokenize(const string &str) {
    vector<string> tokens;
    istringstream iss(str);
    string token;
    while (iss >> token) {
      tokens.push_back(token);
    }
    return tokens;
  }

  int evaluate(const vector<string> &tokens, int &idx) {
    string token = tokens[idx];
    idx++;
    if (token == "f") {
      int x = evaluate(tokens, idx);
      return f(x);
    } else if (token == "g") {
      int x = evaluate(tokens, idx);
      int y = evaluate(tokens, idx);
      return g(x, y);
    } else if (token == "h") {
      int x = evaluate(tokens, idx);
      int y = evaluate(tokens, idx);
      int z = evaluate(tokens, idx);
      return h(x, y, z);
    } else {
      return stoi(token);
    }
  }
};

void leetcode_functionParsing() {
  // 𝑓(𝑥) = 2𝑥 – 3
  // 𝑔(𝑥, 𝑦) = 2𝑥 + 𝑦 – 7
  // ℎ(𝑥, 𝑦, 𝑧) = 3𝑥 – 2𝑦 + 𝑧

  //
  //
  // input string = {h f 5 g 3 4 3}, "space" is inserted between two consecutive
  // parameters, ℎ(𝑓(5), 𝑔(3, 4), 3) = ℎ(7, 3, 3) = 18
  // y(x) = y( h, f, g) <== backtracking
  //

  CFuncParsingBase *sol = nullptr;
  CFuncParsingDerive solDerived;

  sol = &solDerived;
  string inStr = "h f 5 g 3 4 3";
  int res = sol->solveFunctions(inStr);
  printf("%d (ans = 18)\n", res);
}

int funcFindKthMinFromArray(vector<int> vecData, int k) { return -1; }
void leetcode_bt_findKthMin() {
  // Given any array/vector, find the K-min number.
  // Example: array = {5, 4, 1, 9, 2, 3}, if K=3, the 3rd min number is 3.
  vector<int> vecData({5, 4, 1, 9, 2, 3});
  printf("input= { ");
  for (auto &ir : vecData) {
    printf("%d ", ir);
  }
  printf("}\n");

  int k = 3;
  int kthMin = funcFindKthMinFromArray(vecData, k);
  printf("%d-min is %d\n\n", k, kthMin);
}

void pivotPartition(vector<int> &inVec) {}

void basic_pivot_partitioning() {
  // {smaller than pivot} {pivot} {greater than pivot}

  vector<int> vecData({5, 2, 6, 1, 8, 3, 6, 9, 4});

  printf("before : ");
  for (auto &ir : vecData) {
    printf("%d ", ir);
  }
  printf("\n");

  // function
  pivotPartition(vecData);

  printf("after : ");
  for (auto &ir : vecData) {
    printf("%d ", ir);
  }
  printf("\n");
}

vector<int> mergeTwoSortedLists(vector<int> a, vector<int> b) {
  return vector<int>(0);
}

void leetcode_merge_sorted_lists() {
  vector<int> a({2, 10, 20, 40}); // sorted
  vector<int> b({1, 25, 30});     // sorted

  vector<int> c = mergeTwoSortedLists(a, b);

  for (auto &ir : c)
    printf("%d ", ir);
  printf("\n");
}

void basic_mergeSort() {}
int revertInteger(int num) { return -1; }
void leetcode_revert_integer() {
  int num = 420;
  num = revertInteger(num);
  printf("reverted number = %d (ans : 54321)\n", num);
}

int funcEvenOddDiff(int num) { return -1; }
void leetcode_even_odd_diff() {
  int X = 263541;
  int diff = funcEvenOddDiff(X);
  printf("diff =%d (ans : 3)\n", diff);

  X = 131;
  diff = funcEvenOddDiff(X);
  printf("diff =%d (ans : 1)\n", diff);
}

void leetcode_bits_resersal() {}

void leetcode_print_decimal_in_binary() {}

void basic_quickSort() {}