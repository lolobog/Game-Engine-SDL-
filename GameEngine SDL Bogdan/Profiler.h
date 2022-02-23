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
private:
	int profiles = 0;
public:
	string Name;
	vector<Sample*>SubSample;
	__int64 functionTime;
	
	
	void CopyInfo(Sample* sample)
	{
		
		this->Name = sample->Name;
		this->functionTime = sample->functionTime;
		this->SubSample = sample->SubSample;
	}

	int GetNumberOfProfiles()
	{
		int count = 0;
			for (auto sample : SubSample)
			{
				count+=1+sample->GetNumberOfProfiles();
			}
		
		
		return count;
	}

	void PushProfiles(vector<Sample*> Snapshot)
	{
		Snapshot.push_back(this);
		for (auto sample : this->SubSample)
		{
			sample->PushProfiles(Snapshot);
		}
	}


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
	int currentFrame = 0;
	bool isMainLoopIn = false;
	int numberOfProfiles = 0;
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


