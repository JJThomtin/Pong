#include "Game.h"

bool Game::Init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		return false;
	}

	//Creates window with the size of 640x480 pixels with the window title of PONG
	window = SDL_CreateWindow("PONG", 640, 480, 0);
	SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
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

	//Initialization of paddles

	leftPaddle = new Paddle(0);
	rightPaddle = new Paddle(1);

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

	//If the current event of the game is event_quit, the program will close the progrom
	//I.e(User clicks the close button on the window)
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_EVENT_QUIT) {
			isRunning = false;
		}
	}

	//SDL_GetKeyboardState is a pointer to an internal SDL array which checks for keyboard input
	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	//checks for escape input and if pressed(condition true) isRunning is false
	if (keystates[SDL_SCANCODE_ESCAPE]) {
		isRunning = false;
	}


}

void Game::Update() {

}

void Game::Draw() {
	//Set the color used for drawing operations (Rect, Line and Clear)
	SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
	//Clear the current rendering target with the drawing color.
	SDL_RenderClear(renderer);

	//Draw Paddles
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, leftPaddle->GetRect());
	SDL_RenderFillRect(renderer, rightPaddle->GetRect());
	//Update the screen with any rendering performed since the previous call
	SDL_RenderPresent(renderer);

}

void Game::ShutDown() {

	//Destorys all objects
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}