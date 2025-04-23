#include <iostream>
//Pass by Reference
void increment(int& num1, int &num2, int num3) {
    num1++;  // Directly modifies the original
    num2+=4;
    num3++;
}
//Pass by Const Reference (Read Only)
void printLargeString(const std::string& str) {
    // str cannot be modified here
    std::cout << str << "\n";

}

// Return reference to array element
int& getElement(int arr[], int index) {
    return arr[index];
}
int main() {
    int original = 42;

    // Create a reference (alias) to 'original'
    int& ref = original;
    int cpy_original=original;
    std::cout << "Original: " << original << "\n";  // 42
    std::cout << "Reference: " << ref << "\n";      // 42
    std::cout << "cpy_original: " << cpy_original << "\n";      // 42
    // Modify through reference
    ref = 100;
    cpy_original=39;
    std::cout << "After modification:\n";
    std::cout << "Original: " << original << "\n";  // 100
    std::cout << "Reference: " << ref << "\n";      // 100
    std::cout << "cpy_original: " << cpy_original << "\n";
    std::cout << "Original: " << original << "\n";

    // pass by reference
    int val1=5;
    int val2=6;
    int val3=10;
    std::cout<<"before increment, val1="<<val1<<", val2="<<val2<<", val3="<<val3<<std::endl;
    increment(val1,val2,val3);
    std::cout<<"after increment, val1="<<val1<<", val2="<<val2<<", val3="<<val3<<std::endl;

    //const reference
    std::string text = "Very long string...";
    printLargeString(text);  // No copy made
    //return reference
    int numbers[] = {10, 20, 30};

    // Modify array through returned reference
    getElement(numbers, 1) = 99;

    std::cout << numbers[1]<<std::endl;  // Output: 99

    int arr[] = {1, 2, 3, 4, 5};

    // Modify array elements
    for (int& num : arr) {
        num *= 2;
    }

    for (int num : arr) {
        std::cout << num << " ";  // Output: 2 4 6 8 10
    }
    std::cout<<std::endl;

    //elements not modified
    for (int num: arr)
    {
        num*=2;
    }
    for (int num : arr) {
        std::cout << num << " ";  // Output: 2 4 6 8 10
    }
    std::cout<<std::endl;
    //Range-Based For Loops
    return 0;
}