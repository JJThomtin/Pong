#include "Ball.h"
#include <iostream>
Ball::Ball() {
	//Ball speed
	ballSpeed = 2.f;
	xPos = (940 / 2) - (ballSize / 2);
	yPos = 330;

	xDirection = -1;
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




bool Ball::HasCollided(Paddle* paddle) {
	if (xPos + ballSize >= paddle->getPaddleXPos() && //Right ball intersect left paddle
		xPos <= paddle->getPaddleXPos() + paddle->PaddleGetRect()->w && //Right ball intersect right paddle
		yPos + ballSize >= paddle->getPaddleYPos() &&	//Bottom ball intersect top paddle
		yPos <= paddle->getPaddleYPos() + paddle->PaddleGetRect()->h) //Top ball intersect bottom baddle
	{
		xDirection *= -1.1;
		if (paddle->getPaddleID() == 0) {
			xPos = paddle->getPaddleXPos() + paddle->PaddleGetRect()->w;
		}
		else if (paddle->getPaddleID() == 1) {
			xPos = paddle->getPaddleXPos() - ballSize;
		}
		return true;
	}
	return false;
}
SDL_FRect* Ball::BallGetRect() {
	return &ballShapeAndLocation;
}