
#pragma once
#include "Event.h"
#include <vector>
#include <map>

class IEventHandler
{ 
public:
	virtual void OnEvent(Event* event);

	
};

typedef std::map<EventType, std::vector<IEventHandler*>> eventMap;

class EventManger
{
	eventMap listeners;
	
	bool AddListener(EventType type, IEventHandler* listener);
	void FireEvent(EventType type, Event* event);
};



