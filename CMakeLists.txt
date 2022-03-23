project(cpp_experiments)
cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)

include_directories("libs/")

add_library(ut "libs/ut.hpp")
set_target_properties(ut PROPERTIES LINKER_LANGUAGE CXX)

add_library(lab01 "src/Fraction.cpp" "src/Circle.cpp"
                  "src/Point.cpp" "src/DynamicArray.cpp")

add_executable(tests "src/tests.cpp")
target_link_libraries(tests lab01 ut)
