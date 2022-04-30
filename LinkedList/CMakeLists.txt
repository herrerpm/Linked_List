add_library(LinkedList SHARED
        LinkedList.h
        LinkedList.cpp)
target_include_directories(LinkedList PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})