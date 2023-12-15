#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

struct Client {
    char name[50];
    char phoneNumber[15];
};

struct Node {
    struct Client data;
    struct Node* next;
};

struct HashTable {
    struct Node* table[TABLE_SIZE];
};

int hashFunction(char* name) {
    int sum = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        sum += name[i];
    }
    return sum % TABLE_SIZE;
}

void insertClient(struct HashTable* hashTable, struct Client client) {
    int index = hashFunction(client.name);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = client;
    newNode->next = NULL;

    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    } else {
        newNode->next = hashTable->table[index];
        hashTable->table[index] = newNode;
    }

    printf("Client information inserted successfully.\n");
}

void searchClient(struct HashTable* hashTable, char* name) {
    int index = hashFunction(name);

    struct Node* current = hashTable->table[index];
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            printf("Client Name: %s\n", current->data.name);
            printf("Phone Number: %s\n", current->data.phoneNumber);
            return;
        }
        current = current->next;
    }

    printf("Client not found in the telephone book.\n");
}

int main() {
    struct HashTable hashTable;
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable.table[i] = NULL;
    }

    int N;
    printf("Enter the number of clients: ");
    scanf("%d", &N);

    struct Client client;

    for (int i = 0; i < N; i++) {
        printf("Enter client name: ");
        scanf("%s", client.name);
        printf("Enter phone number: ");
        scanf("%s", client.phoneNumber);

        insertClient(&hashTable, client);
    }

    char searchName[50];
    printf("Enter client name to search: ");
    scanf("%s", searchName);

    searchClient(&hashTable, searchName);

    return 0;
}
