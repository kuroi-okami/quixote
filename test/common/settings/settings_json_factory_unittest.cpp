#include <boost/move/unique_ptr.hpp>
#include <boost/move/make_unique.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/filesystem/path.hpp>

#include <common/settings/settings_json_factory.hpp>
#include <common/settings/settings_impl_json.hpp>
#include <common/settings/settings_exception.hpp>

#include <gtest/gtest.h>

namespace common
{
namespace settings
{

class SettingsJsonFactory : public testing::Test
{
protected:
    boost::movelib::unique_ptr<common::settings::settings_json_factory> test_json_factory_;

    SettingsJsonFactory() :
        test_json_factory_(boost::movelib::make_unique<common::settings::settings_json_factory>())
    {};

};

TEST_F(SettingsJsonFactory, SettingsFactoryConstructorShouldNotThrow)
{
    EXPECT_NO_THROW(
        boost::movelib::make_unique<common::settings::settings_json_factory>());
}

TEST_F(SettingsJsonFactory, SettingsFactoryDefaultCreateShouldNotThrow)
{
    EXPECT_NO_THROW(
        test_json_factory_->create());
}

TEST_F(SettingsJsonFactory, SettingsFactoryOverloadedCreateShouldNotThrowWithValidFile)
{
    EXPECT_NO_THROW(
        test_json_factory_->create(common::settings::default_settings_file));
}

TEST_F(SettingsJsonFactory, SettingsFactoryOverloadedCreateShouldThrowWithInvalidFile)
{
    EXPECT_THROW(
        test_json_factory_->create(boost::filesystem::path("definitely/not/a/path.json")),
        common::settings::settings_exception);
}

}
}
