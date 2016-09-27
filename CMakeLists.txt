cmake_minimum_required(VERSION 3.5.1)
set(PROJECT_NAME bimaru-solver)
project(${PROJECT_NAME} C CXX)

find_package(Threads REQUIRED)

add_definitions(-Wall -std=c++11 -pthread)

# Location of the header files
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDES})

# Add source files
file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cc")

# Build everything as a library
add_library(bimarusolver SHARED ${SRC_FILES})

# Testing
add_subdirectory(ext/gtest)

enable_testing()
set(PROJECT_TEST_NAME ${PROJECT_NAME}_test)
include_directories(${GTEST_INCLUDE_DIRS} ${COMMON_INCLUDES})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cc)
add_executable(${PROJECT_TEST_NAME} ${SRC_FILES} ${TEST_SRC_FILES})
add_dependencies(${PROJECT_TEST_NAME} googletest)

target_link_libraries(${PROJECT_TEST_NAME}
    ${GTEST_LIBS_DIR}/libgtest_main.a
    ${GTEST_LIBS_DIR}/libgtest.a
    )

target_link_libraries(${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT})

add_test(test1 ${PROJECT_TEST_NAME})
