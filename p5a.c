#include <stdio.h>
#include <string.h>

#define HASH_SIZE 53

// Structure to represent a book
struct Book {
    char title[100];
    int id;
    float cost;
    int isOccupied; 
};

// Function to calculate the hash value for a given Book ID
int hashFunction(int bookID, int attempt, int size) {
    return (bookID + attempt) % size;
}

// Function to search for a book by Book ID in the hash table using linear probing
struct Book* searchByID(struct Book hashTable[], int bookID, int size) {
    int attempt = 0;
    int index;

    do {
        index = hashFunction(bookID, attempt, size);
        if (hashTable[index].isOccupied && hashTable[index].id == bookID) {
            return &hashTable[index]; // Book found
        }
        attempt++;
    } while (hashTable[index].isOccupied && attempt < size);

    return NULL; // Book not found
}

// Function to insert a book into the hash table using linear probing
void insertBook(struct Book hashTable[], struct Book newBook, int size) {
    int attempt = 0;
    int index;

    do {
        index = hashFunction(newBook.id, attempt, size);
        if (!hashTable[index].isOccupied) {
            hashTable[index] = newBook; 
            hashTable[index].isOccupied = 1; 
            return;
        }
        attempt++;
    } while (attempt < size);

    printf("Hash table is full. Unable to insert book with ID %d\n", newBook.id);
}

int main() {
    struct Book hashTable[HASH_SIZE] = {{0}};

    int numBooks;
    // Input the number of books in the bookstore
    printf("Enter the number of books in the bookstore: ");
    scanf("%d", &numBooks);

    // Input details for each book
    for (int i = 0; i < numBooks; i++) {
        struct Book newBook;

        printf("Enter details for Book %d:\n", i + 1);
        printf("Title: ");
        scanf("%s", newBook.title);
        printf("ID: ");
        scanf("%d", &newBook.id);
        printf("Cost: ");
        scanf("%f", &newBook.cost);

        // Insert the book
        insertBook(hashTable, newBook, HASH_SIZE);
    }

    // Search for a book by Book ID 
    int searchID;
    printf("\nEnter the Book ID to search: ");
    scanf("%d", &searchID);

    struct Book* foundBook = searchByID(hashTable, searchID, HASH_SIZE);
    if (foundBook != NULL) {
        printf("Book found!\nTitle: %s\nID: %d\nCost: %.2f\n", foundBook->title, foundBook->id, foundBook->cost);
    } else {
        printf("Book not found by ID.\n");
    }

    return 0;
}
