#include "Game.h"




int main(int argc, char* argv[])
{
	Game* game = new Game();
	Input* input = new Input();
	SceneManager sceneM;
	
	


	

	
	if (input)
	{
		Uint8 r = 127, g = 127, b = 127, a = 255;

		while (!input->KeyIsPressed(KEY_ESCAPE))
		{
			
			input->Update();
			if (sceneM.getInstance().currentScene != nullptr)
			{
				if (sceneM.getInstance().currentScene->Player != nullptr)
				{
					if (input->KeyIsPressed(KEY_W))
						sceneM.getInstance().currentScene->Player->setY(sceneM.getInstance().currentScene->Player->getPosition().y - 10);
					if (input->KeyIsPressed(KEY_S))
						sceneM.getInstance().currentScene->Player->setY(sceneM.getInstance().currentScene->Player->getPosition().y + 10);
					if (input->KeyIsPressed(KEY_A))
						sceneM.getInstance().currentScene->Player->setX(sceneM.getInstance().currentScene->Player->getPosition().x - 10);
					if (input->KeyIsPressed(KEY_D))
						sceneM.getInstance().currentScene->Player->setX(sceneM.getInstance().currentScene->Player->getPosition().x + 10);
				}
			}
			
				
					


			game->SetDisplayColour(r, g, b, a);
			game->Update();

		}

		delete input;
		input = nullptr;

		delete game;
		game = nullptr;
	}
	return 0;

}
