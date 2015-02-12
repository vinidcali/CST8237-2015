/**
 * \class Wall
 * \brief Inheriting from GameObject, represents the player in the game.
 * \author Vinícius de Carli
 * \date February 12, 2015
 */

#pragma once

#include <GameObject.h>
#include <SDL_image.h>


class Wall : public GameObject {

public:
	/**
	 * \fn		void Wall::Initialize(SDL_Renderer *renderer)
	 * \brief	Function inherited from GameObject. It is used to set initial values and run initalizing routines
	 *			before the object is used elsewhere.
	 * \param	renderer	The SDL renderer used to draw the object.
	 */
	void Initialize(SDL_Renderer *renderer);

	/**
	 * \fn		void Wall::Update(float dt)
	 * \brief	Function inherited from GameObject. It is used to update the object in every new game loop.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	void Update(float dt);

	/**
	 * \fn		void Wall::Draw(SDL_Renderer *renderer, float dt)
	 * \brief	Function inherited from GameObject. It defines how the object is draw to the screen.
	 * \param	renderer	The SDL renderer used to draw the object.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	void Draw(SDL_Renderer *renderer, float dt);

	/**
	* \fn		void Wall::Wall()
	* \brief	Standard constructor for Wall.
	*/
	Wall();

	/**
	* \fn		void Wall::~Wall()
	* \brief	Standard deconstructor for Wall.
	*/
	~Wall();


	SDL_Texture *_wall;
	SDL_Rect wallRect;
	int wallW, wallH;

};
