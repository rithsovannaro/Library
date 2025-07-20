#pragma once
#include "Book.hpp"
#include <vector>

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book);
    void displayBooks() const;
    void searchBook(const std::string& title) const;
    void borrowBook(const std::string& title);
    void returnBook(const std::string& title);
};

