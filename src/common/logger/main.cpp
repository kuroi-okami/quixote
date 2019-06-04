#include <boost/core/scoped_enum.hpp>

#include <iostream>

#include "severity.hpp"

int main()
{
    std::cout << static_cast<int>(boost::native_value(log_severity::notice)) << std::endl;
    return 0;
}