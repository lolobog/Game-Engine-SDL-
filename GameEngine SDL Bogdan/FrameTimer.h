#pragma once
#include <vector>

class FrameTimer {


public:


	std::vector <float> FrameTimeQueue;

	int OldTime = SDL_GetTicks();
	int NewTime;
	int delta;
	
	uint32_t capacity = 200;

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