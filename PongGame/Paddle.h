#pragma once

#include "Utils.h"

class Paddle
{
public:
	Paddle(int i);
	void Update();

	SDL_FRect* GetRect();
private:
	int id;
	int dir = 0;
	int width = 20;
	int height = 100;
	float x = 0, y, speed;
	SDL_FRect rect;

};

