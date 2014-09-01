/*
 * ADC.h
 *
 *  Created on: Aug 12, 2014
 *      Author: fred
 */

#ifndef ADC_H_
#define ADC_H_

namespace ftw
{

class ADC
{
public:
	ADC();
	ADC(const ADC&);
	ADC& operator = (const ADC&);

	virtual ~ADC();

	void operator()();
};

} /* namespace ftw */

#endif /* ADC_H_ */
