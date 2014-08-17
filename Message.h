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

namespace fcmessage
{

struct MsgType
{
	enum
	{
		unknown = -1, last = 0
	};
};

//Tmsg is intended to be a project specific int enum
template<typename Tmsg>
class Message
{
public:
	Message()
	{
		msgType = MsgType::unknown;
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
	Tmsg getType() const
	{
		return msgType;
	}
private:
	Tmsg msgType;
};
//
//Inter-thread message
//
template<typename Tmsg>
class ITMessage: public Message
{
public:
	template<typename Tobj>
	static ITMessage<Tmsg>* make_msg(Tmsg id, Tobj* x)
	{
		ITMessage* newMsg = new ITMessage(id);
		newMsg->setPtr(shared_ptr<void>(reinterpret_cast<void*>(x)));
		return newMsg;
	}

	template<typename Tobj>
	static Tobj get_payload(ITMessage<Tmsg>* msg)
	{

	}

	~ITMessage()
	{
		ptr.reset();
	}
private:
	ITMessage(MsgType t = MsgType::unknown) :
			Message(t), ptr(nullptr_t)
	{
	}
	ITMessage() :
			Message(MsgType::unknown), ptr(nullptr_t)
	{
	}
	ITMessage(const ITMessage& x)
	{
		static_cast<Message>(*this) = static_cast<Message>(x);
		ptr = x.ptr;
	}
	ITMessage& operator =(const ITMessage& x)
	{
		static_cast<Message>(*this) = static_cast<Message>(x);
		ptr = x.ptr;
		return *this;
	}
	void setPtr(std::shared_ptr<void>& x)
	{
		ptr = x;
	}
private:
	shared_ptr<void> ptr;
};
//
//Inter process message
//
template<typename Tmsg, typename Tchar>
class IPMessage: public Message
{
public:
	IPMessage() :
			Message<Tmsg>(MsgType::unknown), ptr(nullptr_t), length(0)
	{
	}
	virtual ~IPMessage<Tmsg, Tchar>()
	{
	}

	virtual void read() = 0;
	virtual void write() = 0;

private:
	shared_ptr<Tchar> ptr;
	streamsize length;
};

} //end namespace

#endif /* MESSAGE_H_ */
