#ifndef QXT_SRC_COMMON_SETTINGS_SETTINGS_JSON_FACTORY_HPP_
#define QXT_SRC_COMMON_SETTINGS_SETTINGS_JSON_FACTORY_HPP_

#include <boost/move/unique_ptr.hpp>
#include "settings_impl_json.hpp"

namespace common
{
namespace settings
{

class settings_json_factory
{
public:
    const boost::shared_ptr<settings> create() const;
    const boost::shared_ptr<settings> create(const boost::filesystem::path& settings_file) const;
};

} // namespace settings
} // namespace common


#endif // !QXT_SRC_COMMON_SETTINGS_SETTINGS_JSON_FACTORY_HPP_
