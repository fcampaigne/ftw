/*
 * app.h
 *
 *  Created on: Aug 10, 2014
 *      Author: fred
 */

#ifndef APP_H_
#define APP_H_

#include <unistd.h>
#include <string>
#include <memory>
//date time
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/thread/thread.hpp"
#include "ASIO.h"
//threads
#include "Logging.h"
#include "ADC.h"
#include "WatchDogTimer.h"

namespace ftw
{


class App
{

public:
	//methods
	App();
	App(const App&);
	App& operator =(const App&);
	void startWatchdog();
	virtual ~App();

	//thread service run method
	void operator()();

private:
	//methods
	void init();

private://data couldn't get shared_ptr to work with eclipse
	ADC* adc;
	WatchDogTimer* wdt;
};

} /* namespace ftw */

#endif /* APP_H_ */
