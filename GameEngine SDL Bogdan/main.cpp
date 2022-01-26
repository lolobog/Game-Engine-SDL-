#include "Game.h"




int main(int argc, char* argv[])
{
	Game* game = new Game();
	Input* input = new Input();
	
	
	


	

	
	if (input)
	{
		Uint8 r = 127, g = 127, b = 127, a = 255;

		while (!input->KeyIsPressed(KEY_ESCAPE))
		{
			input->Update();
			if (input->KeyIsPressed(KEY_W))
				game->scene->Player->setY(game->scene->Player->getPosition().y - 10);
			if (input->KeyIsPressed(KEY_S))
				game->scene->Player->setY(game->scene->Player->getPosition().y + 10);
			if (input->KeyIsPressed(KEY_A))
				game->scene->Player->setX(game->scene->Player->getPosition().x - 10);
			if (input->KeyIsPressed(KEY_D))
				game->scene->Player->setX(game->scene->Player->getPosition().x + 10);

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
