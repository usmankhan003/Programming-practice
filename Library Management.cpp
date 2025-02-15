#include <iostream>
#include <string>
using namespace std;

// Maximum number of books allowed in the library
const int MAX_BOOKS = 100;

// Function prototypes for our main functions
void addBook(string titles[], string authors[], string isbns[], int &bookCount);
void searchBook(const string titles[], const string authors[], const string isbns[], int bookCount);
int findBookIndex(const string titles[], int bookCount, const string &title);

int main() {
    // Arrays to store book information
    string titles[MAX_BOOKS], authors[MAX_BOOKS], isbns[MAX_BOOKS];
    int bookCount = 0; // How many books are currently stored
    int choice;        // To store the user's menu choice

    // Main loop that keeps the program running until you choose to exit
    while (true) {
        // Display the menu
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        cin.ignore(); // Clear the newline from the input buffer

        // Validate the choice
        if (choice < 1 || choice > 3) {
            cout << "Invalid input! Please enter a number between 1 and 3.\n";
            continue;
        }

        // Call the corresponding function based on the user's choice
        if (choice == 1) {
            addBook(titles, authors, isbns, bookCount);
        } else if (choice == 2) {
            searchBook(titles, authors, isbns, bookCount);
        } else if (choice == 3) {
            cout << "Exiting program. Goodbye!\n";
            break;
        }
    }
    return 0;
}

// This function finds the index of a book by its title.
// Returns the index if found, or -1 if not found.
int findBookIndex(const string titles[], int bookCount, const string &title) {
    for (int i = 0; i < bookCount; i++) {
        if (titles[i] == title)
            return i;
    }
    return -1;
}

// This helper function asks the user a yes/no question and returns true if the answer is 'y' and false if 'n'.
bool getYesNoInput(const string &prompt) {
    char answer;
    while (true) {
        cout << prompt << " (y/n): ";
        cin >> answer;
        cin.ignore(); // Clear the newline character from the input buffer
        if (answer == 'y' || answer == 'Y')
            return true;
        else if (answer == 'n' || answer == 'N')
            return false;
        else
            cout << "Invalid input! Please enter y or n.\n";
    }
}

// This function allows the user to add one or more books to the library.
void addBook(string titles[], string authors[], string isbns[], int &bookCount) {
    do {
        if (bookCount >= MAX_BOOKS) {
            cout << "Library is full!\n";
            return;
        }

        cout << "\n-- Add Book --\n";
        cout << "Enter book title: ";
        getline(cin, titles[bookCount]);  // Read the book title
        cout << "Enter book author: ";
        getline(cin, authors[bookCount]);  // Read the book author
        cout << "Enter book ISBN: ";
        getline(cin, isbns[bookCount]);    // Read the book ISBN

        bookCount++;  // Increase the number of books
        cout << "Book added successfully!\n";
    } while (getYesNoInput("Do you want to add another book?"));
}

// This function allows the user to search for a book by title.
void searchBook(const string titles[], const string authors[], const string isbns[], int bookCount) {
    if (bookCount == 0) {
        cout << "No books in library!\n";
        return;
    }
    
    do {
        cout << "\n-- Search Book --\n";
        string title;
        cout << "Enter the title of the book to search: ";
        getline(cin, title);  // Get the title to search for

        int index = findBookIndex(titles, bookCount, title);
        if (index != -1) {
            cout << "\nBook found:\n";
            cout << "Title: " << titles[index] << "\n";
            cout << "Author: " << authors[index] << "\n";
            cout << "ISBN: " << isbns[index] << "\n";
        } else {
            cout << "Book not found!\n";
        }
    } while (getYesNoInput("Do you want to search for another book?"));

    //Void function cannot return any value!

}