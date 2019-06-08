#include "settings.hpp"
#include "settings_impl.hpp"

#include <iostream>

int main()
{
    common::settings::settings* settings_obj =
        new common::settings::settings_impl();

    boost::optional<boost::container::string> setting =
        settings_obj->get_settings(boost::container::string("logger.severity"));

    if(setting)
    {
        std::cout << setting.get() << std::endl;
    }

    return 0;
}