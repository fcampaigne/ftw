/*
 * TempHumidity.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: fred
 */

#include "TempHumidity.h"
#include <boost/thread/thread.hpp>
#include "Logging.h"

namespace ftw
{

TempHumidity::TempHumidity()
{
	BOOST_LOG_SEV(ftw::lg, trace) << "start of TempHumidity ctor";

	BOOST_LOG_SEV(ftw::lg, trace) << "end of TempHumidity ctor";
}
TempHumidity::TempHumidity(const TempHumidity&)
{
	BOOST_LOG_SEV(ftw::lg, trace) << "start of TempHumidity copy ctor";

	BOOST_LOG_SEV(ftw::lg, trace) << "end of TempHumidity copy ctor";
}
TempHumidity& TempHumidity::operator = (const TempHumidity&)
{
	BOOST_LOG_SEV(ftw::lg, trace) << "start of TempHumidity =";
	return *this;
}

TempHumidity::~TempHumidity()
{
	// TODO Auto-generated destructor stub
}

void TempHumidity::operator()()
{
	BOOST_LOG_SEV(ftw::lg, info) << "start of TempHumidity thread";
	//boost::this_thread::sleep_for( boost::chrono::seconds(5) );
	BOOST_LOG_SEV(ftw::lg, trace) << "end of TempHumidity thread";
}

} /* namespace ftw */
