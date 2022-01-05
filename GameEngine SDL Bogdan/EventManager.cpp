#include "EventManager.h"

bool EventManger::AddListener(EventType type, IEventHandler* listener)
{
	listeners[type].push_back(listener);
}

void EventManger::FireEvent(EventType type, Event* event)
{
	for (IEventHandler* handler : listeners[type])
	{
		handler->OnEvent(event);
	}
}
