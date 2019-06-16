cmake_minimum_required(VERSION 3.6.2)

set(CMAKE_CXX_FLAGS "-O3 -Wall -Werror -DBOOST_ALL_DYN_LINK -DBOOST_LOG_DYN_LINK")
set(CMAKE_CXX_STANDARD 11)

project(quixote)
enable_testing()

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