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
		x = 640 + 300.f;
	}

	//positions it at the middle of the screen height
	y = (480/2) + (height/2);

	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	
}
void Paddle::Update() {
	y = y + speed * dir;

	// Keep y inbounds
	if (y < 0) {
		y = 0;
	}
	else if (y > 620) {
		y = 620;
	}
	rect.y = y;

}

void Paddle::SetDir(int d){
	dir = d;
}

SDL_FRect* Paddle::GetRect() {
	return &rect;
}
