#pragma once

namespace Sonicteam{
	namespace Player{
		class INotification
		{
		public:
			INotification(void);

			virtual ~INotification(void);


			//for now
			virtual void OnNotificationSend(unsigned int) {};
			virtual void OnNotificationReceived(unsigned int) {};
		};
	}
}

