#include <stdio.h>
#include <stdlib.h>

// Define the structure for an employee record
struct Employee {
    int empId;
    char name[50];
    // Add other fields as needed
};

// Define the structure for a binary tree node
struct TreeNode {
    struct Employee data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(struct Employee emp) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = emp;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new employee record into the BST
struct TreeNode* insert(struct TreeNode* root, struct Employee emp) {
    if (root == NULL) {
        return createNode(emp);
    }

    if (emp.empId < root->data.empId) {
        root->left = insert(root->left, emp);
    } else if (emp.empId > root->data.empId) {
        root->right = insert(root->right, emp);
    }

    return root;
}

// Function to search for an employee record by empId
struct Employee* search(struct TreeNode* root, int empId) {
    while (root != NULL) {
        if (empId < root->data.empId) {
            root = root->left;
        } else if (empId > root->data.empId) {
            root = root->right;
        } else {
            return &(root->data); // Found the employee
        }
    }

    return NULL; // Employee not found
}

// Function to perform an in-order traversal and print the sorted employee records
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("EmpID: %d, Name: %s\n", root->data.empId, root->data.name);
        inOrderTraversal(root->right);
    }
}

// Main function for testing
int main() {
    struct TreeNode* root = NULL;

    // Sample employee records
    struct Employee emp1 = {101, "John Doe"};
    struct Employee emp2 = {105, "Jane Smith"};
    struct Employee emp3 = {99, "Alice Johnson"};
    struct Employee emp4 = {110, "Bob Brown"};

    // Inserting employee records into the BST
    root = insert(root, emp1);
    root = insert(root, emp2);
    root = insert(root, emp3);
    root = insert(root, emp4);

    // Searching for an employee record by empId
    int searchEmpId = 105;
    struct Employee* foundEmployee = search(root, searchEmpId);

    if (foundEmployee != NULL) {
        printf("Employee found - EmpID: %d, Name: %s\n", foundEmployee->empId, foundEmployee->name);
    } else {
        printf("Employee with EmpID %d not found.\n", searchEmpId);
    }

    // Printing sorted employee records
    printf("\nSorted Employee Records:\n");
    inOrderTraversal(root);

    // Free allocated memory (not necessary for the sample program)
    // Add additional logic for freeing memory as needed

    return 0;
}
