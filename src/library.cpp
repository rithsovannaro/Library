#include "Library.hpp"
#include <iostream>
#include <iomanip>


void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::displayBooks() const{
    std::cout << std::left
            << std::setw(5) << "Title"
            << std::setw(15) << "Author"
            << std::setw(20) << "ISBN" << std::endl;

    for (const auto& b : books) {
        std::cout << std::left
                << std::setw(5) << b.getTitle()
                << std::setw(15) << b.getAuthor()
                << std::setw(20) << b.getISBN() << std::endl;
    }
}
void Library::searchBook(const std::string& title) const {
    bool found = false;
    for (const auto& book : books) {
        if (book.getTitle() == title) {
            book.display();
            found = true;
        }
    }
    if (!found) std::cout << "Book not found." << std::endl;
}

void Library::borrowBook(const std::string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title && book.isAvailable()) {
            book.borrowBook();
            std::cout << "Book borrowed successfully." << std::endl;
            return;
        }
    }
    std::cout << "Book not available or not found." << std::endl;
}

void Library::returnBook(const std::string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title && !book.isAvailable()) {
            book.returnBook();
            std::cout << "Book returned successfully." << std::endl;
            return;
        }
    }
    std::cout << "Book not found or already available." << std::endl;
}
