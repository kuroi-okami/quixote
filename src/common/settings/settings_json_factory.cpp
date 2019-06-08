#include <boost/make_shared.hpp>

#include "settings_json_factory.hpp"

const boost::shared_ptr<common::settings::settings> common::settings::settings_json_factory::create() const
{
    return boost::make_shared<common::settings::settings_impl>();
}

const boost::shared_ptr<common::settings::settings> common::settings::settings_json_factory::create(const boost::filesystem::path& settings_file) const
{
    return boost::make_shared<common::settings::settings_impl>(settings_file);

}