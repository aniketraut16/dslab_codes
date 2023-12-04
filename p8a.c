#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

struct Employee {
    char phoneNumber[15];
    char information[50];
};

struct Node {
    struct Employee data;
    struct Node* next;
};

struct HashTable {
    struct Node* table[TABLE_SIZE];
};

int hashFunction(char* phoneNumber) {
    int sum = 0;
    for (int i = 0; phoneNumber[i] != '\0'; i++) {
        sum += phoneNumber[i];
    }
    return sum % TABLE_SIZE;
}

void insertRecord(struct HashTable* hashTable, struct Employee employee) {
    int index = hashFunction(employee.phoneNumber);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = employee;
    newNode->next = NULL;

    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    } else {
        newNode->next = hashTable->table[index];
        hashTable->table[index] = newNode;
    }

    printf("Record inserted successfully.\n");
}

void searchRecord(struct HashTable* hashTable, char* phoneNumber) {
    int index = hashFunction(phoneNumber);

    struct Node* current = hashTable->table[index];
    while (current != NULL) {
        if (strcmp(current->data.phoneNumber, phoneNumber) == 0) {
            printf("Phone Number: %s\n", current->data.phoneNumber);
            printf("Information: %s\n", current->data.information);
            return;
        }
        current = current->next;
    }

    printf("Record not found for phone number %s.\n", phoneNumber);
}

void deleteRecord(struct HashTable* hashTable, char* phoneNumber) {
    int index = hashFunction(phoneNumber);

    struct Node* current = hashTable->table[index];
    struct Node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->data.phoneNumber, phoneNumber) == 0) {
            if (prev == NULL) {
                hashTable->table[index] = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            printf("Record deleted successfully.\n");
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Record not found for phone number %s.\n", phoneNumber);
}

int main() {
    struct HashTable hashTable;
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable.table[i] = NULL;
    }

    int choice;
    struct Employee employee;
    char phoneNumber[15];

    do {
        printf("\nMenu:\n");
        printf("1. Insert Record\n");
        printf("2. Search Record\n");
        printf("3. Delete Record\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter phone number: ");
                scanf("%s", employee.phoneNumber);
                printf("Enter information: ");
                scanf(" %[^\n]s", employee.information);
                insertRecord(&hashTable, employee);
                break;
            case 2:
                printf("Enter phone number to search: ");
                scanf("%s", phoneNumber);
                searchRecord(&hashTable, phoneNumber);
                break;
            case 3:
                printf("Enter phone number to delete: ");
                scanf("%s", phoneNumber);
                deleteRecord(&hashTable, phoneNumber);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
