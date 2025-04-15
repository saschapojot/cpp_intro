cmake_minimum_required(VERSION 3.28)
project(cpp_intro)

set(CMAKE_CXX_STANDARD 17)

add_executable(basic_data_types basic_data_types.cpp)
add_executable(pointer pointer.cpp)
add_executable(refs refs.cpp)
add_executable(class run_class.cpp class_example/class.cpp class_example/class.hpp)
