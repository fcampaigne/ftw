/*
 * WatchDogTimer.cpp
 *
 *  Created on: Sep 1, 2014
 *      Author: fred
 */

#include <boost/bind.hpp>
#include <iostream>
#include <fstream>

#include "WatchDogTimer.h"
#include "Logging.h"

namespace ftw
{
//statics
std::string WatchDogTimer::watchdogFileName ="/dev/watchdog";
/*
void watchdogTimer(const boost::system::error_code& errorCode,
		boost::asio::deadline_timer* t)
{
	std::cout << "watchdog refresh errorCode: "<< errorCode << std::endl;;
	std::ofstream watchDogFile(WatchDogTimer::watchdogFileName, std::ios::out);
	watchDogFile << '\n' << endl;
	watchDogFile.close();
	t->expires_at(t->expires_at() + boost::posix_time::seconds(30));
	t->async_wait(boost::bind(watchdogTimer, boost::asio::placeholders::error, t));

	//BOOST_LOG_SEV(lg, debug)<< "watchdogTimer fired: " << boost::posix_time::microsec_clock::universal_time().time_of_day();
}
*/
WatchDogTimer::WatchDogTimer()
{
	// TODO Auto-generated constructor stub

}

WatchDogTimer::~WatchDogTimer()
{
	// TODO Auto-generated destructor stub
}
void WatchDogTimer::operator()()
{
	stop = false;
	while(!stop)
	{
		boost::asio::deadline_timer* t = new boost::asio::deadline_timer(ASIO::getIOService(),
				boost::posix_time::seconds(30));
		t->wait();

		std::ofstream watchDogFile(WatchDogTimer::watchdogFileName, std::ios::out);
		watchDogFile << '\n' << endl;
		watchDogFile.close();
		delete t;
		std::cout << "Watchdog refreshed" << std::endl;
		BOOST_LOG_SEV(lg, debug) << "Watchdog refreshed";
	}
	//ASIO::getIOService().run();

}

} /* namespace ftw */
