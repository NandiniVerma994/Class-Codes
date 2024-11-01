#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = val;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int val) {
    if(root == NULL) {
        return createNode(val);
    }
    if(val < root-> data) {
        root -> left = insert(root->left, val);
    }
    else if(val > root-> data) {
        root -> right = insert(root->right, val);
    }
    return root;
}

int minimum(struct Node* root) {
    struct Node* curr = root;
    if(root == NULL) {
        printf("Tree is empty");
        return -1;
    }
    while(curr->left != NULL) {
        curr = curr -> left;
    }
    return curr->data;
}

int main() {
    struct Node* root = NULL;
    int value;
    printf("Enter values to be inserted in a bst:");
    while(1) {
        printf("Enter a value:");
        scanf("%d", &value);
        if(value == -1) {
            break;
        }
        root = insert(root, value);
    }
    printf("Smallest element in BST is %d ", minimum(root));
    return 0;
}


