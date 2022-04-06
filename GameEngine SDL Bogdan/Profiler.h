#pragma once
#include <map>
#include <vector>
#include <iostream>
#include <ctime>
#include <string>
#include <stack>

using namespace std;
/**
* Structure that holds how long the function took and the number of the frame
*/
struct SampleData
{
	__int64 functionTime;
	int frameReference;
};

class Sample
{
private:

public:
	/**
* Name of the sample
*/
	string Name;
	/**
* Vector to store all the sub samples of a sample
*/
	vector<Sample*>SubSample;
	/**
* Time that the function took
*/
	__int64 functionTime;
	
	/**
* Copy the information from one sample to another
*/
	void CopyInfo(Sample* sample)
	{
		
		this->Name = sample->Name;
		this->functionTime = sample->functionTime;
		this->SubSample = sample->SubSample;
	}

	/**
* Returns the number of sample(including the children)
*/
	int GetNumberOfSamples()
	{
		int count = 0;
			for (auto sample : SubSample)
			{
				count+=1+sample->GetNumberOfSamples();
			}
		
		
		return count;
	}
	/**
* Add the new profiles to the vector of sub profiles
*/
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
	/**
* Mark the beginning of a new frame for the profiler to analyze
*/
	void startFrame();
	/**
* Store the time of a profile in the Stack
*/
	void storeSampleTime(__int64 elapsedTime);
	/**
* Store the name of a profile in the Stack
*/
	void storeSampleName(const char* name);
	/**
* Returns a reference to a map holding all the profiles
*/
	vector<Sample*> GetFrameData() { return frameData; }
	/**
* Mark the end of a new frame for the profiler to analyze
*/
	void endFrame();
	
	
private:
	/**
* Integer representing the number of the profiles to analyze
*/
	int numberOfProfiles = 0;
	/**
* Integer representing the number of the frame the application is on
*/
	int currentFrame = 0;
	/**
* Boolean to make sure the Main profile goes in first
*/
	bool isMainLoopIn = false;
	/**
* Vector containing all the profiles
*/
	vector <Sample*> frameData;
	/**
* Vector containing all the frame times
*/
	vector <float> frameTimes;
	/**
* Stack whose top is always the stack we are currently on
*/
	std::stack<Sample*> CurrentSample;
	
	
};
/**
* Global Profile 
* 
*/
static  ProfilerSystem g_profileManager;


struct Profile
{
	/**
* Name of the profile
*/
	const char* _name;
	/**
* Start time of the profile
*/
	std::clock_t startTime;
	/**
* End time of the profile
*/
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


