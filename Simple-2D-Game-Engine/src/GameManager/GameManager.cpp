
#include "GameManager.h"
#include "../TextureManager/TextureManager.h"
#include "../TextManager/TextManager.h"
#include "../Entity/Entity.h"
#include "../Tilemap/Tilemap.h"
#include "../Input/InputHandler.h"
#include "../Input/Mouse.h"
#include "../Math/Vector/Float2.h"
#include "../ToolBox/ToolBox.h"
#include "../Math/NumberGenerator/Generator.h"

ToolBox tools;
SDL_Event GameManager::event;
InputHandler* input;
Mouse* mouse;

//Declare objects here

Entity *player;

GameManager::GameManager() {
	std::cout << "Initializing the window..." << std::endl;
}

GameManager::~GameManager() {
	IMG_Quit();
	TTF_Quit();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void GameManager::init(const char* title, int _width, int _height, bool fullscreen) {
	width = _width;
	height = _height;
	input = InputHandler::Instance();
	tools = ToolBox();
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialized" << std::endl;
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		if (!window) {
			std::cerr << "Window could not be created" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (!renderer) {
			std::cerr << "Renderer could not be created" << std::endl;
		}
		isRunning = true;
	} else {
		isRunning = false;
	}
	//enables the alpha channel
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	mouse = new Mouse();
	mouse->setCursor("assets/images/blueMouse.png");

	//Define objects here
	//cursor = SDL_CreateColorCursor(cursorImage, 0, 0);
	//SDL_SetCursor(cursor);


}

//Such as close, fullscreen and minimize window buttons etc
void GameManager::handleEvents() {
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_MOUSEBUTTONDOWN:
		mouse->down(event.button);
		break;
	case SDL_MOUSEBUTTONUP:
		//FIXME: doesnt do one click at a time, only multiple
		mouse->up();
	default:
		break;
	}
}
void GameManager::update() {
	input->Update();
	//Update stuff here

}


void GameManager::render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	//Render stuff here
	std::cout << mouse->left << mouse->right << mouse->middle << std::endl;


	SDL_RenderPresent(renderer);
}
void GameManager::clean() {
	input->Release();
	input = nullptr;

	//delete stuff here

}

bool GameManager::checkForKeyPress(SDL_Scancode scanCode) {
	return input->KeyDown(scanCode);
}
