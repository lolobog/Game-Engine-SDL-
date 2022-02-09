#pragma once
#include <map>
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

struct SampleData
{
	__int64 functionTime;
	int frameReference;
};




typedef std::map<const char*, std::vector<SampleData*>>FrameMap;

class ProfilerSystem
{
public:
	ProfilerSystem();
	~ProfilerSystem();

	void startFrame();
	void storeSample(const char* name, __int64 elapsedTime);
	void endFrame();

private:
	int currentFrame;
	FrameMap frameData;
};

extern ProfilerSystem g_profileManager;


struct Profile
{
	const char* _name;
	__int64 startTime;


	Profile(const char* name)
	{
		_name = name;
		__int64 li;
		std::clock();


	}
};

