#pragma once

#include "Paddle.h"

struct Velecity {

};
class Ball
{
public:
	Ball();

	void BallUpdate();
	void BallSetVelocity(float xDirection, float yDirection);
	void BallHitPaddle();
	bool HasCollided(Paddle* paddle);
	float getXPos() {
		return xPos;
	}

	float getYPos() {
		return yPos;
	}

	float getXDirection() {
		return xDirection;
	}

	float getYDirection() {
		return yDirection;
	}

	SDL_FRect* BallGetRect();
private:
	int ballSize = 20;
	float xPos, yPos, xDirection, yDirection, ballSpeed;

	SDL_FRect ballShapeAndLocation;
};

