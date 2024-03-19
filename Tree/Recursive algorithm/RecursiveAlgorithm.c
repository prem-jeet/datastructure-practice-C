/*
gcc RecursiveAlgorithm.c ../TreeHelper.c ../../GlobalLibrary/GenericQueue.c
../../GlobalLibrary/GenericStack.c
../../Linked\ list/Doubly\ Circular\ Linked\ List/DoublycircularLinkedList.c
*/
#include "../../GlobalLibrary/GenericQueue.h"
#include "../../GlobalLibrary/GenericStack.h"
#include "../TreeHelper.h"

int countLeafsRecursive(TreeNode);

/* Tree structure
    1
 /    \
2      3
 \    / \
  4  5   6
      \
       7
*/
int main() {
  int tree[] = {1, 2, 3, 0, 4, 5, 6, 0, 0, 0, 0, 0, 7, 0, 0};
  TreeNode root = createTree(tree, 15);
  printf("Number of leaf nodes : %d", countLeafsRecursive(root));
  return 1;
}

int countLeafsRecursive(TreeNode root) {
  if (!root)
    return 0;
  if (!root->left && !root->right)
    return 1;
  return countLeafsRecursive(root->left) + countLeafsRecursive(root->right);
}