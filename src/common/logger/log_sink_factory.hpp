#ifndef QXT_SRC_COMMON_LOGGER_LOG_SINK_FACTORY_HPP_
#define QXT_SRC_COMMON_LOGGER_LOG_SINK_FACTORY_HPP_

#include "log_sink.hpp"

#include <boost/shared_ptr.hpp>
#include <boost/log/sources/logger.hpp>

namespace common
{
namespace logger
{

class log_sink_factory
{
public:
    static boost::shared_ptr<common::logger::log_sink> instance();
};

} // namespace logger
} // namespace common

#endif // !QXT_SRC_COMMON_LOGGER_LOG_SINK_FACTORY_HPP_
