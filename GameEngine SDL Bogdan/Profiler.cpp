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

}

void ProfilerSystem::storeSampleName(const char* name)
{
	
	sample->Name = name;

	if (frameData.size() > 0)
		frameData[0]->SubSample.push_back(sample);
	else
		frameData.push_back(sample);

	CurrentSample.push(sample);
}

void ProfilerSystem::storeSampleTime(__int64 elapsedTime)
{
	
	sample->frameReference = currentFrame;
	sample->functionTime = elapsedTime;
	



	/*SampleData* sample = new SampleData();
	sample->frameReference = currentFrame;
	sample->functionTime = elapsedTime;

	frameData[name].push_back(sample);*/


	
}
