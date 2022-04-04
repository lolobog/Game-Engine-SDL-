#include "SceneManager.h"

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}

void SceneManager::AddScene(std::string sceneName,Scene* scene)
{
	if (gameScenes.count(sceneName) == 0)
	{
		if (currentScene == nullptr)
		{
			currentScene = scene;
		}
		gameScenes[sceneName].push_back(scene);
	}
	else
		cout << "A scene with the name: " + sceneName + "; already exists.(new scene will not be added)\n";
		
}

void SceneManager::UpdateScene()
{
	if (currentScene != nullptr)
	{
		currentScene->Update();
	}

}

void SceneManager::ChangeScene(std::string sceneName)
{
	if (gameScenes.count(sceneName)!=0)
	{
		if (currentScene != nullptr)
		{
			currentScene = gameScenes[sceneName][0];
		}
		else
			cout << "No current scene selected\n";
	}
	else
		cout << "Tried to change to invalid scene\n";
}


