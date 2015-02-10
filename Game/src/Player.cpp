#include "Player.h"
#include <SDL.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <SDL_image.h>
#include <stdio.h>


Player::Player() : GameObject() {

}

Player::~Player() {

}

void Player::Initialize(SDL_Renderer *renderer) {
	speed = 600;
	rotationSpeed = 50000;
	avatarW = 50;
	avatarH = 50;
	
	srand(time(NULL));
	
	_transform.position.x = ((float(rand()) / float(RAND_MAX)) * (640 - -640)) + -640;
	_transform.position.y = ((float(rand()) / float(RAND_MAX)) * (640 - -640)) + -640;

	 _transform.rotation.x = avatarW/2; _transform.rotation.y = avatarH/2; _transform.rotation.z = 10.0f;
	
	 face.x = _transform.position.x + avatarW/2; 
	face.y = _transform.position.y;

	IMG_Init(IMG_INIT_PNG);						//initalizes the kind of image we will use
	_avatar = IMG_LoadTexture(renderer, "./banana.png");		//loads the image
	
}

void Player::Update(float dt) {

}

void Player::Draw(SDL_Renderer *renderer, float dt) {

	
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

	SDL_Rect r;
	r.h = avatarH; r.w = avatarW; r.x = _transform.position.x; r.y = _transform.position.y;
//	r.h = avatarH; r.w = avatarW; r.x = transformedEndPoint.x; r.y = transformedEndPoint.y;
	
	SDL_Point center;
	center.x = r.w / 2;
	center.y = r.h / 2;

	//SDL_RenderCopy(renderer, _avatar, NULL, &r);
	SDL_RenderCopyEx(renderer, _avatar, NULL, &r, rotationRadians, &center, SDL_FLIP_NONE);

//	face.x = _transform.position.x + avatarW/2; 
//	face.y = _transform.position.y;
	face.x = rotatedOffset.x;
	face.y = rotatedOffset.y;

}


void Player::move(float dt, SDL_Keycode key) {
	printf("X: %f, Y: %f\n", _transform.position.x, _transform.position.y);
	printf("fX: %d, fY: %d\n", face.x, face.y);
//	int x = fmod(_transform.position.x, avatarW);
//	int y = fmod(_transform.position.y, avatarH);

	switch(key) {
		case SDLK_LEFT: case SDLK_a:
			_transform.rotation.z += (rotationSpeed * dt);
			printf("hello?");
			break;
		case SDLK_RIGHT: case SDLK_d:
			_transform.rotation.z -= (rotationSpeed * dt);
			break;
		case SDLK_UP: case SDLK_w:
	/*		if (y < avatarH/2 && x < avatarW/2) {
				_transform.position.x -= (speed * dt);
				_transform.position.y -= (speed * dt);
			} else if (y < avatarH/2 && x == avatarW/2) {
				_transform.position.y -= (speed * dt);
			} else if (y < avatarH/2 && x > avatarW/2) {
				_transform.position.x += (speed * dt);
				_transform.position.y -= (speed * dt);
			} else if (y == avatarH/2 && x > avatarW/2) {
				_transform.position.x += (speed * dt);
			} else if (y > avatarH/2 && x > avatarW/2) {
				_transform.position.x += (speed * dt);
				_transform.position.y += (speed * dt);
			} else if (y > avatarH/2 && x == avatarW/2) {
				_transform.position.y += (speed * dt);
			} else if (y > avatarH/2 && x < avatarW/2) {
				_transform.position.x -= (speed * dt);
				_transform.position.y += (speed * dt);
			} else if (y == avatarH/2 && x < avatarW/2) {
				_transform.position.x -= (speed * dt);
			}
	*/	
			_transform.position.y -= (speed * dt);
			break;
		case SDLK_DOWN: case SDLK_s:
			_transform.position.y += (speed * dt);
			break;
	}
}