/*
 * app.cpp
 *
 *  Created on: Aug 10, 2014
 *      Author: fred
 */

#include "App.h"
#include "ASIO.h"

namespace ftw
{


App::App()
{
	init();
	adc = new ADC();
	wdt = new WatchDogTimer();
}

App::App(const App& x)
{
	adc = new ADC();
	wdt = new WatchDogTimer();//should be unique_ptr
}

App& App::operator = (const App& x)
{
	adc = new ADC();
	wdt = new WatchDogTimer();//should be unique_ptr
	return *this;
}

App::~App()
{
	delete adc;
	delete wdt;
}

void App::init()
{
	initLogging();
	BOOST_LOG_SEV(lg, info) << "logging initialized starting IO Services";
}
void App::startWatchdog()
{
}
//thread service run method
void App::operator()()
{
	BOOST_LOG_SEV(ftw::lg, info) << "start of App thread";
	//thread taken on stack...raii
	boost::thread wdt_th(*wdt);
	boost::thread adc_th(*adc);
	//wdt_th.join();
	BOOST_LOG_SEV(ftw::lg, trace) << "end of App thread";
	wdt_th.join();
	adc_th.join();
	std::cout << "join called" << std::endl;
}
//-----------------------------------------------------------------------------
}
/* namespace ftw */

int main()
{
ftw::App* ftw = new ftw::App();
boost::thread app_th(*ftw);

std::cout<< "starting watchdog" << std::endl;
//ftw::ASIO::getIOService().run();
//do the work
app_th.join();
delete ftw;
BOOST_LOG_SEV(ftw::lg, trace)<< "end of main";

}
