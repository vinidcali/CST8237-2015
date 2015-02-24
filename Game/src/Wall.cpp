#include "Wall.h"
#include <SDL.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <SDL_image.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds


Wall::Wall() : GameObject() {

}

Wall::~Wall() {

}

void Wall::Initialize(SDL_Renderer *renderer) {
	wallW = 100;
	wallH = 100;

	//this way, when creating multiple walls, because there's the sleep time,
	//the walls won't be in the same place, at least this is the way I got it to work D:
//	srand(time(NULL));
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	_transform.position.x = float(rand()) / (float(RAND_MAX / 900));
	_transform.position.y = float(rand()) / (float(RAND_MAX / 600));
	
	IMG_Init(IMG_INIT_PNG);						//initalizes the kind of image we will use
	_wall = IMG_LoadTexture(renderer, "./etemon.png");			//loads the image
}

void Wall::Update(float dt) {

}

void Wall::Draw(SDL_Renderer *renderer, float dt) {
	wallRect.h = wallH; wallRect.w = wallW; wallRect.x = _transform.position.x; wallRect.y = _transform.position.y;

	SDL_RenderCopy(renderer, _wall, NULL, &wallRect);
}
