#include <SDL.h>
#include "Game.h"
#include <filesystem>




Game::Game()
{

	m_Window = nullptr;
	m_Renderer = nullptr;

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	m_Window = SDL_CreateWindow(
		"My First Window", //title
		1000, //initial x
		300,  //initial y
		screenWidth,  //width
		screenHeight, //height
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


	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		//success = false;
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
	g_profileManager.startFrame();
	{
		PROFILE("MAIN LOOP");

		m_timer.NewTime = SDL_GetTicks();
		m_timer.delta = m_timer.NewTime - m_timer.OldTime;

		{

			m_timer.Push(m_timer.delta);

		}



		CheckEvents();
		SDL_RenderClear(m_Renderer);

		ImGui::NewFrame();
		ImGui_ImplSDL2_NewFrame(m_Window);
		bool show = true;
		{
			PROFILE("SCENE UPDATE");
			scene->Update();

		}
		//ImGui::ShowDemoWindow(nullptr);
		{
			PROFILE("ASSETS GRABBING");
			count++;
			if (count % 120 == 0)
			{
				std::string AssetPath = "../GameEngine SDL Bogdan/assets";
				for (const auto& entry : std::filesystem::directory_iterator(AssetPath)) //directory_iterator(path) //recursive_
				{
					if (entry.path().extension() == ".bmp" || entry.path().extension() == ".jpg" || entry.path().extension() == ".png")
					{
						bool isInVector = false;
						for (auto bitmap : content)
						{
							if (bitmap->GetFilePath() == entry.path().string())
								isInVector = true;
						}
						if (isInVector == false)
						{
							Bitmap* Asset = new Bitmap(m_Renderer, entry.path().string(), true);
							content.push_back(Asset);
							numberOfImages++;
						}

					}
					else if (entry.is_directory())
					{
						std::cout << "dir " << entry.path() << std::endl;
					}
					//debug
					std::cout << entry.path() << std::endl;
				}

			}
			SDL_Delay(4);
		}
		{
			PROFILE("GO HIERARCHY");
			ImGui::Begin("GameObjects", 0, ImGuiWindowFlags_NoMove);
			ImGui::SetWindowPos({ 0,menuHeight });
			ImGui::SetWindowSize({ 150,screenHeight - menuHeight });

			ImGuiTreeNodeFlags nodeFlags = ImGuiTreeNodeFlags_FramePadding | ImGuiTreeNodeFlags_DefaultOpen;
			GameObject* Root = scene->GetRoot();
			bool isNodeOpen = ImGui::TreeNodeEx(Root->objectName.c_str(), nodeFlags);
			if (ImGui::BeginDragDropTarget())
			{
				if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("_TREENODE"))
				{
					GameObject* PayloadAsGameObject = static_cast<GameObject*>(I_GUI::EditorToShow);
					std::cout << PayloadAsGameObject->objectName << " on top of " << Root->objectName << std::endl;

					PayloadAsGameObject->SetParent(Root);
				}
				ImGui::EndDragDropTarget();
			}
			{
				PROFILE("OPENING NODE");
				if (isNodeOpen)
				{
					for (auto object : Root->children)
					{
						if (object->parent->objectName == "Root")
							//if(ImGui::TreeNodeEx(object->objectName.c_str(),nodeFlags))
							object->DrawChildGUI();
					}
					ImGui::TreePop();//poping root
				}
				
			}


			ImGui::End();



			if (ImGui::IsMouseReleased(ImGuiMouseButton_Left) && AssetMouseDrag != nullptr)
			{
				cout << "It is working?!" << endl;
				int x, y;
				SDL_GetMouseState(&x, &y);



				GameObject* obj = new GameObject(AssetMouseDrag->GetFileName(), m_Renderer, AssetMouseDrag, *scene->io, 100, 100, x, y, 0);
				scene->SceneObjects.push_back(obj);
				scene->GetRoot()->AddChild(obj);

				AssetMouseDrag = nullptr;
			}
			SDL_Delay(4);
		}

		{ PROFILE("CONTENT WINDOW");

			ImGui::Begin("Content Window");

			for (int i = 0; i < content.size(); i++)
			{
				ImGui::PushID(i);

				ImGui::ImageButton((ImTextureID)content[i]->GetTexture(), { 100,100 });



				if (ImGui::BeginDragDropSource())
				{
					AssetMouseDrag = content[i];
					ImGui::Image((ImTextureID)content[i]->GetTexture(), { 100,100 });
					ImGui::EndDragDropSource();
				}
				ImGui::PopID();
				if (i % 4 != 3)
					ImGui::SameLine();


			}
			SDL_Delay(4);
			ImGui::End();


		}

		{
			PROFILE("PROFILER WINDOW");
			//Profiler Window
			ImGui::Begin("Profiler");

			ImGui::PlotLines("Frames", m_timer.FrameTimeQueue.data(), m_timer.capacity);
			char buffer[64];
			snprintf(buffer, sizeof(buffer), "Average Frame Time %f ms", m_timer.AverageTime());
			ImGui::Text(buffer);

			ImGui::End();


			SDL_Delay(4);

		}


		//Flame Graph
		
		ImGui::Begin("Flame Graph");

		vector<Sample*> Snapshot;
		vector<float>* FrameTimes=0;
		


		if (ImGui::Button("Take snapshot"))
		{
			Snapshot = g_profileManager.GetFrameData();
			for (auto profile : Snapshot)
			{
				FrameTimes->push_back(profile->functionTime);
				for (auto subProfile : profile->SubSample)
					FrameTimes->push_back(subProfile->functionTime);
			}
		}
		int selectedFrame = Snapshot.size();
		ImGui::SameLine();

		bool LiveFlameGraph = true;
		ImGui::Checkbox("Live Flame Graph", &LiveFlameGraph);
		if (LiveFlameGraph)
		{
			selectedFrame = -1;
		}

		int range[2] = { 0,100 };
		if (FrameTimes && FrameTimes->size() > 100)
		{
			ImGui::SliderInt2("Frame Range", range, 0, FrameTimes->size());
			if (range[0] >= range[1])
			{
				range[0] = range[1] - 1;
			}

			vector<float>subData(FrameTimes->cbegin() + range[0], FrameTimes->cbegin() + range[1]);

			int tempHitSelection = ImGui::MyPlotHistogram("Frame data", subData.data(), subData.size());
			if (tempHitSelection != -1)
			{
				LiveFlameGraph = false;
				selectedFrame = tempHitSelection;
			}

			ImRect rect = { ImGui::GetItemRectMin(),ImGui::GetItemRectMax() };
			if (rect.Contains(scene->io->MousePos))
			{
				if (ImGui::IsMouseClicked(ImGui::IsMouseClicked(ImGuiMouseButton_Left)))
				{
					cout << selectedFrame << endl;
				}
			}

		}

		Sample* previousFrame = g_profileManager.GetFrameData().back();

		if (!LiveFlameGraph && selectedFrame != -1)
		{
			
		}





		ImGui::End();
		





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
		m_timer.OldTime = m_timer.NewTime;

		g_profileManager.endFrame();
		SDL_Delay(16);
	}
	
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






