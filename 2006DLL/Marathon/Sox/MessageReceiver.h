#pragma once

namespace Sonicteam{
	namespace SoX{
		
		struct Message{
			unsigned int MessageInfo; // (just number)
			unsigned int MessageResult; // send message back  (here example 82206070)

		};
		class MessageReceiver
		{
		public:
			MessageReceiver(void);
			virtual ~MessageReceiver(void);
			virtual int OnMessageRecieved(Message*) = 0;
	


			
		};
	}
}
