#include "MenuScene.h"
#include "SceneManager.h"

MenuScene::MenuScene(SDL_Renderer* renderer, ImGuiIO& _io)
{
	io = &_io;
	m_rednerere = renderer;

	Root = new GameObject("Root", renderer, _io, 0, 0, 0, 0, 0);
	SceneObjects.push_back(Root);

	

}

MenuScene::~MenuScene()
{
}

void MenuScene::Update()
{
	SceneManager sceneMan;
	
	ImVec2 buttonSize = ImVec2(700, 300);

	
	
	

	ImGui::Begin("Main Menu Window",0,1|2|4|8|16|32|128);
	
	ImGui::SetWindowFontScale(10);
		if (ImGui::Button("Play", buttonSize))
		{
			
			sceneMan.getInstance().ChangeScene("Game");
		}
		if (ImGui::Button("Quit", buttonSize))
		{
			SDL_Quit();
			exit(0);
		}
		
	ImGui::End();
	
}
