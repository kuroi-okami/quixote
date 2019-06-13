add_library(log_sink
            log_sink_impl.cpp)

target_link_libraries(log_sink
                      PUBLIC
                      pthread
                      boost_thread
                      boost_log
                      boost_system
                      boost_filesystem
                      )

add_executable(beep_boop
               main.cpp)

target_link_libraries(beep_boop
                      log_sink
                      /src/quixote/third_party/boost-1.70/lib/libboost_filesystem.so.1.70.0
                      )

