#pragma once
#include <map>
#include <vector>
#include <iostream>
#include <ctime>
#include <string>
#include <stack>

using namespace std;

struct SampleData
{
	__int64 functionTime;
	int frameReference;
};

class Sample
{
public:
	string Name;
	vector<Sample*>SubSample;
	__int64 functionTime;
	

};




typedef std::map<const char*, std::vector<SampleData*>>FrameMap;

class ProfilerSystem
{
public:
	ProfilerSystem();
	~ProfilerSystem();

	void startFrame();
	void storeSampleTime(__int64 elapsedTime);
	void storeSampleName(const char* name);
	vector<Sample*> GetFrameData() { return frameData; }
	void endFrame();

private:
	int currentFrame = 0;;
	bool isMainLoopIn = false;
	//FrameMap frameData;
	vector <Sample*> frameData;
	vector <float> frameTimes;
	std::stack<Sample*> CurrentSample;
	

	
};

static  ProfilerSystem g_profileManager;


struct Profile
{
	const char* _name;
	std::clock_t startTime;
	std::clock_t endTime;
	
	Profile(const char* name)
	{
		_name = name;
		startTime = std::clock();
		
		g_profileManager.storeSampleName(name);
		//cout << "Stored: " << name << endl;

	}
	~Profile()
	{
		endTime = std::clock();
		__int64 elapsedTime = 1000 * (endTime - startTime) / CLOCKS_PER_SEC; //Elapsed time in milliseconds
		g_profileManager.storeSampleTime(elapsedTime);
		
	}
};
#define PROFILE(name)Profile p(name)


