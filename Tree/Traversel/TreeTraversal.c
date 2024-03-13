/*
gcc TreeTraversal.c ../TreeHelper.c ../../GlobalLibrary/GenericQueue.c
../../GlobalLibrary/GenericStack.c
../../Linked\ list/Doubly\ Circular\ Linked\ List/DoublycircularLinkedList.c
*/
#include "../../GlobalLibrary/GenericQueue.h"
#include "../../GlobalLibrary/GenericStack.h"
#include "../TreeHelper.h"
#include <stdio.h>

void printPreorder(TreeNode node) {
  if (node) {
    printf("%d", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
  }
}
void printPostorder(TreeNode node) {
  if (node) {
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d", node->data);
  }
}
void printInorder(TreeNode node) {
  if (node) {
    printInorder(node->left);
    printf("%d", node->data);
    printInorder(node->right);
  }
}
void printConversePreorder(TreeNode node) {
  if (node) {
    printf("%d", node->data);
    printConversePreorder(node->right);
    printConversePreorder(node->left);
  }
}
void printConversePostorder(TreeNode node) {
  if (node) {
    printConversePostorder(node->right);
    printConversePostorder(node->left);
    printf("%d", node->data);
  }
}
void printConverseInorder(TreeNode node) {
  if (node) {
    printConverseInorder(node->right);
    printf("%d", node->data);
    printConverseInorder(node->left);
  }
}
void printLevelorder(TreeNode root) {
  Queue q = createQueue();
  enqueue(q, root);
  while (!isEmpty(q)) {
    TreeNode t = dequeue(q);
    printf("%d", t->data);
    if (t->left)
      enqueue(q, t->left);
    if (t->right)
      enqueue(q, t->right);
  }
}

void iterativePreorder(TreeNode root) {
  /*
  LOOP start
    -LOOP till left subtree
      --print current node
      --push current node in stack
      -- go left subtree
    -if stack empty
      --then stop
    else
      --pop from stack
      --to right subtree
  */
  if (!root)
    return;
  Stack *s = createStack();
  TreeNode temp = root;
  while (true) {
    while (temp) {
      printf("%d", temp->data);
      push(s, temp);
      temp = temp->left;
    }
    if (isStackEmpty(s))
      return;
    temp = pop(s);
    temp = temp->right;
  }
}
void iterativeInorder(TreeNode root) {
  /*
  Loop start
    -Loop while node
      -- push node in stack
      -- move to feft child
    - if stack is empty
      -- stop
    - else
      -- pop from stack
      -- move to right subtree
  */
  Stack *s = createStack();
  TreeNode temp = root;
  while (true) {
    while (temp) {
      push(s, temp);
      temp = temp->left;
    }
    if (isStackEmpty(s))
      return;
    temp = pop(s);
    printf("%d", temp->data);
    temp = temp->right;
  }
}
void iterativePostorder(){

}


int main() {
  /*
        1
      /  \
     4    2
      \  /
      5 3
  */
  int arr[] = {1, 4, 2, 0, 5, 3, 0};
  TreeNode root = createTree(arr, 7);
  printf("\nPreorder : ");
  printPreorder(root);
  printf("\nIterative Preorder : ");
  iterativePreorder(root);

  printf("\nPostorder : ");
  printPostorder(root);

  printf("\nInorder : ");
  printInorder(root);
  printf("\nIteravive Inorder : ");
  iterativeInorder(root);

  printf("\nConverse Preorder : ");
  printConversePreorder(root);

  printf("\nConverse Postorder : ");
  printConversePostorder(root);

  printf("\nConverse Inorder : ");
  printConverseInorder(root);

  printf("\nLevelorder : ");
  printLevelorder(root);
  printf("\n");
  return 1;
}