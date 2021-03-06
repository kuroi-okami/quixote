#ifndef QXT_SRC_COMMON_SETTINGS_SETTINGS_IMPL_JSON_HPP_
#define QXT_SRC_COMMON_SETTINGS_SETTINGS_IMPL_JSON_HPP_

#include <boost/filesystem/path.hpp>
#include <boost/container/string.hpp>

#include "settings.hpp"

namespace common
{
namespace settings
{

static const boost::filesystem::path default_settings_file("/src/quixote/external/settings/settings.json");

class settings_impl : public settings
{
public:
    settings_impl();
    settings_impl(const boost::filesystem::path& settings_file);

    const boost::optional<boost::container::string> get_settings(const boost::container::string& key) const;
    const boost::optional<boost::container::string> get_settings_from_array(const boost::container::string& key, unsigned int array_index) const;

private:
    const boost::filesystem::path settings_file_;
};

} // namespace settings
} // namespace common

#endif // !QXT_SRC_COMMON_SETTINGS_SETTINGS_IMPL_JSON_HPP_