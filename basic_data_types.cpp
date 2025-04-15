#include <iostream>//similar to import xxx in python

//main is entry point of an executable
int main() {
    // Integer types
    int age = 25;
    unsigned int distance = 1000;

    // Floating-point
    float pi = 3.14f;
    double precisePi = 3.1415926535;

    // Character
    char grade = 'A';
    wchar_t symbol = L'€';

    // Boolean
    bool isCppFun = true;

    // Output
    //std is a namespace, :: is scope operator,
    // in python's language, it is something like std.cout<<xxx
    std::cout << "Age: " << age << std::endl;
    std::cout << "Pi: " << pi << std::endl;
    std::cout << "Grade: " << grade << std::endl;
    std::cout << "Is C++ fun? " << isCppFun << std::endl;





    return 0;
}