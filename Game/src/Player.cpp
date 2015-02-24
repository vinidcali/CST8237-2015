#include "Player.h"
#include <SDL.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <SDL_image.h>
#include <stdio.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds



Player::Player() : GameObject() {

}

Player::~Player() {

}

void Player::Initialize(SDL_Renderer *renderer) {
	speed = 600;
	rotationSpeed = 2000;
	avatarW = 50;
	avatarH = 50;
	points = 0;
	

	//this way, when creating two players, because there's the sleep time,
	//the players won't be in the same place, because there's a palpable time difference between one random and the other
	srand(unsigned (time(NULL)));
	std::this_thread::sleep_for(std::chrono::seconds(1));

	int r = rand();

	_transform.position.x = float(rand()) / (float(RAND_MAX / 900));
	_transform.position.y = float(rand()) / (float(RAND_MAX / 600));

	 _transform.rotation.x = avatarW/2; _transform.rotation.y = 0;
	 _transform.rotation.z = float(rand()) / (float(RAND_MAX / 360));;
	
	face.x = _transform.position.x + avatarW/2; 
	face.y = _transform.position.y;

	IMG_Init(IMG_INIT_PNG);						//initalizes the kind of image we will use
	_avatar = IMG_LoadTexture(renderer, "./banana.png");		//loads the image
	
}

void Player::Update(float dt) {

}

void Player::Draw(SDL_Renderer *renderer, float dt) {
	_transform.rotation.z += _transform.rotation.z >= 360.0f ? -360.0f : 0;		//well, cant have more than 360 degrees, right?
	_transform.position.x += _transform.position.x >= 900 ? -900 : (_transform.position.x <= 0 ? 900 : 0);
	_transform.position.y += _transform.position.y >= 600 ? -600 : (_transform.position.y <= 0 ? 600 : 0);

	//magical stuff (aka math) takes place, so we can rotate, like the woooooooorld
	float rotationRadians = MathUtils::ToRadians(_transform.rotation.z);

	Vector2 rotatedOffset = {
		_transform.rotation.x * cosf(rotationRadians) + _transform.rotation.y * sinf(rotationRadians),
		_transform.rotation.x * sinf(rotationRadians) - _transform.rotation.y * cosf(rotationRadians)
	};
	Vector2 transformedEndPoint = {_transform.position.x + rotatedOffset.x, _transform.position.y + rotatedOffset.y };

	avatarRect.h = avatarH; avatarRect.w = avatarW; avatarRect.x = _transform.position.x; avatarRect.y = _transform.position.y;
	
	SDL_Point center;
	center.x = avatarRect.w / 2;
	center.y = avatarRect.h / 2;

	//SDL_RenderCopy(renderer, _avatar, NULL, &r);
	SDL_RenderCopyEx(renderer, _avatar, NULL, &avatarRect, _transform.rotation.z, &center, SDL_FLIP_NONE);

	face.x = transformedEndPoint.x;
	face.y = transformedEndPoint.y;


}


void Player::move(float dt, SDL_Keycode key) {
/*	printf("X: %f, Y: %f\n", _transform.position.x, _transform.position.y);
	printf("fX: %d, fY: %d\n", face.x, face.y);
		printf("z%f\n", _transform.rotation.z);
*/	int x = face.x - _transform.position.x;
	int y = face.y - _transform.position.y;
//	printf("x: %d, y: %d\n\n", x, y);
	switch(key) {
		case SDLK_LEFT: case SDLK_a:
			_transform.rotation.z -= (rotationSpeed * dt);
			printf("hello?");
			break;
		case SDLK_RIGHT: case SDLK_d:
			_transform.rotation.z += (rotationSpeed * dt);
			break;
		case SDLK_UP: case SDLK_w:	
			if (y < 0 && x > 0) {					
				_transform.position.x -= (speed * dt);
				_transform.position.y -= (speed * dt);
			} else if (y == 0 && x == avatarW/2 - 1) {		
				_transform.position.y -= (speed * dt);
			} else if (y > 0 && x > 0) {			
				_transform.position.x += (speed * dt);
				_transform.position.y -= (speed * dt);
			} else if (y == avatarH/2 - 1 && x == 0) {				
				_transform.position.x += (speed * dt);
			} else if (y > 0 && x < 0) {
				_transform.position.x += (speed * dt);
				_transform.position.y += (speed * dt);
			} else if (y == 0 && x == -avatarW/2) {
				_transform.position.y += (speed * dt);
			} else if (y < 0 && x < 0) {
				_transform.position.x -= (speed * dt);
				_transform.position.y += (speed * dt);
			} else if (y == -avatarH/2 && x == 0) {
				_transform.position.x -= (speed * dt);
			}
			break;
		default:
			break;
	}
}


void Player::collision(float dt, SDL_Rect intersc) {
	int x = intersc.x - avatarW/2 - _transform.position.x;
	int y = intersc.y - avatarH/2 - _transform.position.y;

	if (y < 0 && x > 0) {					
		_transform.position.x += (speed * dt);
		_transform.position.y += (speed * dt);
	} else if (y == 0 && x == avatarW/2 - 1) {		
		_transform.position.y += (speed * dt);
	} else if (y > 0 && x > 0) {			
		_transform.position.x -= (speed * dt);
		_transform.position.y += (speed * dt);
	} else if (y == avatarH/2 - 1 && x == 0) {				
		_transform.position.x -= (speed * dt);
	} else if (y > 0 && x < 0) {
		_transform.position.x -= (speed * dt);
		_transform.position.y -= (speed * dt);
	} else if (y == 0 && x == -avatarW/2) {
		_transform.position.y -= (speed * dt);
	} else if (y < 0 && x < 0) {
		_transform.position.x += (speed * dt);
		_transform.position.y -= (speed * dt);
	} else if (y == -avatarH/2 && x == 0) {
		_transform.position.x += (speed * dt);
	}
}