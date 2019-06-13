add_subdirectory(googletest)

set(BOOST_DIR         ${CMAKE_CURRENT_SOURCE_DIR}/boost)
set(BOOST_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/boost-1.70)
set(BOOTSTRAP_COMMAND ./bootstrap.sh)
set(BJAM_COMMAND      ./b2)
set(BOOST_LOG_BUILD   "--with-log variant=release define=BOOST_LOG_WITHOUT_EVENT_LOG stage")

if(NOT EXISTS ${BOOST_INSTALL_DIR})
    if(EXISTS ${BOOST_DIR})
        message("Generating boost install:")
        execute_process(
            WORKING_DIRECTORY ${BOOST_DIR}
            COMMAND ${BOOTSTRAP_COMMAND} --prefix=${BOOST_INSTALL_DIR})
        execute_process(
            WORKING_DIRECTORY ${BOOST_DIR}
            COMMAND ${BJAM_COMMAND} install -j4)
    else()
        message("ERROR")
    endif()
endif()

# Propagate the include directories backwards
set(BOOST_INCLUDE_DIR ${BOOST_INSTALL_DIR}/include PARENT_SCOPE)
set(GTEST_INCLUDE_DIR ${gtest_SOURCE_DIR}/include  PARENT_SCOPE)
set(GMOCK_INCLUDE_DIR ${gmock_SOURCE_DIR}/include  PARENT_SCOPE)

# Propagate the link libraries backwards
set(BOOST_LINK_DIR ${BOOST_INSTALL_DIR}/lib PARENT_SCOPE)
set(GTEST_LINK_DIR ${CMAKE_BINARY_DIR}/googletest/googlemock/gtest)
set(GMOCK_LINK_DIR ${CMAKE_BINARY_DIR}/googletest/googlemock)
