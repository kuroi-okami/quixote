#include "severity.hpp"
#include <ostream>

std::ostream& operator<< (std::ostream& strm, log_severity level)
{
    static const char* strings[] =
    {
        "emerg",
        "alert",
        "crit",
        "err",
        "warning",
        "notice",
        "info",
        "debug"
    };

    if (static_cast< std::size_t >(level) < sizeof(strings) / sizeof(*strings))
        strm << strings[boost::underlying_cast<unsigned int>(level)];
    else
        strm << static_cast< int >(level);

    return strm;
}