

struct treenode {
  int data;
  struct treenode *left;
  struct treenode *right;
};
typedef struct treenode *TreeNode;

TreeNode createNode(int);
TreeNode createTree(int *, int);