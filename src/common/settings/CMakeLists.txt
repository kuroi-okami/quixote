add_library(settings
            settings_impl_json.cpp
            settings_json_factory.cpp)

target_link_libraries(settings
               PUBLIC boost_filesystem)