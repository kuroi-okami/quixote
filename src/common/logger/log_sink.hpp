#ifndef QXT_SRC_COMMON_LOGGER_LOG_SINK_HPP_
#define QXT_SRC_COMMON_LOGGER_LOG_SINK_HPP_

#include <fstream>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/smart_ptr/make_shared_object.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace common
{
namespace logger
{

class log_sink
{
public:
    virtual boost::shared_ptr<boost::log::sources::logger> get_logger() const = 0;
    virtual ~log_sink() {}
};

} // namespace logger
} // namespace common
#endif // !QXT_SRC_COMMON_LOGGER_LOG_SINK_HPP_
