#include "WinScene.h"
#include "SceneManager.h"

WinScene::WinScene(SDL_Renderer* renderer, ImGuiIO& _io)
{
	io = &_io;
	m_rednerere = renderer;

	Root = new GameObject("Root", renderer, _io, 0, 0, 0, 0, 0);
	SceneObjects.push_back(Root);
}

WinScene::~WinScene()
{
}

void WinScene::Update()
{
	SceneManager sceneMan;

	ImVec2 buttonSize = ImVec2(700, 300);





	ImGui::Begin("Win Screen Window", 0, 1 | 2 | 4 | 8 | 16 | 32 | 128| ImGuiWindowFlags_NoDocking);

	ImGui::SetWindowFontScale(10);
	if (ImGui::Button("Play Again?", buttonSize))
	{
		Mix_HaltMusic();
		Mix_PlayMusic(audioManager.getInstance().gameMusic, -1); 
		Mix_PlayChannel(-1, audioManager.getInstance().buttonClick, 0);
		sceneMan.getInstance().ChangeScene("Game");
	}
	if (ImGui::Button("Quit", buttonSize))
	{
		Mix_HaltMusic();
		Mix_PlayChannel(-1, audioManager.getInstance().buttonClick, 0);
		audioManager.getInstance().Close();
		SDL_Quit();
		exit(0);
	}

	ImGui::End();

	for (auto object : SceneObjects)
	{
		if (object->objectName != "Root")
		{

			object->UpdateGUI(*io);
			object->Update();
		}


	}


	if (I_GUI::EditorToShow)
		if (sceneMan.getInstance().showGUI == true)
			I_GUI::EditorToShow->DrawGUI();

}
