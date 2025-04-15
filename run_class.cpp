#include "./class_example/class.hpp"


int main()
{
    // Example of using the default constructor
    std::cout << "=== Creating default book (using default constructor) ===\n";
    Book defaultBook;
    defaultBook.display();


    // Sample ratings array for further examples
    double initialRatings[] = {4.5, 5.0, 4.0};

    std::cout << "\n=== Creating book1 (using parameterized constructor) ===\n";
    Book book1("Effective C++", "Scott Meyers", 256, 39.99, initialRatings, 3);
    book1.display();

    //copy constructor
    std::cout << "\n=== Copy construction (book2) ===\n";
    Book book2 = book1;  // Copy constructor
    book2.display();

    //move constructor
    std::cout << "\n=== Move construction (book3) ===\n";
    Book book3 = std::move(book1);  // Move constructor
    book3.display();

    //
    std::cout << "\n=== Adding rating to book3 ===\n";
    book3.addRating(4.8);
    book3.display();

    // reallocate array
    std::cout << "\n=== Copy assignment (book4 = book3) ===\n";
    Book book4;
    book4 = book3;  // Copy assignment
    book4.display();


    //move assignment  constructor
    std::cout << "\n=== Move assignment (book5 = std::move(book3)) ===\n";
    Book book5;
    book5 = std::move(book3);  // Move assignment
    book5.display();

    std::cout << "\n=== End of scope ===\n";



}