#include "WinScene.h"
#include "SceneManager.h"

WinScene::WinScene(SDL_Renderer* renderer, ImGuiIO& _io)
{
	io = &_io;
	m_rednerere = renderer;
}

WinScene::~WinScene()
{
}

void WinScene::Update()
{
	SceneManager sceneMan;

	ImVec2 buttonSize = ImVec2(700, 300);





	ImGui::Begin("Win Screen Window", 0, 1 | 2 | 4 | 8 | 16 | 32 | 128);

	ImGui::SetWindowFontScale(10);
	if (ImGui::Button("Play Again?", buttonSize))
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
