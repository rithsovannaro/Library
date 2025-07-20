#include "include/book.hpp"
#include "include/Library.hpp"
#include <iostream>

void menu() {
    std::cout << "=== Library Management System ===" << std::endl;
    std::cout << "1. Add Book" << std::endl;
    std::cout << "2. Display All Books" << std::endl;
    std::cout << "3. Search Book by Title" << std::endl;
    std::cout << "4. Borrow Book" << std::endl;
    std::cout << "5. Return Book" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Choose: ";
}

int main() {
    Library lib;
    int choice;
    using namespace std;
    string title, author, isbn;

    do {
        menu();
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter ISBN: ";
                getline(cin, isbn);
                lib.addBook(Book(title, author, isbn));
                break;
            case 2:
                lib.displayBooks();
                break;
            case 3:
                cout << "Enter title to search: ";
                getline(cin, title);
                lib.searchBook(title);
                break;
            case 4:
                cout << "Enter title to borrow: ";
                getline(cin, title);
                lib.borrowBook(title);
                break;
            case 5:
                cout << "Enter title to return: ";
                getline(cin, title);
                lib.returnBook(title);
                break;
            case 6:
                cout << "not found exiting" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 6);

    return 0;
}
