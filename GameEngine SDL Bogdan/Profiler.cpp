#include "Profiler.h"

ProfilerSystem::ProfilerSystem()
{
}

ProfilerSystem::~ProfilerSystem()
{
}

void ProfilerSystem::startFrame()
{
	currentFrame++;
}

void ProfilerSystem::endFrame()
{
	isMainLoopIn = false;
}



void ProfilerSystem::storeSampleName(const char* name)
{
	Sample* sample = new Sample();
	sample->Name = name;

	if (isMainLoopIn==true)
		CurrentSample.top()->SubSample.push_back(sample);
	else
	{
		frameData.push_back(sample);
		isMainLoopIn = true;
	}
	numberOfProfiles++;
	CurrentSample.push(sample);
}

void ProfilerSystem::storeSampleTime(__int64 elapsedTime)
{
	Sample* sample = CurrentSample.top();

	
	sample->functionTime = elapsedTime;
	
	
	CurrentSample.pop();	
}
