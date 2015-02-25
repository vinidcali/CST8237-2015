#include "Projectile.h"
#include <SDL.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <SDL_image.h>
#include <stdio.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds



Projectile::Projectile() : GameObject() {

}

Projectile::~Projectile() {

}

void Projectile::Initialize(SDL_Renderer *renderer) {
	speed = 600;
	avatarW = 20;
	avatarH = 20;
	bounces = 0;
	
	_transform.position.x = 0;
	_transform.position.y = 0;

	IMG_Init(IMG_INIT_PNG);						//initalizes the kind of image we will use
	_avatar = IMG_LoadTexture(renderer, "./laser.png");		//loads the image
	
}

void Projectile::Update(float dt) {
	if (shootFlag) {
		shoot(dt);
	}
	if (bounces == 5)
		destroy();
}

void Projectile::Draw(SDL_Renderer *renderer, float dt) {
	_transform.position.x += _transform.position.x >= 900 ? -900 : (_transform.position.x <= 0 ? 900 : 0);
	_transform.position.y += _transform.position.y >= 600 ? -600 : (_transform.position.y <= 0 ? 600 : 0);

	avatarRect.h = avatarH; avatarRect.w = avatarW; avatarRect.x = _transform.position.x; avatarRect.y = _transform.position.y;
	
	SDL_Point center;
	center.x = avatarRect.w / 2;
	center.y = avatarRect.h / 2;

	SDL_RenderCopyEx(renderer, _avatar, NULL, &avatarRect, _transform.rotation.z, &center, SDL_FLIP_NONE);
}


void Projectile::shoot(float dt) {
	int x = _transform.position.x;
	int y = _transform.position.y;

	
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

}


void Projectile::collision(float dt, SDL_Rect intersc) {
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


void Projectile::setOrigin(int x, int y) {
	_transform.position.x = x;
	_transform.position.y = y;

	shootFlag = true;
}

void Projectile::destroy() {
	SDL_DestroyTexture(_avatar);
}