#include "TreeHelper.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode createNode(int data) {
  TreeNode temp = calloc(1, sizeof(struct treenode));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

TreeNode createTree(int *arr, int size) {
  TreeNode *nodeArr = calloc(size, sizeof(TreeNode));
  for (int i = 0; i < size; i++) {
    TreeNode temp = NULL;
    if (arr[i]) {
      temp = createNode(arr[i]);
    }
    nodeArr[i] = temp;
  }
  for (int i = 0; i < size; i++) {
    if (nodeArr[i]) {
      int leftChildIndex = 2 * i + 1;
      int rightChildIndex = 2 * i + 2;
      if (leftChildIndex < size && nodeArr[leftChildIndex]) {
        nodeArr[i]->left = nodeArr[leftChildIndex];
      }
      if (rightChildIndex < size && nodeArr[rightChildIndex]) {
        nodeArr[i]->right = nodeArr[rightChildIndex];
      }
    }
  }
  return nodeArr[0];
}
