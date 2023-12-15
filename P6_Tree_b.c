#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isCommonMember(struct Node* root1, struct Node* root2, int target) {
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }

    if (root1->data == target && root2->data == target) {
        return 1;
    }

    int leftCheck = isCommonMember(root1->left, root2->left, target);
    int rightCheck = isCommonMember(root1->right, root2->right, target);

    return leftCheck || rightCheck;
}

int main() {
    // Assume two organizational trees with the same structure
    struct Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);

    struct Node* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(6);
    root2->left->right = createNode(5);

    int target;

    printf("Enter the target member to check for commonality: ");
    scanf("%d", &target);

    if (isCommonMember(root1, root2, target)) {
        printf("%d is a common member in both organizations.\n", target);
    } else {
        printf("%d is not a common member in both organizations.\n", target);
    }

    return 0;
}
