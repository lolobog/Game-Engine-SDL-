#include <SDL.h>
#include "Game.h"



Game::Game()
{

	m_Window = nullptr;
	m_Renderer = nullptr;

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	m_Window = SDL_CreateWindow(
		"My First Window", //title
		250, //initial x
		50,  //initial y
		640,  //width
		480, //height
		0  //window behaviour flags


	);

	if (!m_Window)
	{
		printf("WINDOW initialisation failed: %s/n");
		printf("Press any key to continue/n");
		getchar();
		return;
	}

	m_Renderer = SDL_CreateRenderer(
		m_Window,
		-1,
		0
	);

	if (!m_Renderer)
	{
		printf("WINDOW initialisation failed: %s/n");
		printf("Press any key to continue/n");
		getchar();
		return;
	}

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	SDL_DisplayMode DisplayMode;
	SDL_GetCurrentDisplayMode(0, &DisplayMode);
	ImGuiSDL::Initialize(m_Renderer, DisplayMode.w, DisplayMode.h);
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

	ImGui::StyleColorsDark();

	ImGui_ImplSDL2_InitForOpenGL(m_Window, SDL_GL_CreateContext(m_Window));

	





 m_pSmallFont = TTF_OpenFont("Assets/DejaVuSans.ttf", 15);
 m_pBigFont = TTF_OpenFont("Assets/DejaVuSans.ttf", 50);


	scene = new Scene(m_Renderer,io);


}///

void Game::SetDisplayColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{

		if (m_Renderer)
		{
			int result = SDL_SetRenderDrawColor(
				m_Renderer,
				r,
				g,
				b,
				a

			);



		}

	}
Game::~Game() 
{
	

	TTF_CloseFont(m_pBigFont);
	TTF_CloseFont(m_pSmallFont);
	
}

void Game::Update(void)
{
	CheckEvents();
	SDL_RenderClear(m_Renderer);

	ImGui::NewFrame();
	ImGui_ImplSDL2_NewFrame(m_Window);
	bool show = true;
	scene->Update();
	//ImGui::ShowDemoWindow(nullptr);

	//ImGui::Begin("WINDOW NAME");

	////.x
	//float x = 1.0f;

	////ImGui::InputFloat("X", scene->LayerObjects[playerEnemy][1]->getTransform()->getXAddr(), 0.1f, 1.0f, "%.3f");

	////ImGui::InputFloat("Y", scene->LayerObjects[playerEnemy][1]->getTransform()->getYAddr(), 0.1f, 1.0f, "%.3f");
	//
	//ImGui::End();

	ImGui::Render();
	ImGuiSDL::Render(ImGui::GetDrawData());
	
	

	
	


	/*UpdateText("Small Red", 50, 10, m_pSmallFont, { 255,0,0 });
	UpdateText("Small Red", 50, 40, m_pSmallFont, { 0,0,255 });

	char char_array[] = "Big White";
	UpdateText(char_array, 50, 140, m_pBigFont, { 255,255,255 });

	string myString = "Big Green";
	UpdateText(myString, 50, 70, m_pBigFont, { 0,255,0 });

	int testNumber = 1234;
	string testString = "Test Number: ";
	testString += to_string(testNumber);
	UpdateText(testString, 50, 210, m_pBigFont, { 255,255,255 });*/


	SDL_RenderPresent(m_Renderer);

	SDL_Delay(16);
}

void Game::UpdateText(string msg, int x, int y, TTF_Font* font, SDL_Color colour)
{
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;

	int texW = 0;
	int texH = 0;


	surface = TTF_RenderText_Solid(font, msg.c_str(), colour);
	if (!surface)
	{
		printf("Surface for font not loaded \n");
		printf("%s\n", SDL_GetError());

	}
	else
	{
		texture = SDL_CreateTextureFromSurface(m_Renderer, surface);
		if (!texture)
		{
			printf("Texture for font not loaded\n");
			printf("%s\n", SDL_GetError());
		}
		else
		{
			SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
			SDL_Rect textRect = { x,y,texW,texH };

			SDL_RenderCopy(m_Renderer, texture, NULL, &textRect);
		}
	}
	
	if (texture)
		SDL_DestroyTexture(texture);
	if (surface)
		SDL_FreeSurface(surface);
		
}




