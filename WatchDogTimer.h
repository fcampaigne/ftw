/*
 * WatchDogTimer.h
 *
 *  Created on: Sep 1, 2014
 *      Author: fred
 */

#ifndef WATCHDOGTIMER_H_
#define WATCHDOGTIMER_H_


#include <string>
#include "ASIO.h"

namespace ftw
{

void watchdogTimer(const boost::system::error_code& /*e*/,
		boost::asio::deadline_timer* t);


class WatchDogTimer
{
public://types
	typedef boost::asio::deadline_timer deadline_timer_type;
	volatile bool stop;

public: //data
	static std::string watchdogFileName;


public:
	WatchDogTimer();
	static const char* getWatchdogFileName(){return watchdogFileName.data();}

	virtual ~WatchDogTimer();
	void operator()();

//private://data
	//deadline_timer_type* watchDog;//should be unique_ptr
};

} /* namespace ftw */

#endif /* WATCHDOGTIMER_H_ */
