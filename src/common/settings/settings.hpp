#ifndef QXT_SRC_COMMON_SETTINGS_SETTINGS_HPP_
#define QXT_SRC_COMMON_SETTINGS_SETTINGS_HPP_

#include <boost/filesystem/path.hpp>
#include <boost/container/string.hpp>
#include <boost/optional.hpp>

namespace common
{
namespace settings
{

class settings
{
public:
    virtual const boost::optional<boost::container::string> get_settings(const boost::container::string& key) const = 0;
    virtual const boost::optional<boost::container::string> get_settings_from_array(const boost::container::string& key, unsigned int array_index) const = 0;
};

} // namespace settings
} // namespace common
#endif //!QXT_SRC_COMMON_SETTINGS_SETTINGS_HPP_
