/*
 * Time.h
 *
 *  Created on: Aug 24, 2014
 *      Author: fred
 */

#ifndef SNTIME_H_
#define SNTIME_H_

#include <ctime>
#include <ratio>
#include <chrono>

namespace sn_time
{

typedef typename std::chrono::system_clock MsgClock;
typedef typename std::chrono::system_clock::time_point MsgTimePoint;
MsgTimePoint getMsgTimePoint()
{
	return MsgClock::now();
}

typedef typename std::chrono::high_resolution_clock HighResClock;
typedef typename std::chrono::high_resolution_clock::time_point HighResTimePoint;
MsgTimePoint getHighResTimePoint()
{
	return HighResClock::now();
}

}

#endif /* TIME_H_ */
