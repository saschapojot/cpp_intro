#include "class_example/class.hpp"
#include <vector>

int main()
{
    // Create a vector to store Book objects.
    std::vector<Book> library;

    // Create some Book objects using parameterized constructor.
    double ratings1[] = {4.5, 4.0, 5.0};//static array, located on stack, quick access, short length
    Book book1("The C++ Programming Language", "Bjarne Stroustrup", 1376, 59.99, ratings1, 3);

    double ratings2[] = {4.2, 3.9};
    Book book2("Effective Modern C++", "Scott Meyers", 334, 45.50, ratings2, 2);

    double ratings3[] = {4.8, 4.5, 4.7, 4.9};
    Book book3("Clean Code", "Robert C. Martin", 464, 39.95, ratings3, 4);

    // Add books to the vector using push_back.
    library.push_back(book1);
    library.push_back(book2);
    library.push_back(book3);
    // Demonstrate adding a rating to the first book in the vector.
    library[0].addRating(4.8);

    // Iterate over the vector using iterators to display each book.
    std::cout << "Library Books:\n";
    for (auto it = library.begin(); it != library.end(); ++it) {
        it->display();
    }
}