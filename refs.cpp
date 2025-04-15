#include <iostream>
//Pass by Reference
void increment(int& num1, int &num2) {
    num1++;  // Directly modifies the original
    num2+=4;
}

int main() {
    int original = 42;

    // Create a reference (alias) to 'original'
    int& ref = original;

    std::cout << "Original: " << original << "\n";  // 42
    std::cout << "Reference: " << ref << "\n";      // 42

    // Modify through reference
    ref = 100;

    std::cout << "After modification:\n";
    std::cout << "Original: " << original << "\n";  // 100
    std::cout << "Reference: " << ref << "\n";      // 100


    // pass by reference
    int val1=5;
    int val2=6;
    increment(val1,val2);
    return 0;
}