cmake_minimum_required(VERSION 3.20)
project(Linked_List)

set(CMAKE_CXX_STANDARD 23)

add_executable(Linked_List main.cpp)

target_include_directories(Linked_List PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
