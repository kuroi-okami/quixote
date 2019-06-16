#include "log_sink_impl.hpp"
#include "severity.hpp"

#include <boost/log/sinks/basic_sink_frontend.hpp>
#include <boost/log/expressions/attr.hpp>
#include <boost/log/expressions/formatter.hpp>
#include <boost/log/utility/value_ref.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared_object.hpp>
#include <boost/phoenix/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sources/basic_logger.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/attributes/scoped_attribute.hpp>
#include <boost/log/utility/value_ref.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/move/make_unique.hpp>

#include <common/settings/settings_json_factory.hpp>

// Singleton object of log_sink class
boost::shared_ptr<common::logger::log_sink_impl> common::logger::log_sink_impl::log_instance_;

BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", log_severity)
BOOST_LOG_ATTRIBUTE_KEYWORD(file, "File", std::string)
BOOST_LOG_ATTRIBUTE_KEYWORD(function, "Function", std::string)
BOOST_LOG_ATTRIBUTE_KEYWORD(line, "Line", int)

boost::shared_ptr<common::logger::log_sink> common::logger::log_sink_impl::get_instance()
{
    if (!log_instance_)
    {
        // Can't use make_shared here... Ctor is private.
        log_instance_.reset(new log_sink_impl());
    }
    return log_instance_;
}

boost::shared_ptr<
    boost::log::sources::severity_logger< log_severity >> 
        common::logger::log_sink_impl::get_logger() const
{
    return logger_;
}

common::logger::log_sink_impl::log_sink_impl()
{
    typedef boost::log::sinks::synchronous_sink<
        boost::log::sinks::text_ostream_backend> text_sink;

    boost::shared_ptr< text_sink > sink =
        boost::make_shared<text_sink>();

    // FIXME - Needs to add DDMMYYHHSS
    sink->locked_backend()->add_stream(
        boost::make_shared< std::ofstream >("QXT.log"));

    BOOST_AUTO(settings_factory, 
        boost::movelib::make_unique<common::settings::settings_json_factory>());
    const char* logger_default = "5";
    sink->set_filter(
        severity <= static_cast<log_severity>(boost::lexical_cast<int>(
            settings_factory->create()->get_settings("logger.severity").
                get_value_or(logger_default))));
    
    sink->set_formatter(
        boost::log::expressions::stream 
            << boost::posix_time::second_clock::local_time() << ": "
            << file << ":" << line
            << " " << function << " - "
            << "[" << severity << "] "
            << boost::log::expressions::smessage);

    // Register the sink in the logging core
    boost::log::core::get()->add_sink(sink);

    logger_ = boost::make_shared<
        boost::log::sources::severity_logger< log_severity >>();
}
