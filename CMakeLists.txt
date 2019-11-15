cmake_minimum_required(VERSION 3.6.2)

set(CMAKE_CXX_FLAGS "-O3 -Wall -Werror -DBOOST_ALL_DYN_LINK -DBOOST_LOG_DYN_LINK")
set(CMAKE_CXX_STANDARD 11)

project(quixote)

# Configure ctest with custom memcheck options
include(CTest)
set( MEMORYCHECK_COMMAND_OPTIONS
     "--leak-check=full  --show-reachable=yes  --undef-value-errors=yes \
      --track-origins=no  --child-silent-after-fork=yes  --trace-children=no"
     CACHE STRING "Valgrind memcheck flags, to be used by ctest")

# Configure third party dependancies
add_subdirectory(third_party)

include_directories(${GTEST_INCLUDE_DIR}
                    ${GMOCK_INCLUDE_DIR}
                    ${GTEST_MAIN_PATH}
                    ${BOOST_INCLUDE_DIR}
                    src
                    )

link_directories(${BOOST_LINK_DIR}
                 ${GTEST_LINK_DIR}
                 ${GMOCK_LINK_DIR})

add_subdirectory(src)
add_subdirectory(test)
