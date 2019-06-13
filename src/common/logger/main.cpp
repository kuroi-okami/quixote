#include <boost/core/scoped_enum.hpp>

#include <iostream>

#include "severity.hpp"
#include "log_sink_impl.hpp"

int main()
{
    std::cout << static_cast<int>(boost::native_value(log_severity::notice)) << std::endl;
    boost::shared_ptr<boost::log::sources::logger> logger = common::logger::log_sink_impl::get_instance()->get_logger();

    BOOST_LOG(*logger) << "Hello world!";

    return 0;
}
