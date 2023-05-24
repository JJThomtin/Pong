#include "Game.h"

bool Game::Init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		return false;
	}

	//Creates window with the size of 1270x800 pixels with the window title of PONG
	window = SDL_CreateWindow("PONG", 1270, 800, 0);

	//Check if window opened
	if (!window) {
		return false;
	}

	//Creates a 2D rendering context for a window with the 1st parameter being the window that is rendering
	//2nd parameter being the name of the rendering driver (it's NULL to initialize the first one supporting the flag
	//3rd parameter is the renderingflags
	renderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//check if there is a render
	if (!renderer) {
		return false;
	}

	return true;

}

void Game::GameLoop() {
	while (isRunning) {
		HandleEvents();
		Update();
		Draw();
	}
}

void Game::HandleEvents() {

}

void Game::Update() {

}

void Game::Draw() {
	//Set the color used for drawing operations (Rect, Line and Clear)
	SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
	//Clear the current rendering target with the drawing color.
	SDL_RenderClear(renderer);
	//Update the screen with any rendering performed since the previous call
	SDL_RenderPresent(renderer);

}

void Game::ShutDown() {

	//Destorys all objects
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}