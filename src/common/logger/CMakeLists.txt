add_library(log_sink
            log_sink_impl.cpp
            log_sink_factory.cpp
            severity.cpp)

target_link_libraries(log_sink
                      PUBLIC
                      pthread
                      boost_thread
                      boost_log
                      boost_system
                      boost_filesystem
                      settings
                      )
