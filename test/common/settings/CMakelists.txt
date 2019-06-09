add_executable(test_common_settings_test
               settings_json_factory_unittest.cpp
               settings_json_impl_unittest.cpp)

target_link_libraries(test_common_settings_test
                      settings
                      qxt_gtest_main)

add_test(testCommonSettingsTest
        ${CMAKE_CURRENT_BINARY_DIR}/test_common_settings_test)
