cmake_minimum_required(VERSION 3.6.2)

set(CMAKE_CXX_FLAGS "-g -Wall -Werror")
set(CMAKE_CXX_STANDARD 11)

project(quixote)
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include
		    ${gmock_SOURCE_DIR}/include)

add_subdirectory(googletest)
add_subdirectory(scratchspace)

