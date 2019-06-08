#include "settings_impl.hpp"

#include <boost/fusion/iterator/prior.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/container/vector.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/tokenizer.hpp>
#include <iostream>

common::settings::settings_impl::settings_impl() : settings_file_(default_settings_file)
{
    std::cout
        << "Initalising settings with settings_file: "
        << default_settings_file.c_str()
        << std::endl;
}

common::settings::settings_impl::settings_impl(const boost::filesystem::path& settiings_file) : settings_file_(settiings_file)
{
    std::cout
        << "Initalising settings with settings_file: "
        << settiings_file.c_str()
        << std::endl;
}

const boost::optional<boost::container::string> common::settings::settings_impl::get_settings(const boost::container::string& key) const
{
    boost::property_tree::ptree settings_ptree;

    boost::property_tree::read_json(settings_file_.string(), settings_ptree);
    boost::property_tree::write_json(std::cout, settings_ptree);

    boost::char_separator<char> delimiter(".");
    boost::tokenizer<boost::char_separator<char> > tokens(key, delimiter);

    boost::container::vector<std::basic_string<char> > full_path_to_key;
    for (const auto& t : tokens)
    {
        full_path_to_key.push_back(t);
    }

    boost::container::vector<std::basic_string<char> > path_to_key(
        full_path_to_key.begin(), boost::prior(full_path_to_key.end()));
    std::string catenated_path = boost::algorithm::join(path_to_key, ".");

    auto child_node = settings_ptree.get_child_optional(catenated_path);
    if(!child_node)
    {
        return boost::none;
    }

    boost::optional<boost::container::string> value =
        child_node.get().get_optional<boost::container::string>(*boost::prior(full_path_to_key.end()));

    return value;
}