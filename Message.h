/*
 * message.h
 *
 *  Created on: Aug 14, 2014
 *      Author: fred
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include "Logging.h"
#include <memory>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

//snugglynoodles
namespace sn_message
{

struct MsgType
{
	enum
	{
		unknown = -1, last = 0
	};
};

//Tmsg is intended to be a project specific int enum
template<typename TmsgType, typename TtimeType>
class Message
{
public:
	Message()
	{
		msgType = MsgType::unknown;
		time = 0;
		double* x = new double(0.0);
	}
	Message(const Message& x)
	{
		msgType = x.msgType;
	}
	Message& operator =(const Message& x)
	{
		msgType = x.msgType;
		return *this;
	}
	~Message()
	{
	}
	const TmsgType& getType() const
	{
		return msgType;
	}
	const TtimeType& getTime()const
	{
		return time;
	}
private:
	TmsgType msgType;
	TtimeType time;
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
	ITMessage(MsgType t = MsgType::unknown) :
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
		static_cast<Message&>(*this) = static_cast<Message&>(x);
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

#endif /* MESSAGE_H_ */
