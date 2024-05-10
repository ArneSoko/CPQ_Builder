cmake_minimum_required(VERSION 3.0)
project(MyProject)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable target
add_executable(MyProject main.cpp Cart.cpp CartItem.cpp Item.cpp Attr.cpp)

# Include directory for header files
target_include_directories(MyProject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

