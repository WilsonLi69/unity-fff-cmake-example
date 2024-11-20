cmake_minimum_required(VERSION 3.14)
project(testsuit)

set(CMAKE_C_STANDARD 11)

# Enable CTest
enable_testing()

# Add externals
add_subdirectory(external)

# Add examples
add_subdirectory(examples)
