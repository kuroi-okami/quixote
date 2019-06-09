#include <boost/move/make_unique.hpp>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/optional/optional_io.hpp>

#include <common/settings/settings_json_factory.hpp>
#include <common/settings/settings_exception.hpp>
#include <gtest/gtest.h>

#include <iostream>

namespace common
{
namespace settings
{

static boost::container::string test_data_str(
    "{ \"test_array\": [{\"index_key1\":\"1\", \"index_key2\":\"1.2\",\"index_key3\":\"1.3\"}, {\"index_key1\":\"2\", \"index_key2\":\"2.2\",\"index_key3\":\"2.3\"}], \"test_entry\":\"3\", \"embedded_entry\":{\"test_entry\":\"4\"}}");

class SettingsJsonFactory : public testing::Test
{
protected:
    boost::filesystem::path test_file_;
    boost::movelib::unique_ptr<common::settings::settings_json_factory> test_json_factory_;
    boost::shared_ptr<common::settings::settings> test_json_parser_;

    SettingsJsonFactory() :
        test_file_(boost::filesystem::path("/tmp/test.json")),
        test_json_factory_(boost::movelib::make_unique<common::settings::settings_json_factory>())
    {
        boost::filesystem::ofstream test_file_stream(test_file_);
        test_file_stream << "";
        test_file_stream.close();
        test_json_parser_ = test_json_factory_->create(test_file_);
    };
    ~SettingsJsonFactory()
    {
        if (boost::filesystem::exists(test_file_))
        {
            try
            {
                boost::filesystem::remove(test_file_);
            }
            catch (boost::filesystem::filesystem_error &e)
            {
                std::cout << "couldn't remove test file - " << e.what() << std::endl;
            }
        }
    }
public:
    void write_test_file(boost::container::string const test_string);
};

void SettingsJsonFactory::write_test_file(boost::container::string const test_string)
{
    std::istringstream test_data(std::string(test_string.begin(),test_string.end()));
    boost::property_tree::ptree test_settings_ptree;

    boost::property_tree::read_json(test_data, test_settings_ptree);
    boost::property_tree::write_json(test_file_.string(), test_settings_ptree);
}

TEST_F(SettingsJsonFactory, ExpectSettingsCanBeObtainedFromEmbeddedJsonKey)
{
    boost::container::string test_key("embedded_entry.test_entry");
    SettingsJsonFactory::write_test_file(test_data_str);
    EXPECT_EQ(test_json_parser_->get_settings(test_key).get(), "4");
}

TEST_F(SettingsJsonFactory, ExpectSettingsCanBeObtainedFromTopLevelJsonKey)
{
    boost::container::string test_key("test_entry");
    SettingsJsonFactory::write_test_file(test_data_str);
    EXPECT_EQ(test_json_parser_->get_settings(test_key).get(), "3");
}

TEST_F(SettingsJsonFactory, ExpectSettingsCannotBeObtainedFromMissingKey)
{
    boost::container::string test_key("not_a_key");
    SettingsJsonFactory::write_test_file(test_data_str);
    EXPECT_EQ(test_json_parser_->get_settings(test_key), boost::none);
}

TEST_F(SettingsJsonFactory, ExpectSettingsCannotBeObtainedFromEmptyKey)
{
    boost::container::string test_key("");
    SettingsJsonFactory::write_test_file(test_data_str);
    EXPECT_THROW(test_json_parser_->get_settings(test_key),
        common::settings::settings_exception);
}

TEST_F(SettingsJsonFactory, ExpectSettingsCannotBeObtainedFromInvalidNode)
{
    boost::container::string test_key("not_a_node.imaginary_key");
    SettingsJsonFactory::write_test_file(test_data_str);
    EXPECT_EQ(test_json_parser_->get_settings(test_key), boost::none);
}

TEST_F(SettingsJsonFactory, ExpectSettingsCanBeObtainedFromArrayIndexZero)
{
    unsigned int array_index = 0;
    boost::container::string test_key("test_array.index_key1");
    SettingsJsonFactory::write_test_file(test_data_str);
    EXPECT_EQ(test_json_parser_->get_settings_from_array(test_key, array_index).get(), "1");
}

TEST_F(SettingsJsonFactory, ExpectSettingsCanBeObtainedFromArrayIndexNonZero)
{
    unsigned int array_index = 1;
    boost::container::string test_key("test_array.index_key1");
    SettingsJsonFactory::write_test_file(test_data_str);
    EXPECT_EQ(test_json_parser_->get_settings_from_array(test_key, array_index).get(), "2");
}

TEST_F(SettingsJsonFactory, ExpectSettingsCannotBeObtainedFromArrayIndexOutOfBounds)
{
    unsigned int array_index = 2;
    boost::container::string test_key("test_array.index_key1");
    SettingsJsonFactory::write_test_file(test_data_str);
    EXPECT_EQ(test_json_parser_->get_settings_from_array(test_key, array_index), boost::none);
}

TEST_F(SettingsJsonFactory, ExpectSettingsCannotBeObtainedFromArrayNotAnArray)
{
    unsigned int array_index = 1;
    boost::container::string test_key("not_a_test_array.index_key1");
    SettingsJsonFactory::write_test_file(test_data_str);
    EXPECT_EQ(test_json_parser_->get_settings_from_array(test_key, array_index), boost::none);
}

TEST_F(SettingsJsonFactory, ExpectSettingsCannotBeObtainedFromArrayNotAnArrayKey)
{
    unsigned int array_index = 1;
    boost::container::string test_key("test_array.not_an_index_key");
    SettingsJsonFactory::write_test_file(test_data_str);
    EXPECT_EQ(test_json_parser_->get_settings_from_array(test_key, array_index), boost::none);
}

}
}
