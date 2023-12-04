#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to create a circular linked list of n nodes
struct Node* createCircularLinkedList(int n) {
    if (n <= 0) {
        return NULL;
    }

    struct Node* head = createNode(1);
    struct Node* current = head;

    for (int i = 2; i <= n; ++i) {
        current->next = createNode(i);
        current = current->next;
    }

    // Make the linked list circular by connecting the last node to the head
    current->next = head;

    return head;
}

// Function to solve Josephus' problem and find the survivor
int josephus(int n, int k) {
    struct Node* head = createCircularLinkedList(n);
    struct Node* current = head;
    struct Node* prev = NULL;

    // Traverse the circular linked list until only one node remains
    while (current->next != current) {
        // Skip k-1 nodes
        for (int i = 0; i < k - 1; ++i) {
            prev = current;
            current = current->next;
        }

        // Remove the k-th node
        prev->next = current->next;
        printf("Eliminated: %d\n", current->data);
        free(current);
        current = prev->next;
    }

    // Return the data of the survivor
    int survivor = current->data;
    free(current); // Free the last remaining node
    return survivor;
}

int main() {
    int n, k;

    printf("Enter the number of people (n): ");
    scanf("%d", &n);
    printf("Enter the counting interval (k): ");
    scanf("%d", &k);

    int survivor = josephus(n, k);
    printf("The survivor is at position %d.\n", survivor);

    return 0;
}
