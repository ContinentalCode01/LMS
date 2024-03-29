#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the book structure
struct Book {
    char name[100];
    char author[100];
    int pages;
    struct Book* next;
};

// Function to create a new book node
struct Book* createBook(char name[], char author[], int pages) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newBook->name, name);
    strcpy(newBook->author, author);
    newBook->pages = pages;
    newBook->next = NULL;
    return newBook;
}

// Function to add a book to the library
void addBook(struct Book** head, char name[], char author[], int pages) {
    struct Book* newBook = createBook(name, author, pages);
    if (*head == NULL) {
        *head = newBook;
    } else {
        struct Book* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
}

// Function to delete a book by name
void deleteBook(struct Book** head, char name[]) {
    struct Book* temp = *head;
    struct Book* prev = NULL;
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Book not found.\n");
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Book '%s' deleted successfully.\n", name);
}

// Function to search for a book by name
void displaySearchResultsByName(struct Book* head, char name[]) {
    struct Book* temp = head;
    int found = 0;
    printf("\n+----------------------------------------------------------------+\n");
    printf("| %-30s | %-20s | %-6s |\n", "Book Name", "Author", "Pages");
    printf("+----------------------------------------------------------------+\n");
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("| %-30s | %-20s | %-6d |\n", temp->name, temp->author, temp->pages);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("| %-30s | %-20s | %-6s |\n", "No matching books found", "", "");
    }
    printf("+----------------------------------------------------------------+\n");
}

// Function to search for a book by author
void displaySearchResultsByAuthor(struct Book* head, char author[]) {
    struct Book* temp = head;
    int found = 0;
    printf("\n+----------------------------------------------------------------+\n");
    printf("| %-30s | %-20s | %-6s |\n", "Book Name", "Author", "Pages");
    printf("+----------------------------------------------------------------+\n");
    while (temp != NULL) {
        if (strcmp(temp->author, author) == 0) {
            printf("| %-30s | %-20s | %-6d |\n", temp->name, temp->author, temp->pages);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("| %-30s | %-20s | %-6s |\n", "No matching books found", "", "");
    }
    printf("+----------------------------------------------------------------+\n");
}

// Function to display all books
void displayBooksInTable(struct Book* head) {
    struct Book* temp = head;
    printf("\n+----------------------------------------------------------------+\n");
    printf("| %-30s | %-20s | %-6s |\n", "Book Name", "Author", "Pages");
    printf("+----------------------------------------------------------------+\n");
    while (temp != NULL) {
        printf("| %-30s | %-20s | %-6d |\n", temp->name, temp->author, temp->pages);
        printf("+----------------------------------------------------------------+\n");
        temp = temp->next;
    }
}

int main() {
    struct Book* library = NULL;
    int choice;
    char name[100], author[100];
    int pages;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Search by Book Name\n");
        printf("4. Search by Author Name\n");
        printf("5. Display All Books\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nADD BOOK MENU\n\n");
                printf("Enter book name: ");
                scanf("%s", name);
                printf("Enter author name: ");
                scanf("%s", author);
                printf("Enter number of pages: ");
                scanf("%d", &pages);
                addBook(&library, name, author, pages);
                break;
            case 2:
            printf("\nDELETE BOOK MENU\n\n");
                printf("Enter book name to delete: ");
                scanf("%s", name);
                deleteBook(&library, name);
                break;
            case 3:
            printf("\nSEARCH By BOOK NAME MENU\n\n");
                printf("Enter book name to search: ");
                scanf("%s", name);
                displaySearchResultsByName(library, name);
                break;
            case 4:
            printf("\nSEARCH By AUTHOR NAME MENU\n\n");
                printf("Enter author name to search: ");
                scanf("%s", author);
                displaySearchResultsByAuthor(library,author);
                break;
            case 5:
            printf("\nDISPLAYING BOOKS\n\n");
                displayBooksInTable(library);
                break;
            case 6:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}