#ifndef QXT_SRC_COMMON_LOGGER_LOG_SINK_IMPL_HPP_
#define QXT_SRC_COMMON_LOGGER_LOG_SINK_IMPL_HPP_

#include "log_sink.hpp"
#include "severity.hpp"

#include <boost/shared_ptr.hpp>
#include <boost/log/sources/severity_logger.hpp>

namespace common
{
namespace logger
{

class log_sink_impl : public log_sink
{
public:
    static boost::shared_ptr<common::logger::log_sink> get_instance();
    boost::shared_ptr<
        boost::log::sources::severity_logger< log_severity >> get_logger() const;

private:
    log_sink_impl();

    boost::shared_ptr<boost::log::sources::severity_logger< log_severity >> logger_;
    static boost::shared_ptr<log_sink_impl> log_instance_;
};

} // namespace logger
} // namespace common

#endif // !QXT_SRC_COMMON_LOGGER_LOG_SINK_IMPL_HPP_
