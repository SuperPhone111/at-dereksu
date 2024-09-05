#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
// Google : cplusplus, stackoverflow, geeksforgeeks

#include "includes.h"

using namespace std;

int main(int argc, char **argv) {
  int testID = 2;

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
  case 2: // binary tree- DF creation
    basic_binaryTree_creation_depthFirst();
    break;
  case 3: // binary tree- DF traversal
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
  default:
    printf("not a supported testID %d\n", testID);
    exit(-1);
  }

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

STreeNode *createDFTree_PreOrder(vector<STreeNode> &nodes) {
  STreeNode *root = nullptr;
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

STreeNode *createDFTree_InOrder(vector<STreeNode> &nodes) {
  STreeNode *root = nullptr;
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

STreeNode *createDFTree_PostOrder(vector<STreeNode> &nodes) {
  STreeNode *root = nullptr;
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
  return vector<int>(0);
}

vector<int> traverseBTInOrder(STreeNode *root) {
  //       8
  //    /     \
  //   5        3
  //  /   \    /
  // 2    9   1
  // In-order traversal : left, root, right:  {2, 5, 9, 8, 1, 3}
  return vector<int>(0);
}

vector<int> traverseBTPostOrder(STreeNode *root) {
  //       8
  //    /     \
  //   5        3
  //  /   \    /
  // 2    9   1
  // traversal : left, right, root:  {5, 2, 9, 3, 1, 8}
  return vector<int>(0);
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
  printNodes(nodeData);
  //---------------//
  STreeNode *root = &(nodeData[0]);
  printf("root value is %d\n", root->val);
  // Q:  Given an unbalanced binary tree, make it in-order balanced tree.

  //      6
  //     /  \
  //   5     1
  //  / \   / \
  // 9   4 7   NULL

  // TBD
}

class CRecurLeafBase {
public:
  virtual vector<vector<int>> getLayeredLeaveValues(STreeNode *tree) {
    printf("No implementation\n");
    return vector<vector<int>>(0);
  }
};

class CRecurLeaf : public CRecurLeafBase {
public:
  vector<vector<int>> getLayeredLeaveValues(STreeNode *tree) {
    // TBD
    return vector<vector<int>>(0);
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

  // Q:  Given binary tree, print out the leave values at different layers
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

class CSolDistanceKInBT : public CSolDistanceKInBTBase {
public:
  virtual vector<int> distanceK(STreeNode *root, STreeNode *target, int k) {
    // TBD
    return vector<int>();
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

int getFibSeq(int k) {

  return -1; // please modify it.
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
  //                   X(4) = 3, when k=3

  int k = 10;
  int Xk = getFibSeq(k);

  printf("X%d= %d\n", k, Xk);
}