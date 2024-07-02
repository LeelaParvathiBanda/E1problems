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
    return root;
}

// Function to find the minimum value node in a subtree
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete an element from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        // Element not found, nothing to delete
        return NULL;
    }
    
    // Find the node to be deleted
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node to be deleted found
        if (root->left == NULL && root->right == NULL) {
            // Node has no children (no left and no right child)
            free(root);
            return NULL; // Return NULL indicating the node is deleted
        } else if (root->left == NULL) {
            // Node has no left child, replace it with right child
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // Node has no right child, replace it with left child
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            // Node has two children, find the in-order successor
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    
    return root;
}


// Non-recursive in-order traversal using a stack
void nonRecursiveInOrderTraversal(struct Node* root) {
    struct Node* current = root;
    struct Node* stack[100];  // Stack to hold nodes
    int top = -1;  // Initialize stack pointer
    
    while (current != NULL || top != -1) {
        // Traverse to the leftmost node
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        // Pop the top node from the stack and visit it
        current = stack[top--];
        printf("%d ", current->data);
        // Move to the right subtree
        current = current->right;
    }
}

int main() {
    // Create an empty BST
    struct Node* root = NULL;
    
    // Insert data into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    // Perform non-recursive in-order traversal
    printf("Non-recursive in-order traversal of BST: ");
    nonRecursiveInOrderTraversal(root);
    printf("\n");
    
    // Delete an element from the BST
    root = deleteNode(root, 70);
    
    
    // Perform non-recursive in-order traversal after deletion
    printf("Non-recursive in-order traversal after deleting 70: ");
    nonRecursiveInOrderTraversal(root);
    printf("\n");
    
    return 0;
}
