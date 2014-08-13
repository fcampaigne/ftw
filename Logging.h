/*
 * Logging.h
 *
 *  Created on: Aug 12, 2014
 *      Author: fred
 */

#ifndef LOGGING_H_
#define LOGGING_H_

//logging
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

//namespace management
using namespace std;
namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;
using namespace logging::trivial;

namespace ftw
{
//free functions
void initLogging();
string fl(const std::string file, int line);
//logging
static src::severity_logger<severity_level> lg;

}//namespace


#endif /* LOGGING_H_ */
