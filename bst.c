#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform level-wise display (non-recursive)
void levelwiseDisplay(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* queue[100];  // Assuming a maximum of 100 nodes
    int front = 0, rear = -1;

    queue[++rear] = root;

    while (front <= rear) {
        struct TreeNode* node = queue[front++];

        printf("%d ", node->data);

        if (node->left) queue[++rear] = node->left;
        if (node->right) queue[++rear] = node->right;
    }
}

// Function to perform mirror image transformation (non-recursive)
void mirrorImage(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top >= 0) {
        struct TreeNode* node = stack[top--];

        // Swap left and right children
        struct TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;

        if (node->left) stack[++top] = node->left;
        if (node->right) stack[++top] = node->right;
    }
}

// Function to count the total number of nodes in the tree
int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;

    struct TreeNode* stack[100];
    int top = -1;
    int count = 0;

    stack[++top] = root;

    while (top >= 0) {
        struct TreeNode* node = stack[top--];
        count++;

        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }

    return count;
}

// Function to calculate the height of the tree
int height(struct TreeNode* root) {
    if (root == NULL) return 0;

    struct TreeNode* queue[100];
    int front = 0, rear = -1;
    int levelSize, treeHeight = 0;

    queue[++rear] = root;

    while (front <= rear) {
        levelSize = rear - front + 1;

        while (levelSize > 0) {
            struct TreeNode* node = queue[front++];

            if (node->left) queue[++rear] = node->left;
            if (node->right) queue[++rear] = node->right;

            levelSize--;
        }

        treeHeight++;
    }

    return treeHeight;
}

// Function to count the total number of leaf nodes in the tree
int countLeafNodes(struct TreeNode* root) {
    if (root == NULL) return 0;

    struct TreeNode* stack[100];
    int top = -1;
    int count = 0;

    stack[++top] = root;

    while (top >= 0) {
        struct TreeNode* node = stack[top--];

        if (node->left == NULL && node->right == NULL) {
            count++;
        } else {
            if (node->right) stack[++top] = node->right;
            if (node->left) stack[++top] = node->left;
        }
    }

    return count;
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int choice;
    do {
        printf("\n\nMenu:\n");
        printf("1. Level-wise Display\n");
        printf("2. Mirror Image\n");
        printf("3. Count Total Nodes\n");
        printf("4. Display Height\n");
        printf("5. Count Leaf Nodes\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Level-wise Display: ");
                levelwiseDisplay(root);
                break;

            case 2:
                printf("Mirror Image: ");
                mirrorImage(root);
                levelwiseDisplay(root);
                break;

            case 3:
                printf("Total Number of Nodes: %d", countNodes(root));
                break;

            case 4:
                printf("Height of the Tree: %d", height(root));
                break;

            case 5:
                printf("Total Number of Leaf Nodes: %d", countLeafNodes(root));
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.");
        }
    } while (choice != 6);

    return 0;
}
