#include "Library.hpp"
#include <iostream>
#include <iomanip>


void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::displayBooks() const{
    std::cout << std::left
            << std::setw(12) << "Title" 
            << std::setw(20) << "Author" 
            << std::setw(30) << "ISBN" << std::endl;

    for (const auto& b : books) {
        std::cout << std::left
                << std::setw(12) << b.getTitle() 
                << std::setw(20) << b.getAuthor() 
                << std::setw(30) << b.getISBN() << std::endl;
    }
}
void Library::searchBook(const std::string& title) const {
    std::cout << std::left
            << std::setw(12) << "Title" 
            << std::setw(20) << "Author" 
            << std::setw(30) << "ISBN" << std::endl;
    bool found = false;
    for (const auto& b : books) {
        std::cout << std::left
                << std::setw(12) << b.getTitle() 
                << std::setw(20) << b.getAuthor() 
                << std::setw(30) << b.getISBN() << std::endl;
        if (b.getTitle() == title) {
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
