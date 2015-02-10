/**
 * \class Player
 * \brief Inheriting from GameObject, represents the player in the game.
 * \author Vinícius de Carli
 * \date January 29, 2015
 */

#pragma once

#include <GameObject.h>
#include <SDL_image.h>


class Player : public GameObject {

public:
	/**
	 * \fn		void Player::Initialize()
	 * \brief	Function inherited from GameObject. It is used to set initial values and run initalizing routines
	 *			before the object is used elsewhere.
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

	int rice;
	SDL_Texture *_avatar;

};
