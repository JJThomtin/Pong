#include "Ball.h"

Ball::Ball() {
	//Ball speed
	ballSpeed = 10.f;
	xPos = (940 / 2) - (ballSize / 2);
	yPos = 330;

	xDirection = 1;
	yDirection = -1;

	ballShapeAndLocation.x = (int)xPos;
	ballShapeAndLocation.y = (int)yPos;
	ballShapeAndLocation.w = ballSize;
	ballShapeAndLocation.h = ballSize;
}

void Ball::BallUpdate() {
	ballShapeAndLocation.x = xPos;
	ballShapeAndLocation.y = yPos;
}

void Ball::BallSetVelocity(float xDirection, float yDirection) {

}

SDL_FRect* Ball::BallGetRect() {
	return &ballShapeAndLocation;
}