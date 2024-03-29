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
void iterativePostorder(TreeNode root) {
  /* Using two stack
    * stack one to keep track of node
    * stack two to store visited noded,
    the second stack when printed at last
    while poppoing prints the postorder,
  */
  if (!root)
    return;
  Stack *s = createStack();
  Stack *postorderReverse = createStack();
  push(s, root);
  while (!isStackEmpty(s)) {
    TreeNode temp = pop(s);
    if (temp->left)
      push(s, temp->left);
    if (temp->right)
      push(s, temp->right);
    push(postorderReverse, temp);
  }

  while (!isStackEmpty(postorderReverse)) {
    TreeNode temp = pop(postorderReverse);
    printf("%d", temp->data);
  }
}

void zigzagTraversal(TreeNode root) {
  if (!root)
    return;
  Stack *s = createStack();
  Queue q = createQueue();
  bool rev = false;
  push(s, root);
  while (!(isStackEmpty(s) && isEmpty(q))) {
    while (!isEmpty(q)) {
      TreeNode currNode = dequeue(q);
      printf("%d", currNode->data);
      if (rev) {
        push(s, currNode->right);
        push(s, currNode->left);
      } else {
        push(s, currNode->left);
        push(s, currNode->right);
      }
    }
    while (!isStackEmpty(s)) {
      TreeNode temp = pop(s);
      enqueue(q, temp);
    }
    rev = !rev;
  }
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
  printf("\nIterative Postorder : ");
  iterativePostorder(root);

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

  printf("\nZigzag Levelorder : ");
  zigzagTraversal(root);
  printf("\n");
  return 1;
}