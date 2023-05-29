#pragma once

#include <SDL3/SDL.h>

struct Velecity {

};
class Ball
{
public:
	Ball();

	void BallUpdate();
	void BallSetVelocity(float xDirection, float yDirection);

	SDL_FRect* BallGetRect();
private:
	int ballSize = 20;
	float xPos, yPos, xDirection, yDirection, ballSpeed;

	SDL_FRect ballShapeAndLocation;
};

