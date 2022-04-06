#pragma once
#include <vector>

/**
* Class for handling frame times
*/
class FrameTimer {


public:

	/**
* Queue containing all frame times
*/
	std::vector <float> FrameTimeQueue;
	/**
* Integer variable representing the old frame time
*/
	int OldTime = SDL_GetTicks();
	/**
* Integer variable representing the new frame time
*/
	int NewTime;
	/**
* Integer variable representing difference between the old time and new time
*/
	int delta;
	/**
* FrameTimeQueue maximum capacity
*/
	uint32_t capacity = 200;

	/**
* Pushes frame time into the queue
*/
	void Push(float FrameTime) {
		if (FrameTimeQueue.size() >= capacity)
		{
			//remove first
			FrameTimeQueue.erase(FrameTimeQueue.begin());
			//add new
			FrameTimeQueue.push_back(FrameTime);

		}
		else
		{
			FrameTimeQueue.push_back(FrameTime);
		}

	}

	/**
* Return the average frame time of the queue
*/
	float AverageTime()
	{
		float average = 0;
		for (int i = 0; i < FrameTimeQueue.size(); i++)
		{
			average += FrameTimeQueue[i];
		}

		return average / FrameTimeQueue.size();
	}

};