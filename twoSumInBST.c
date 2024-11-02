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

void inorder(struct Node* root, int arr[], int *i) {
    if(root != NULL) {
        inorder(root->left, arr, i);
        arr[(*i)++] = root -> data;
        inorder(root->right, arr, i);
    }
}

void pairSum(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int found = 0;
    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == target) {
            found = 1;
            printf("Pair found %d and %d", arr[left], arr[right]);
            left++;
            right--;
        }
        else if(sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
    if(!found) {
        printf("No pair found. ");
    }
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
    int x;
    printf("Enter the target sum: ");
    scanf("%d", &x);
    int arr[100];
    int index = 0;
    inorder(root, arr, &index);//as the value of i is always changing

    pairSum(arr, index, x);
    return 0;
}


