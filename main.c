#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Library
{
    char  bookName[50];
    char  author[50];
    int   pages;
    float price;
};

// Function prototypes
void addBook(struct Library lib[], int *count);
void listAllBooks(struct Library lib[], int count);
void listByAuthor(struct Library lib[], int count);
void showTotalBooks(int count);
void printMenu();

int main()
{
    struct Library lib[100];
    int count = 0;
    int choice;

    do
    {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addBook(lib, &count);
                break;
            case 2:
                listAllBooks(lib, count);
                break;
            case 3:
                listByAuthor(lib, count);
                break;
            case 4:
                showTotalBooks(count);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    while (choice != 5);

    return 0;
}

// Print main menu
void printMenu()
{
    printf("\n========================================\n");
    printf("      LIBRARY MANAGEMENT SYSTEM         \n");
    printf("========================================\n");
    printf("1. Add Book\n");
    printf("2. List All Books\n");
    printf("3. List Books by Author\n");
    printf("4. Show Total Number of Books\n");
    printf("5. Exit\n");
    printf("========================================\n");
}

// Add a new book to the library
void addBook(struct Library lib[], int *count)
{
    printf("Enter book name: ");
    scanf("%s", lib[*count].bookName);

    printf("Enter author name: ");
    scanf("%s", lib[*count].author);

    printf("Enter number of pages: ");
    scanf("%d", &lib[*count].pages);

    printf("Enter price: ");
    scanf("%f", &lib[*count].price);

    (*count)++;
    printf("Book added successfully.\n");
}

// List all books in the library
void listAllBooks(struct Library lib[], int count)
{
    if (count == 0)
    {
        printf("No books in the library.\n");
        return;
    }

    printf("\n--- All Books ---\n");
    int j;
    for (j = 0; j < count; j++)
    {
        printf("\nBook %d:\n",       j + 1);
        printf("  Name:   %s\n",    lib[j].bookName);
        printf("  Author: %s\n",    lib[j].author);
        printf("  Pages:  %d\n",    lib[j].pages);
        printf("  Price:  %.2f\n",  lib[j].price);
    }
}

// List all books by a specific author
void listByAuthor(struct Library lib[], int count)
{
    char author[50];
    int  found = 0;

    printf("Enter author name: ");
    scanf("%s", author);

    printf("\n--- Books by %s ---\n", author);

    int j;
    for (j = 0; j < count; j++)
    {
        if (strcmp(author, lib[j].author) == 0)
        {
            printf("\nBook name:  %s\n",   lib[j].bookName);
            printf("Author:     %s\n",     lib[j].author);
            printf("Pages:      %d\n",     lib[j].pages);
            printf("Price:      %.2f\n",   lib[j].price);
            found++;
        }
    }

    if (found == 0)
    {
        printf("No books found for this author.\n");
    }
}

// Show total number of books
void showTotalBooks(int count)
{
    printf("\nTotal number of books: %d\n", count);
}
