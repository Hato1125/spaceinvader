#ifndef _SPACEINVADER_LOG_HPP
#define _SPACEINVADER_LOG_HPP

#include <boost/log/trivial.hpp>

#define LOG_TRACE(message) BOOST_LOG_TRIVIAL(trace)   << message
#define LOG_DEBUG(message) BOOST_LOG_TRIVIAL(debug)   << message
#define LOG_INFO(message)  BOOST_LOG_TRIVIAL(info)    << message
#define LOG_WARN(message)  BOOST_LOG_TRIVIAL(warning) << message
#define LOG_ERROR(message) BOOST_LOG_TRIVIAL(error)   << message
#define LOG_FATAL(message) BOOST_LOG_TRIVIAL(fatal)   << message

#endif
