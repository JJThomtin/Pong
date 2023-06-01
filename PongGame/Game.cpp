#include "Game.h"
using Clock = std::chrono::steady_clock;
using namespace std::literals;
auto constexpr dt = 1.0s / 60.;
using duration = std::chrono::duration<double>;
using time_point = std::chrono::time_point<Clock, duration>;

bool Game::Init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		return false;
	}

	//Creates window with the size of 768x575 pixels with the window title of PONG
	window = SDL_CreateWindow("PONG", 640, 480, 0);
	SDL_SetWindowSize(window, 640, 480);
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

	//Initialization of Ball

	ball = new Ball;
	return true;

}

void Game::GameLoop() {
	time_point t{};

	time_point currentTime = Clock::now();
	duration accumulator = 0s;
	while (isRunning) {
		time_point newTime = Clock::now();
		auto frameTime = newTime - currentTime;
		if (frameTime > 0.25s)
			frameTime = 0.25s;
		currentTime = newTime;

		accumulator += frameTime;
		while (accumulator >= dt)
		{
			HandleEvents();
			Update();
			Draw();
			t += dt;
			accumulator -= dt;
		}
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

	//Left Paddle Movement
	//Stops left paddle when no button is pressed
	leftPaddle->PaddleSetDir(0);

	//Press W for the left paddle to go up
	if (keystates[SDL_SCANCODE_W]){
		leftPaddle->PaddleSetDir(-1);
	}
	//Press S for the left paddle to go down
	if (keystates[SDL_SCANCODE_S]) {
		leftPaddle->PaddleSetDir(1);
	}
	//Stops right paddle when no button is pressed
	rightPaddle->PaddleSetDir(0);


	//Press Up Arrow for the right paddle to go up
	if (keystates[SDL_SCANCODE_UP]) {
		rightPaddle->PaddleSetDir(-1);
	}
	//Press Down Arrow for the right paddle to go down
	if (keystates[SDL_SCANCODE_DOWN]) {
		rightPaddle->PaddleSetDir(1);
	}
}

void Game::Update() {
	leftPaddle->PaddleUpdate();
	rightPaddle->PaddleUpdate();
	ball->BallUpdate();

	//Ball hits left paddle 
	if (ball->HasCollided(leftPaddle)) {
		std::cout << "LEFT" << std::endl;
	}
	//Ball hits left paddle 
	if (ball->HasCollided(rightPaddle)) {
		std::cout << "RIGHT" << std::endl;
	}

}

void Game::Draw() {
	//Set the color used for drawing operations (Rect, Line and Clear)
	SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
	//Clear the current rendering target with the drawing color.
	SDL_RenderClear(renderer);

	//Draw Paddles
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, leftPaddle->PaddleGetRect());
	SDL_RenderFillRect(renderer, rightPaddle->PaddleGetRect());

	//Draw ball
	SDL_RenderFillRect(renderer, ball->BallGetRect());
	//Update the screen with any rendering performed since the previous call
	SDL_RenderPresent(renderer);

}

void Game::ShutDown() {

	//Destorys all objects
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}