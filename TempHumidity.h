/*
 * TempHumidity.h
 *
 *  Created on: Aug 12, 2014
 *      Author: fred
 */

#ifndef TEMPHUMIDITY_H_
#define TEMPHUMIDITY_H_

namespace ftw
{

class TempHumidity
{
public:
	TempHumidity();
	TempHumidity(const TempHumidity&);
	TempHumidity& operator = (const TempHumidity&);

	virtual ~TempHumidity();

	void operator()();
};

} /* namespace ftw */

#endif /* TEMPHUMIDITY_H_ */
