#ifndef SRC_COMMON_LOGGER_SEVERITY_
#define SRC_COMMON_LOGGER_SEVERITY_

#include <boost/core/scoped_enum.hpp>

BOOST_SCOPED_ENUM_DECLARE_BEGIN(log_severity)
{
    emerg,
    alert,
    crit,
    err,
    warning,
    notice,
    info,
    debug
}
BOOST_SCOPED_ENUM_DECLARE_END(log_severity)

#endif // !SRC_COMMON_LOGGER_SEVERITY_