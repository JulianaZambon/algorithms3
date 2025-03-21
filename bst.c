// Binary Search Tree operations in C

// Based in https://www.programiz.com/dsa/binary-search-tree
// Changes by André Guedes (17/08/2023)

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int key;
  struct node *left, *right;
} node;

typedef node *tree;

// Create a node
node *newNode(int item) {
  node *temp = (node *)malloc(sizeof(node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    printf("%d -> ", root->key);

    // Traverse right
    inorder(root->right);
  }
}

// Preorder Traversal with parenthesis
void preorderp(node *root) {
  if (root != NULL) {
    // Traverse root
    printf("%d (", root->key);

    // Traverse left
    preorderp(root->left);
    printf(", ");

    // Traverse right
    preorderp(root->right);
    printf(") ");

  }
}

// Insert a node
node *insert(node *root, int key) {
  // Return a new node if the tree is empty
  if (root == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < root->key)
    root->left = insert(root->left, key);
  else
    root->right = insert(root->right, key);

  return root;
}

// Find the inorder successor
node *minValueNode(node *root) {
  node *current = root;

  // Find the leftmost leaf
  while (current && current->left)
    current = current->left;

  return current;
}

// Deleting a node
node *deleteNode(node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Driver code
int main() {
  node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  printf("Inorder traversal: ");
  inorder(root);

  printf("\nPreorder traversal: ");
  preorderp(root);

  printf("\nAfter deleting 10\n");
  root = deleteNode(root, 10);
  printf("Inorder traversal: ");
  inorder(root);

  printf("\nPreorder traversal: ");
  preorderp(root);

  printf("\nAfter deleting 3\n");
  root = deleteNode(root, 3);
  printf("Inorder traversal: ");
  inorder(root);

  printf("\nPreorder traversal: ");
  preorderp(root);

  printf("\n");
}
