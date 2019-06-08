#ifndef QXT_SRC_COMMON_SETTINGS_SETTINGS_EXCEPTION_HPP_
#define QXT_SRC_COMMON_SETTINGS_SETTINGS_EXCEPTION_HPP_

#include <stdexcept>

namespace common
{
namespace settings
{

class settings_exception : public std::runtime_error
{
public:
    settings_exception(const std::string message) :
        std::runtime_error(message)
    {
    }
    virtual ~settings_exception() throw() {}
};

} // namespace settings
} // namespace common


#endif
