#include <boost/core/scoped_enum.hpp>

#include <iostream>

#include "severity.hpp"
#include "log_sink_factory.hpp"

int main()
{
    std::cout << static_cast<int>(boost::native_value(log_severity::notice)) << std::endl;
    BOOST_AUTO(logger, common::logger::log_sink_factory::instance()->get_logger());

    COMMON_LOGGER(*logger, log_severity::notice) << "Hello world!";

    COMMON_LOGGER(*logger, log_severity::debug)  << "Hello world at a debug level!";

    COMMON_LOGGER(*logger, log_severity::info)  << "Hello world at a info level!";

    COMMON_LOGGER(*logger, log_severity::emerg)  << "Hello world at a emerg level!";

    return 0;
}
