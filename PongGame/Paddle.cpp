#include "Paddle.h"

Paddle::Paddle(int i) {
	//Checks player 1 or 2 paddle
	paddleID = i;
	//Speed of paddle
	paddleSpeed = 20.f;

	//starting position of player 1 paddle
	if (paddleID == 0) {
		paddleXPos = 0;
		
	}
	//starting position of player 2 paddle
	else if (paddleID == 1) {
		//positions it at the right side
		paddleXPos = 640 + 300.f;
	}

	//positions it at the middle of the screen height
	paddleYPos = (480/2) + (paddleHeight/2);

	paddleShape.x = paddleXPos;
	paddleShape.y = paddleYPos;
	paddleShape.w = paddleWidth;
	paddleShape.h = paddleHeight;

	
}
void Paddle::PaddleUpdate() {
	paddleYPos = paddleYPos + paddleSpeed * paddleDirection;

	// Keep y inbounds
	if (paddleYPos < 0) {
		paddleYPos = 0;
	}
	else if (paddleYPos > 620) {
		paddleYPos = 620;
	}
	paddleShape.y = paddleYPos;

}

void Paddle::PaddleSetDir(int d){
	paddleDirection = d;
}

SDL_FRect* Paddle::PaddleGetRect() {
	return &paddleShape;
}
