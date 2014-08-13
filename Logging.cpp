/*
 * Logging.cpp

 *
 *  Created on: Aug 12, 2014
 *      Author: fred
 */

#include <string>
#include "Logging.h"

namespace ftw
{
//free defs
string fl(const string file, int line)
{
	return string("{" + file + ":" + boost::lexical_cast<string>(line) + "}:");
}
void initLogging()
{
	logging::add_file_log(keywords::file_name = "../../log/ftw_%N.log", /*< file name pattern >*/
	keywords::rotation_size = 10 * 1024 * 1024, /*< rotate files every 10 MiB... >*/
			keywords::time_based_rotation = sinks::file::rotation_at_time_point(
					0, 0, 0), /*< ...or at midnight >*/
			keywords::format = "[%TimeStamp% %ThreadID%]:%Message%" /*< log record format >*/
			);

	logging::core::get()->set_filter(
			logging::trivial::severity >= logging::trivial::info);

	logging::add_common_attributes();
}
}//namespace
