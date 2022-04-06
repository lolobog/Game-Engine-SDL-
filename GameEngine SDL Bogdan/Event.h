#pragma once
/**
* Enumeration representing all the event types
*/
enum EventType
{
	Event_Object_Collected,
	Event_Object_Destroyed,
	Event_Object_Explosion,
	Event_Player_Seen,


};
/**
* Structure that represents the information about an event
*/
struct Variant
{
	/**
* Enumeration representing all the information types
*/
	enum Type
	{
		TYPE_INTEGER,
		TYPE_FLOAT,
		TYPE_BOOL,
		TYPE_STRING_ID,
		TYPE_COUNT
	};
	/**
* Variable representing the type of variant
*/
	Type type;
	/**
* Storing the information as the desired type
*/
	union 
	{
		int asInteger;
		float asFloat;
		bool asBool;
		unsigned long asStringId;

	};
};



/**
* Base Event class from which all further events will inherit
*/
class Event
{
	
public:
	EventType type;
	
	
};
/**
* Event to be triggered upon an explosion
*/
class ExplosionEvent : public Event
{
	Variant Position;
	
};
/**
* Event to be triggered upon a collection
*/
class CollectionEvent : public Event
{
	Variant Position;
	Variant AmmountCollected;
};

