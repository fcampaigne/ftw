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
	tempHumidity = new TempHumidity();
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
}
//thread service run method
void App::operator()()
{
	BOOST_LOG_SEV(ftw::lg, info) << "start of App thread";
	//thread taken on stack...raii
	boost::thread tempHumidity_th(*tempHumidity);
	tempHumidity_th.join();
	BOOST_LOG_SEV(ftw::lg, trace) << "end of App thread";
}
//-----------------------------------------------------------------------------
}
/* namespace ftw */

int main()
{
ftw::App* ftw = new ftw::App();
boost::thread app_th(*ftw);
//do the work
app_th.join();
delete ftw;
BOOST_LOG_SEV(ftw::lg, trace)<< "end of main";

}
