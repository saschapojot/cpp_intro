#include <iostream>
#include <memory>  // Required for shared_ptr
//main is entry point of an executable
int main()
{
    int num = 42;       // Integer variable
    int* ptr = &num;    // Pointer storing address of 'num'

    std::cout << "Value of num: " << num << std::endl;      // 42
    std::cout << "Address of num: " << &num << std::endl;   // Memory address
    std::cout << "Value via pointer: " << *ptr << std::endl; // 42 (dereferencing)

    //modify the value of num
    *ptr=132;
    std::cout << "Value via pointer: " << *ptr << std::endl;



    // Allocate memory for 10 double
    int length=10;
    double* arr = new double[length];
    // Initialize array values
    for (int i = 0; i < 5; ++i) {
        arr[i]=1.1*static_cast<double>(i);
    }

    // Print array values
    for (int i = 0; i < length; ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    // Release the array memory
    delete[] arr;

    // 1. Create a shared_ptr to manage a double array, since c++ 11
    std::shared_ptr<double[]> arr_shared_ptr(new double[length]);
    // 2. Initialize array values
    for (size_t i = 0; i < length; ++i) {
        arr_shared_ptr[i] = (i + 1) * 1.1;  // 1.1, 2.2, 3.3, 4.4, 5.5
    }
    // 3. Access and print values
    std::cout << "Array values:" << std::endl;
    for (size_t i = 0; i < length; ++i) {
        std::cout << "arr_shared_ptr[" << i << "] = " << arr_shared_ptr[i] << std::endl;
    }

    // 4. Demonstrate shared ownership
    {
        std::shared_ptr<double[]> arr_copy = arr_shared_ptr;
        std::cout << "\nAfter copying (use count: " << arr_shared_ptr.use_count() << ")" << std::endl;
        std::cout << "arr_copy[2] = " << arr_copy[2] << std::endl;
    }

    // 5. Memory is automatically released when last shared_ptr goes out of scope
    std::cout << "\nFinal use count before destruction: " << arr_shared_ptr.use_count() << std::endl;
}
