add_library(qxt_gtest_main
            main.cpp)

target_link_libraries(qxt_gtest_main
                      PUBLIC  gtest
                              gmock)
