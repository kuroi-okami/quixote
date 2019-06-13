#ifndef QXT_SRC_COMMON_LOGGER_LOG_EXCEPTION_HPP_
#define QXT_SRC_COMMON_LOGGER_LOG_EXCEPTION_HPP_

#include <stdexcept>

namespace common
{
namespace logger
{

class log_exception : public std::runtime_error
{
public:
    log_exception(const std::string message) :
        std::runtime_error(message)
    {
    }
    virtual ~log_exception() throw() {}
};

} // namespace settings
} // namespace common


#endif // !QXT_SRC_COMMON_LOGGER_LOG_EXCEPTION_HPP_