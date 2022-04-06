#include "Scene.h"



typedef std::map<std::string, std::vector<Scene*>> scenesMap;

class SceneManager
{
public:
	/**
* The current scene selected by the Scene Manager
*/
	Scene* currentScene=nullptr;
	/**
* Map containing all the scenes and their respective names
*/
	scenesMap gameScenes;
	/**
* Boolean variable that controls the appearence/dissapearence of the Editor
*/
	bool showGUI = false;
	/**
* Default class constructor for Scene Manager
*/
	SceneManager();
	/**
* Default class destructor for Scene Manager
*/
	~SceneManager();
	/**
* Add a new scene to the scenes map along with its respective name
*/
	void AddScene(std::string sceneName,Scene* scene);
	/**
* Update the current scene
*/
	void UpdateScene();
	/**
* Change the  current scene to a new scene with the respective name
*/
	void ChangeScene(std::string sceneName);
	/**
* Create an instance of the class which is accessible anywhere in the project through the function
*/
	static SceneManager& getInstance()
	{
		static SceneManager    instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}

};


