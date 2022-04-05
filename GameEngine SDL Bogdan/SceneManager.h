#include "Scene.h"



typedef std::map<std::string, std::vector<Scene*>> scenesMap;

class SceneManager
{
public:
	Scene* currentScene=nullptr;
	scenesMap gameScenes;
	bool showGUI = false;
	SceneManager();
	~SceneManager();
	void AddScene(std::string sceneName,Scene* scene);
	void UpdateScene();
	void ChangeScene(std::string sceneName);
	static SceneManager& getInstance()
	{
		static SceneManager    instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}

};


