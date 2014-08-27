/*
 * Time.h
 *
 *  Created on: Aug 24, 2014
 *      Author: fred
 */

#ifndef FTWTIME_H_
#define FTWTIME_H_

#include <ctime>
#include <ratio>
#include <chrono>

namespace ftw
{

class Time
{
public:
	typedef typename std::chrono::system_clock MsgClock;
	typedef typename std::chrono::system_clock::time_point MsgTimePoint;

	static MsgTimePoint getMsgTimePoint()
	{
		return MsgClock::now();
	}
	static double getMsgSeconds()
	{
		return (double)(MsgClock::now().time_since_epoch().count())/(double)Time::MsgTimePoint::period::den;
	}

	static double MsgPrecision;

	typedef typename std::chrono::high_resolution_clock HighResClock;
	typedef typename std::chrono::high_resolution_clock::time_point HighResTimePoint;

	static MsgTimePoint getHighResTimePoint()
	{
		return HighResClock::now();
	}
	static double getHighResSeconds()
	{
		return (double)(HighResClock::now().time_since_epoch().count())/(double)Time::HighResTimePoint::period::den;
	}
	static double HighResPrecision;
};

}

#endif /* FTWTIME_H_ */
