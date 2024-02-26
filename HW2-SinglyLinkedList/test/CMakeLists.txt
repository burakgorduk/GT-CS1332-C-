cmake_minimum_required(VERSION 3.10.0)

project (unitTest)

find_package(Catch2 3 REQUIRED)

add_executable(unitTest SinglyLinkedListTest.cpp)

target_link_libraries(unitTest PRIVATE Catch2::Catch2WithMain)

target_include_directories(unitTest PUBLIC ../include)

add_custom_target(test ALL $<TARGET_FILE:unitTest>)
