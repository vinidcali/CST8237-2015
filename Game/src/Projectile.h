/**
 * \class Projectile
 * \brief Inheriting from GameObject, represents the player in the game.
 * \author Vin�cius de Carli
 * \date February 26, 2015
 */

#pragma once

#include <GameObject.h>
#include <SDL_image.h>


class Projectile : public GameObject {

public:
	/**
	 * \fn		void Projectile::Initialize(SDL_Renderer *renderer)
	 * \brief	Function inherited from GameObject. It is used to set initial values and run initalizing routines
	 *			before the object is used elsewhere.
	 * \param	renderer	The SDL renderer used to draw the object.
	 */
	void Initialize(SDL_Renderer *renderer);

	/**
	 * \fn		void Projectile::Update(float dt)
	 * \brief	Function inherited from GameObject. It is used to update the object in every new game loop.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	void Update(float dt);

	/**
	 * \fn		void Projectile::Draw(SDL_Renderer *renderer, float dt)
	 * \brief	Function inherited from GameObject. It defines how the object is draw to the screen.
	 * \param	renderer	The SDL renderer used to draw the object.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	void Draw(SDL_Renderer *renderer, float dt);

	/**
	* \fn		void Projectile::Projectile()
	* \brief	Standard constructor for Player.
	*/
	Projectile();

	/**
	* \fn		void Projectile::~Projectile()
	* \brief	Standard deconstructor for Player.
	*/
	~Projectile();


	void shoot(float dt);

	void collision(float dt, SDL_Rect intersc);

	void setOrigin(int x, int y);

	/**
	* \fn		void Projectile::destroy()
	* \brief	Destroys the projectile texture (erases it from screen).
	*/
	void destroy();

	SDL_Point origin;
	SDL_Texture *_avatar;
	SDL_Rect avatarRect;
	int avatarW, avatarH;
	int bounces;
	bool shootFlag;
	float speed;

};
