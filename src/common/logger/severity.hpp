#ifndef QXT_SRC_COMMON_LOGGER_SEVERITY_HPP_
#define QXT_SRC_COMMON_LOGGER_SEVERITY_HPP_

#include <boost/core/scoped_enum.hpp>
#include <boost/log/expressions/keyword.hpp>
#include <boost/log/utility/manipulators.hpp>
#include <boost/current_function.hpp>
#include <ostream>
#include <string.h>

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

std::ostream& operator<< (std::ostream& strm, log_severity level);

#define __FILENAME__(offset) \
    (strstr(__FILE__, offset) ? strstr(__FILE__, offset) + strlen(offset) + 1  : __FILE__)

#define COMMON_LOGGER(logger, lvl)\
    BOOST_LOG_SEV(logger, lvl)\
    << boost::log::add_value("File", __FILENAME__("quixote") )\
    << boost::log::add_value("Function", BOOST_CURRENT_FUNCTION)\
    << boost::log::add_value("Line", __LINE__)\

#endif // !QXT_SRC_COMMON_LOGGER_SEVERITY_HPP_