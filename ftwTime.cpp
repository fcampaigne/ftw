/*
 * ftwTime.cpp
 *
 *  Created on: Aug 27, 2014
 *      Author: fred
 */

#include "ftwTime.h"
#include <cmath>

namespace ftw
{

double Time::MsgPrecision = std::log10(Time::MsgTimePoint::period::den);
double Time::HighResPrecision = std::log10(Time::HighResTimePoint::period::den);

}

