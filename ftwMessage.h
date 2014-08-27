/*
 * message.h
 *
 *  Created on: Aug 14, 2014
 *      Author: fred
 */

#ifndef FTWMESSAGE_H_
#define FTWMESSAGE_H_

#include <memory>

#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

#include "Logging.h"
#include "ftwTime.h"

//snugglynoodles
namespace ftw
{

struct MsgType
{
	enum
	{
		unknown = -1, last = 0
	};
};

//Tmsg is intended to be a project specific int enum
template<typename TmsgType>
class Message
{
	typedef time::MsgTimePoint time_point;

public:
	Message() :
			msgType(MsgType::unknown), time(time::getMsgTimePoint())
	{
	}
	Message(TmsgType t) :
			msgType(t), time(time::getMsgTimePoint())
	{
	}

	Message(const Message& x) : msgType(x.msgType), time(x.time)
	{
	}

	Message& operator =(const Message& x)
	{
		msgType = x.msgType;
		time = x.time;
		return *this;
	}
	const TmsgType& getType() const
	{
		return msgType;
	}
	const time_point& getTime() const
	{
		return time;
	}
	double getSeconds() const
	{
		return ((double)(time.time_since_epoch().count()))/(double)time_point::period::den;
	}

private:
	TmsgType msgType;
	time_point time;
};
//
//Inter-thread message
//
template<typename TmsgType>
class ITMessage: public Message
{
public:
	template<typename Tobj>
	static ITMessage<TmsgType>* make_msg(TmsgType id, Tobj* x)
	{
		ITMessage* newMsg = new ITMessage(id);
		newMsg->setPtr(shared_ptr<void>(reinterpret_cast<void*>(x)));
		return newMsg;
	}

	template<typename Tobj>
	static Tobj get_payload(ITMessage<TmsgType>* msg)
	{

	}

	~ITMessage()
	{
		ptr.reset();
	}

private:
	ITMessage() :
			Message(), ptr(std::nullptr_t)
	{
	}
	ITMessage(TmsgType t) :
			Message(t), ptr(std::nullptr_t)
	{
	}
	ITMessage(const ITMessage& x) :
			Message(x)
	{
		ptr = x.ptr;
	}
	ITMessage& operator =(const ITMessage& x)
	{
		static_cast<Message&>(*this) = x;
		ptr = x.ptr;
		return *this;
	}
	void setPtr(std::shared_ptr<void>& x)
	{
		ptr = x;
	}
private:
	std::shared_ptr<void> ptr;
};
//
//Inter process message
//
template<typename TmsgType, typename Tchar>
class IPMessage: public Message
{
public:
	IPMessage() :
			Message<TmsgType>(MsgType::unknown), ptr(std::nullptr_t), length(0)
	{
	}
	virtual ~IPMessage<TmsgType, Tchar>()
	{
		ptr.reset();
	}

	virtual void read() = 0;
	virtual void write() = 0;

private:
	std::shared_ptr<Tchar> ptr;
	streamsize length;
};

} //end namespace

#endif /* FTWMESSAGE_H_ */
