#include "Player.h"
#include <SDL.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <SDL_image.h>


Player::Player() : GameObject() {

}

Player::~Player() {

}

void Player::Initialize() {
/*	srand(time(NULL));
	
	_transform.position.x = ((float(rand()) / float(RAND_MAX)) * (640 - -640)) + -640;

	srand(time(NULL));
	_transform.position.y = ((float(rand()) / float(RAND_MAX)) * (640 - -640)) + -640;

	 _transform.rotation.x = 30.0f; _transform.rotation.y = 0.0f; _transform.rotation.z = 10.0f;
	*/
	rice = 222;
	_transform.position.x = 100.0f;
	_transform.position.y = 100.0f;
	_transform.rotation.x = 30.0f;
	_transform.rotation.y = 0.0f;
	_transform.rotation.z = 10.0f;
//	IMG_Init(IMG_INIT_PNG);						//initalizes the kind of image we will use
	
}

void Player::Update(float dt) {

}

void Player::Draw(SDL_Renderer *renderer, float dt) {
/*	_avatar = IMG_LoadTexture(renderer, "./banana.png");		//loads the image

	  int w, h, winW, winH;
	SDL_QueryTexture(_avatar, NULL, NULL, &w, &h);
	

	SDL_Rect r;
	r.h = h; r.w = w; r.x = 200; r.y = 200;
	
	SDL_RenderCopy(renderer, _avatar, NULL, &r);
*/	
	_transform.rotation.z += _transform.rotation.z >= 360.0f ? -360.0f : 0;		//well, cant have more than 360 degrees, right?
	_transform.position.x += _transform.position.x >= 640 ? -640 : (_transform.position.x <= 0 ? 640 : 0);
	_transform.position.y += _transform.position.y >= 640 ? -640 : (_transform.position.y <= 0 ? 640 : 0);

	//magical stuff (aka math) takes place, so we can rotate, like the woooooooorld
	float rotationRadians = MathUtils::ToRadians(_transform.rotation.z);

	Vector2 rotatedOffset = {
		_transform.rotation.x * cosf(rotationRadians) + _transform.rotation.y * sinf(rotationRadians),
		_transform.rotation.x * sinf(rotationRadians) - _transform.rotation.y * cosf(rotationRadians)
	};
	Vector2 transformedEndPoint = {_transform.position.x + rotatedOffset.x, _transform.position.y + rotatedOffset.y };
	
	SDL_RenderDrawLine(renderer,
		_transform.position.x,
		_transform.position.y,
		transformedEndPoint.x,
		transformedEndPoint.y);

}