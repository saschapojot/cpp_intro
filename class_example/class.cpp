//
// Created by adada on 15/4/2025.
//

#include "class.hpp"
// 1. Default Constructor
Book::Book()
    : title("Untitled"), author("Unknown"), pages(0), price(0.0),
      ratings(nullptr), ratingsCount(0) {
    std::cout << "Default constructor called\n";
}

// 2. Parameterized Constructor with ratings array
Book::Book(const std::string& t, const std::string& a, int p, double pr,
           const double* ratingsArr, size_t count)
    : title(t), author(a), pages(p), price(pr), ratingsCount(count) {

    if (count > 0) {
        ratings = new double[count];  // Traditional array allocation
        std::copy(ratingsArr, ratingsArr + count, ratings);  // Safe copy
    } else {
        ratings = nullptr;
    }
    std::cout << "Parameterized constructor with ratings called\n";
}

// 3. Copy Constructor (deep copy)
//python uses shallow copy
Book::Book(const Book& other)
    : title(other.title),
      author(other.author),
      pages(other.pages),
      price(other.price),
      ratingsCount(other.ratingsCount) {

    if (other.ratingsCount > 0) {
        ratings = new double[other.ratingsCount];
        std::copy(other.ratings, other.ratings + other.ratingsCount, ratings);
    } else {
        ratings = nullptr;
    }
    std::cout << "Copy constructor called\n";
}

// 4. Move Constructor
Book::Book(Book&& other) noexcept
    : title(std::move(other.title)),
      author(std::move(other.author)),
      pages(other.pages),
      price(other.price),
      ratings(other.ratings),       // Transfer ownership, copies the value of address to ratings
      ratingsCount(other.ratingsCount) {

    other.ratings = nullptr;       // Source no longer owns the array
    other.ratingsCount = 0;
    other.pages = 0;
    other.price = 0.0;
    std::cout << "Move constructor called\n";
}


// 5. Destructor
Book::~Book() {
    std::cout << "Destructor called for: " << title << "\n";
    delete[] ratings;  // Release array memory
}


// 6. Copy Assignment Operator
Book& Book::operator=(const Book& other) {
    if (this != &other) {  // Protect against self-assignment
        // Free existing resources
        delete[] ratings;

        // Copy simple members
        title = other.title;
        author = other.author;
        pages = other.pages;
        price = other.price;
        ratingsCount = other.ratingsCount;

        // Deep copy the array
        if (other.ratingsCount > 0) {
            ratings = new double[other.ratingsCount];
            std::copy(other.ratings, other.ratings + other.ratingsCount, ratings);
        } else {
            ratings = nullptr;
        }
    }
    std::cout << "Copy assignment called\n";
    return *this;
}


// 7. Move Assignment Operator
Book& Book::operator=(Book&& other) noexcept {
    if (this != &other) {
        // Free existing resources
        delete[] ratings;

        // Transfer ownership
        title = std::move(other.title);
        author = std::move(other.author);
        pages = other.pages;
        price = other.price;
        ratings = other.ratings;
        ratingsCount = other.ratingsCount;

        // Leave source in valid state
        other.ratings = nullptr;
        other.ratingsCount = 0;
        other.pages = 0;
        other.price = 0.0;
    }
    std::cout << "Move assignment called\n";
    return *this;
}

// Display method
void Book::display() const {
    std::cout << title << " by " << author
              << ", " << pages << " pages, $" << price << "\n";

    if (ratingsCount > 0) {
        std::cout << "Ratings: ";
        for (size_t i = 0; i < ratingsCount; ++i) {
            std::cout << ratings[i] << " ";
        }
        std::cout << "\n";
    }
}

// Method to add a rating (demonstrates array resizing)
void Book::addRating(double newRating) {
    // Create new array
    double* newRatings = new double[ratingsCount + 1];

    // Copy existing ratings
    for (size_t i = 0; i < ratingsCount; ++i) {
        newRatings[i] = ratings[i];
    }

    // Add new rating
    newRatings[ratingsCount] = newRating;

    // Delete old array and update pointer
    delete[] ratings;
    ratings = newRatings;
    ratingsCount++;
}