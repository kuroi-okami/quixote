#include "log_sink.hpp"
#include "log_sink_impl.hpp"
#include "log_sink_factory.hpp"

boost::shared_ptr<common::logger::log_sink> common::logger::log_sink_factory::instance()
{
    return common::logger::log_sink_impl::get_instance();
}