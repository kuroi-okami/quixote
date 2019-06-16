#include "settings_impl_json.hpp"
#include "settings_exception.hpp"

#include <boost/fusion/iterator/prior.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/container/vector.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/tokenizer.hpp>
#include <boost/filesystem.hpp>
#include <iostream>

common::settings::settings_impl::settings_impl() : settings_file_(default_settings_file)
{
    if(!boost::filesystem::exists(settings_file_))
    {
        throw settings_exception("File does not exist");
    }
}

common::settings::settings_impl::settings_impl(const boost::filesystem::path& settiings_file) : settings_file_(settiings_file)
{
    if(!boost::filesystem::exists(settings_file_))
    {
        throw settings_exception("File does not exist");
    }
}

const boost::optional<boost::container::string> common::settings::settings_impl::get_settings(const boost::container::string& key) const
{
    if (key == "")
    {
        throw settings_exception("Invalid JSON key");
    }
    boost::property_tree::ptree settings_ptree;

    boost::property_tree::read_json(settings_file_.string(), settings_ptree);
    //boost::property_tree::write_json(std::cout, settings_ptree);

    boost::char_separator<char> delimiter(".");
    boost::tokenizer<boost::char_separator<char> > tokens(key, delimiter);

    boost::container::vector<std::basic_string<char> > full_path_to_key;
    for (const auto& t : tokens)
    {
        //std::cout << t << std::endl;
        full_path_to_key.push_back(t);
    }

    boost::container::vector<std::basic_string<char> > path_to_key(
        full_path_to_key.begin(), boost::prior(full_path_to_key.end()));
    std::string catenated_path = boost::algorithm::join(path_to_key, ".");

    auto child_node = settings_ptree.get_child_optional(catenated_path);
    if(!child_node)
    {
        std::cout << "Unable to read settings - No children" << std::endl;
        return boost::none;
    }

    boost::optional<boost::container::string> value =
        child_node.get().get_optional<boost::container::string>(*boost::prior(full_path_to_key.end()));

    return value;
}

const boost::optional<boost::container::string> common::settings::settings_impl::get_settings_from_array(const boost::container::string& key, unsigned int array_index) const
{
    if (key == "")
    {
        throw settings_exception("Invalid JSON key");
    }
    boost::property_tree::ptree settings_ptree;

    boost::property_tree::read_json(settings_file_.string(), settings_ptree);
    //boost::property_tree::write_json(std::cout, settings_ptree);

    boost::char_separator<char> delimiter(".");
    boost::tokenizer<boost::char_separator<char> > tokens(key, delimiter);

    boost::container::vector<std::basic_string<char> > full_path_to_key;
    for (const auto& t : tokens)
    {
        std::cout << t << std::endl;
        full_path_to_key.push_back(t);
    }

    boost::container::vector<std::basic_string<char> > path_to_key(
        full_path_to_key.begin(), boost::prior(full_path_to_key.end()));
    std::string catenated_path = boost::algorithm::join(path_to_key, ".");

    auto child_node = settings_ptree.get_child_optional(catenated_path);
    if(!child_node)
    {
        std::cout << "Unable to read settings - No children" << std::endl;
        return boost::none;
    }

    boost::optional<boost::container::string> value = boost::none;
    unsigned int i = 0;
    for (const auto& array_node : child_node.get().get_child(""))
    {
        if (i == array_index)
        {
            value = array_node.second.get_optional<boost::container::string>(
                *boost::prior(full_path_to_key.end()));
        }
        i++;
    }
    return value;
}
