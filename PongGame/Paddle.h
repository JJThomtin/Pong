#pragma once

#include <SDL3/SDL.h>

class Paddle
{
public:
	Paddle(int i);
	void PaddleUpdate();
	void PaddleSetDir(int d);

	SDL_FRect* PaddleGetRect();

	float getPaddleXPos() {
		return paddleXPos;
	}

	float getPaddleYPos() {
		return paddleYPos;
	}

	int getPaddleID() {
		return paddleID;
	}
private:
	int paddleID;
	int paddleDirection = 0;
	int paddleWidth = 20;
	int paddleHeight = 100;
	float paddleXPos = 0, paddleYPos, paddleSpeed;
	SDL_FRect paddleShape;

};

