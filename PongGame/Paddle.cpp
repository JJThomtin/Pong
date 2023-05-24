#include "Paddle.h"

Paddle::Paddle(int i) {
	//Checks player 1 or 2 paddle
	id = i;
	//Speed of paddle
	speed = 20.f;

	//starting position of player 1 paddle
	if (id == 0) {
		x = 0;
		
	}
	//starting position of player 2 paddle
	else if (id == 1) {
		//positions it at the right side
		x = SCREEN_WIDTH + 300.f;
	}

	//positions it at the middle of the screen height
	y = (SCREEN_HEIGHT/2) + (height/2);

	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	
}
void Paddle::Update() {
	rect.x = x;
	rect.y = y;
}

SDL_FRect* Paddle::GetRect() {
	return &rect;
}