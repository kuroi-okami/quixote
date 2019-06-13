#include "log_sink_impl.hpp"

// Singleton object of log_sink class
boost::shared_ptr<common::logger::log_sink_impl> common::logger::log_sink_impl::log_instance_;

boost::shared_ptr<common::logger::log_sink> common::logger::log_sink_impl::get_instance()
{
    if (!log_instance_)
    {
        // Can't use make_shared here... Ctor is private.
        log_instance_.reset(new log_sink_impl());
    }
    return log_instance_;
}

boost::shared_ptr<boost::log::sources::logger> common::logger::log_sink_impl::get_logger() const
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

    // Register the sink in the logging core
    boost::log::core::get()->add_sink(sink);

    logger_ =boost::make_shared<boost::log::sources::logger>();
}
