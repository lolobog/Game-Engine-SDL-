
#pragma once
#include "Event.h"
#include <vector>
#include <map>

/**
* Class for handling the events
*/
class IEventHandler
{ 
public:
	/**
* Function that is activated once an event is triggered
*/
	virtual void OnEvent(Event* event);

	
};

typedef std::map<EventType, std::vector<IEventHandler*>> eventMap;
/**
* Class for Managing Events
*/
class EventManger
{
public:
	/**
* Map containing all the IEventHandler objects listening for events, along with the type of the event
*/
	eventMap listeners;
	/**
* Add IEventHandler type object to the listeners map along with their event type
*/
	bool AddListener(EventType type, IEventHandler* listener);
	/**
* Triggers the OnEvent function of the IEventHandler type objects listening for the event with the respective type
*/
	void FireEvent(EventType type, Event* event);
};



