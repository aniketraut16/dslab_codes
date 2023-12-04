#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a student
struct Student {
    int studentId;
    char studentName[50];
    int semester;
    struct Student* next;
};

// Function to create a new student node
struct Student* createNode(int id, const char* name, int semester) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    if (newNode != NULL) {
        newNode->studentId = id;
        strcpy(newNode->studentName, name);
        newNode->semester = semester;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a new student at the end of the linked list
void insertNode(struct Student** head, int id, const char* name, int semester) {
    struct Student* newNode = createNode(id, name, semester);
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        return;
    }

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Student* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to delete a student node based on the student ID
void deleteNode(struct Student** head, int id) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Student* current = *head;
    struct Student* prev = NULL;

    // Traverse the list to find the node with the specified ID
    while (current != NULL && current->studentId != id) {
        prev = current;
        current = current->next;
    }

    // If the specified node is not found
    if (current == NULL) {
        printf("Student with ID %d not found. Cannot delete.\n", id);
        return;
    }

    // If the node to be deleted is the first node
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Student with ID %d deleted successfully.\n", id);
}

// Function to display the linked list
void displayList(struct Student* head) {
    printf("Student List:\n");
    while (head != NULL) {
        printf("ID: %d, Name: %s, Semester: %d\n", head->studentId, head->studentName, head->semester);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Student** head) {
    struct Student* current = *head;
    struct Student* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int main() {
    struct Student* head = NULL;

    insertNode(&head, 1, "Shubhman Gill", 77);
    insertNode(&head, 2, "Rohit Sharma", 45);
    insertNode(&head, 3, "Virat Kohli", 18);
    insertNode(&head, 4, "Shreyas Iyer", 41);
    insertNode(&head, 5, "KL Rahul", 1);
    insertNode(&head, 6, "Hardik Pandya", 33);
    insertNode(&head, 7, "Ravindra Jadeja", 8);
    insertNode(&head, 8, "Mohommad Shami", 11);
    insertNode(&head, 9, "Jasprit Bumrah", 93);
    insertNode(&head, 10, "Kuldeep Yadav", 23);
    insertNode(&head, 11, "Mohommad Siraj", 13);

    displayList(head);

    deleteNode(&head, 06);
    displayList(head);

    deleteNode(&head, 05);

    freeList(&head);

    return 0;
}
