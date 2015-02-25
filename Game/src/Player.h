/**
 * \class Player
 * \brief Inheriting from GameObject, represents the player in the game.
 * \author Vinícius de Carli
 * \date February 12, 2015
 */

#pragma once

#include <GameObject.h>
#include <SDL_image.h>


class Player : public GameObject {

public:
	/**
	 * \fn		void Player::Initialize(SDL_Renderer *renderer)
	 * \brief	Function inherited from GameObject. It is used to set initial values and run initalizing routines
	 *			before the object is used elsewhere.
	 * \param	renderer	The SDL renderer used to draw the object.
	 */
	void Initialize(SDL_Renderer *renderer);

	/**
	 * \fn		void Player::Update(float dt)
	 * \brief	Function inherited from GameObject. It is used to update the object in every new game loop.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	void Update(float dt);

	/**
	 * \fn		void Player::Draw(SDL_Renderer *renderer, float dt)
	 * \brief	Function inherited from GameObject. It defines how the object is draw to the screen.
	 * \param	renderer	The SDL renderer used to draw the object.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	void Draw(SDL_Renderer *renderer, float dt);

	/**
	* \fn		void Player::Player()
	* \brief	Standard constructor for Player.
	*/
	Player();

	/**
	* \fn		void Player::~Player()
	* \brief	Standard deconstructor for Player.
	*/
	~Player();

	/**
	 * \fn		void Player::move(float dt, SDL_Keycode key)
	 * \brief	Algorithm that makes the players move forward based on the direction they're facing or sideways.
	 * \param	dt			The time in fractions of a second since the last pass.
	 * \param	key			The SDL key code representing the keyboard key being used.
	 */
	void move(float dt, SDL_Keycode key);
	
	/**
	 * \fn		void Player::collision(float dt, SDL_Keycode key)
	 * \brief	Algorithm that makes the players move backwards when they hit something in the game world.
	 * \param	dt			The time in fractions of a second since the last pass.
	 * \param	key			The coordinates representing the location where the collision happened.
	 */
	void collision(float dt, SDL_Rect intersc);


	SDL_Point face;
	SDL_Texture *_avatar;
	SDL_Rect avatarRect;
	int avatarW, avatarH;
	int points;
	float speed, rotationSpeed;

};
