//
// Created by adada on 15/4/2025.
//

#ifndef CLASS_HPP
#define CLASS_HPP
#include <iostream>
#include <string>
#include <algorithm> // for std::copy

class Book {
//class is private by default, struct is public by default
private:
    std::string title;
    std::string author;
    int pages;
    double price;
    double* ratings;    // Traditional pointer to dynamic array
    size_t ratingsCount;
public:
    // 1. Default Constructor
    Book();

    // 2. Parameterized Constructor with ratings array
    Book(const std::string& t, const std::string& a, int p, double pr,
         const double* ratingsArr, size_t count);

    // 3. Copy Constructor (deep copy)
    Book(const Book& other);

    // 4. Move Constructor
    Book(Book&& other) noexcept;// do not throw execption such as bad_alloc

    // 5. Destructor
    ~Book();

    // 6. Copy Assignment Operator
    Book& operator=(const Book& other);

    // 7. Move Assignment Operator
    Book& operator=(Book&& other) noexcept;

    // Display method
    void display() const;

    // Method to add a rating (demonstrates array resizing)
    void addRating(double newRating);




};

#endif //CLASS_HPP
