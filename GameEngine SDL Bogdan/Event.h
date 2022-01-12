#pragma once

enum EventType
{
	Event_Object_Collected,
	Event_Object_Destroyed,
	Event_Object_Explosion,
	Event_Player_Seen,


};

struct Variant
{
	enum Type
	{
		TYPE_INTEGER,
		TYPE_FLOAT,
		TYPE_BOOL,
		TYPE_STRING_ID,
		TYPE_COUNT
	};

	Type type;

	union 
	{
		int asInteger;
		float asFloat;
		bool asBool;
		unsigned long asStringId;

	};
};




class Event
{
	
public:
	EventType type;
	
	
};

class ExplosionEvent : public Event
{
	Variant Position;
	
};

class CollectionEvent : public Event
{
	Variant Position;
	Variant AmmountCollected;
};

