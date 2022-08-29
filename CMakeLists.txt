set(SOURCES
    src/main/Gradebook.cpp
    src/main/StudentLinkedList.cpp
)

cmake_minimum_required(VERSION 3.14)
project(SimpleGradebook VERSION 0.0.1)



add_executable(
    SimpleGradebook 
    ${SOURCES}
)

target_include_directories(SimpleGradebook
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)


# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY  https://github.com/google/googletest.git
    GIT_TAG         609281088cfefc76f9d0ce82e1ff6c30cc3591e5
    #FIND_PACKAGE_ARGS NAMES GTest
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    hello_test
    src/tests/hello_test.cpp
)
target_link_libraries(
    hello_test
    gtest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)
