/*
 * ASIO.h
 *
 *  Created on: Aug 31, 2014
 *      Author: fred
 */

#ifndef ASIO_H_
#define ASIO_H_

#include <boost/asio.hpp>

namespace ftw
{

class ASIO
{
public:
	ASIO();
	virtual ~ASIO();

	static boost::asio::io_service& getIOService()
	{
		return io;
	}

private:
	static boost::asio::io_service io;
};

} /* namespace ftw */

#endif /* ASIO_H_ */
