#include "Ball.h"

Ball::Ball() {
	//Ball speed
	ballSpeed = 2.f;
	xPos = (940 / 2) - (ballSize / 2);
	yPos = 330;

	xDirection = 1;
	yDirection = 1;

	ballShapeAndLocation.x = (int)xPos;
	ballShapeAndLocation.y = (int)yPos;
	ballShapeAndLocation.w = ballSize;
	ballShapeAndLocation.h = ballSize;
}

void Ball::BallUpdate() {

	xPos = xPos + xDirection * ballSpeed;
	yPos = yPos + yDirection * ballSpeed;

	//Keep ball inbounds
	if (yPos < 0) {
		yPos = 0;
		yDirection *= -1;
	}
	else if (yPos + ballSize > 720) {
		yPos = 720 - ballSize;
		yDirection *= -1;
	}

	ballShapeAndLocation.x = xPos;
	ballShapeAndLocation.y = yPos;
}

void Ball::BallSetVelocity(float xDirection, float yDirection) {

}

SDL_FRect* Ball::BallGetRect() {
	return &ballShapeAndLocation;
}