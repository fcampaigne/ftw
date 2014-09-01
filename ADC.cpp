/*
 * ADC.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: fred
 */

#include "ADC.h"
#include <boost/thread/thread.hpp>
#include "Logging.h"

namespace ftw
{

ADC::ADC()
{
	BOOST_LOG_SEV(ftw::lg, trace) << "start of ADC ctor";

	BOOST_LOG_SEV(ftw::lg, trace) << "end of ADC ctor";
}
ADC::ADC(const ADC&)
{
	BOOST_LOG_SEV(ftw::lg, trace) << "start of ADC copy ctor";

	BOOST_LOG_SEV(ftw::lg, trace) << "end of ADC copy ctor";
}
ADC& ADC::operator = (const ADC&)
{
	BOOST_LOG_SEV(ftw::lg, trace) << "start of ADC =";
	return *this;
}

ADC::~ADC()
{
	// TODO Auto-generated destructor stub
}

void ADC::operator()()
{
	BOOST_LOG_SEV(ftw::lg, info) << "start of ADC thread";
	//boost::this_thread::sleep_for( boost::chrono::seconds(5) );
	BOOST_LOG_SEV(ftw::lg, trace) << "end of ADC thread";
}

} /* namespace ftw */
