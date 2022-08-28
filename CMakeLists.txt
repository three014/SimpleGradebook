set(SOURCES
    src/Gradebook.cpp
    src/StudentLinkedList.cpp
)

cmake_minimum_required(VERSION 3.14)
project(SimpleGradebook VERSION 0.0.1)



add_executable(SimpleGradebook ${SOURCES})

target_include_directories(SimpleGradebook
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)


# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
