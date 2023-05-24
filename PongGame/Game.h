#pragma once

#include "Paddle.h"
class Game {
public:
	//The INIT function initializes the data structures required by the rest of
	//the computation of the aggregate
	bool Init();
	//The gameloop is a sequence of processes that run continuously as long as the game is running
	void GameLoop();
	//Flushes all the data when the app closes
	void ShutDown();
private:
	//Set up current events
	void HandleEvents();
	//changes events
	void Update();
	//creates image
	void Draw();

	//checks if app is running
	bool isRunning = true;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	class Paddle* leftPaddle,  *rightPaddle;
};

