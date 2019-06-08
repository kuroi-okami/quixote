#include <boost/shared_ptr.hpp>
#include <boost/move/make_unique.hpp>

#include "settings_json_factory.hpp"

#include <iostream>

int main()
{
    boost::movelib::unique_ptr<common::settings::settings_json_factory> settings_factory(
        boost::movelib::make_unique<common::settings::settings_json_factory>());

    boost::shared_ptr<common::settings::settings> settings_obj(
        settings_factory->create());

    boost::optional<boost::container::string> setting =
        settings_obj->get_settings(boost::container::string("logger.severity"));

    if(setting)
    {
        std::cout << setting.get() << std::endl;
    }

    return 0;
}