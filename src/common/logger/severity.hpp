#ifndef QXT_SRC_COMMON_LOGGER_SEVERITY_HPP_
#define QXT_SRC_COMMON_LOGGER_SEVERITY_HPP_

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

#endif // !QXT_SRC_COMMON_LOGGER_SEVERITY_HPP_