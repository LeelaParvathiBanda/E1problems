#include <stdio.h>
#include <stdlib.h>

// Define a structure for the nodes of the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert data into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        // If the tree is empty, create a new node as the root
        return createNode(data);
    }
    // Compare data with root's data
    if (data < root->data) {
        // If data is less than root's data, insert in left subtree
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        // If data is greater than root's data, insert in right subtree
        root->right = insert(root->right, data);
    }
    // Return the unchanged root pointer
    return root;
}

// Function to traverse the BST recursively in postorder
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        // Traverse left subtree
        postorderTraversal(root->left);
        // Traverse right subtree
        postorderTraversal(root->right);
        // Visit root node
        printf("%d ", root->data);
    }
}

int main() {
    // Create an empty BST
    struct Node* root = NULL;
    
    // Insert data into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    // Perform postorder traversal of the BST
    printf("Postorder traversal of BST: ");
    postorderTraversal(root);
    printf("\n");
    return 0;
}
