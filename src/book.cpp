#include "Book.hpp"
#include <iostream>

Book::Book(std::string title, std::string author, std::string isbn)
    : title(title), author(author), isbn(isbn), available(true) {}

std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getISBN() const { return isbn; }
bool Book::isAvailable() const { return available; }

void Book::borrowBook() { available = false; }
void Book::returnBook() { available = true; }

void Book::display() const {
    std::cout << "Title: " << title
              << "Author: " << author
              << "ISBN: " << isbn
              << "Status: " << (available ? "Available" : "Borrowed") << "\n";
}
