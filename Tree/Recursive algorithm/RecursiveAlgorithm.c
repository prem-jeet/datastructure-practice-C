/*
gcc RecursiveAlgorithm.c ../TreeHelper.c ../../GlobalLibrary/GenericQueue.c
../../GlobalLibrary/GenericStack.c
../../Linked\ list/Doubly\ Circular\ Linked\ List/DoublycircularLinkedList.c
*/
#include "../../GlobalLibrary/GenericQueue.h"
#include "../../GlobalLibrary/GenericStack.h"
#include "../TreeHelper.h"

int countLeafsRecursive(TreeNode);
int countLeafsIterative(TreeNode);
int countInternalNodesRecursive(TreeNode);
int countInternalNodesIterative(TreeNode);
int countNodesRecursive(TreeNode);
int countNodesIterative(TreeNode);
int treeHeight(TreeNode);
int treeHeightIterative(TreeNode);
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
  printf("Number of leaf nodes (Recursive) : %d\n", countLeafsRecursive(root));
  printf("Number of leaf nodes (Iterative) : %d\n", countLeafsIterative(root));
  printf("Number of internal nodes (Recursive) : %d\n",
         countInternalNodesRecursive(root));
  printf("Number of internal nodes (Iterative) : %d\n",
         countInternalNodesIterative(root));
  printf("Number of nodes (Recursive) : %d\n", countNodesRecursive(root));
  printf("Number of nodes (Iterative) : %d\n", countNodesIterative(root));
  printf("Tree height : %d\n", treeHeight(root));
  printf("Tree height (Iterative) : %d\n", treeHeightIterative(root));
  return 1;
}

int countLeafsRecursive(TreeNode root) {
  if (!root)
    return 0;
  if (!root->left && !root->right)
    return 1;
  return countLeafsRecursive(root->left) + countLeafsRecursive(root->right);
}
int countLeafsIterative(TreeNode root) {
  if (!root)
    return 0;
  int count = 0;
  Queue q = createQueue();
  enqueue(q, root);
  //   BFS
  while (!isEmpty(q)) {
    TreeNode curr = dequeue(q);
    if (!(curr->left && curr->right))
      count++;
    else {
      if (curr->left)
        enqueue(q, curr->left);
      if (curr->right)
        enqueue(q, curr->right);
    }
  }
  return count;
}

int countInternalNodesRecursive(TreeNode root) {
  if (!(root && (root->left || root->right)))
    return 0;

  return countInternalNodesRecursive(root->left) +
         countInternalNodesRecursive(root->right) + 1;
}
int countInternalNodesIterative(TreeNode root) {
  if (!root)
    return 0;
  Queue q = createQueue();
  enqueue(q, root);
  int count = 0;
  while (!isEmpty(q)) {
    TreeNode temp = dequeue(q);
    if (temp->left || temp->right)
      count++;
    if (temp->left)
      enqueue(q, temp->left);
    if (temp->right)
      enqueue(q, temp->right);
  }
  return count;
}

int countNodesRecursive(TreeNode root) {
  if (!root)
    return 0;
  return countNodesRecursive(root->left) + countNodesRecursive(root->right) + 1;
}
int countNodesIterative(TreeNode root) {
  if (!root)
    return 0;
  Stack *s = createStack();
  int count = 0;
  TreeNode curr = root;
  while (true) {
    while (curr) {
      push(s, curr);
      curr = curr->left;
    }
    if (isStackEmpty(s))
      return count;
    curr = pop(s);
    count++;
    curr = curr->right;
  }
}

int treeHeight(TreeNode root) {
  if (!root || !(root->left || root->right))
    return 0;
  int leftHeight = treeHeight(root->left);
  int rightHeight = treeHeight(root->right);
  return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
int treeHeightIterative(TreeNode root) {
  if (!root)
    return 0;
  Queue q = createQueue();
  enqueue(q, root);
  int height = -1;
  while (!isEmpty(q)) {
    height++;
    int levelNodeCount = q->size;
    while (levelNodeCount--) {
      TreeNode temp = dequeue(q);
      if (temp->right)
        enqueue(q, temp->right);
      if (temp->left)
        enqueue(q, temp->left);
    }
  }
  return height;
}