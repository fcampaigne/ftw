/*
 * app.cpp
 *
 *  Created on: Aug 10, 2014
 *      Author: fred
 */

#include "App.h"

namespace ftw
{

App::App()
{
	init();
}

App::App(const App& x)
{
	tempHumidity = new TempHumidity();
}

App& App::operator = (const App& x)
{
	tempHumidity = new TempHumidity();
	return *this;
}

App::~App()
{
	delete tempHumidity;
}

void App::init()
{
	initLogging();
	BOOST_LOG_SEV(lg, info) << "logging initialized";
	tempHumidity = new TempHumidity();
}

void App::operator()()
{
	BOOST_LOG_SEV(ftw::lg, info) << "start of App thread";
	boost::thread* tempHumidity_t = new boost::thread(*tempHumidity);

	tempHumidity_t->join();
	delete tempHumidity_t;
	BOOST_LOG_SEV(ftw::lg, trace) << "end of App thread";
}
//-----------------------------------------------------------------------------
}
/* namespace ftw */

int main()
{
ftw::App* ftw = new ftw::App();
boost::thread* app_t = new boost::thread(*ftw);
//do the work
app_t->join();
delete ftw;
delete app_t;
BOOST_LOG_SEV(ftw::lg, trace)<< "end of main";

}
