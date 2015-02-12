/**
 * \class GameObject
 * \brief A generic class for creating all the objects present in the game.
 * \author Vinícius de Carli
 * \date February 12, 2015
 */

#pragma once 

#include "MathUtils.h"

struct SDL_Renderer;

class GameObject
{
public:
	/**
	 * \fn		virtual void GameObject::Initialize(SDL_Renderer *renderer) = 0
	 * \brief	The virtual function which will be inherited by other classes and used to
	 *			set initial values and run initalizing routines.
	 */
	virtual void Initialize(SDL_Renderer *renderer) = 0;
  
	/**
	 * \fn		virtual void GameObject::Update(float dt) = 0
	 * \brief	The virtual function which will be inherited by other classes and used to update these
	 *			objects while the program is running.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	virtual void Update(float dt) = 0;

	/**
	 * \fn		virtual void GameObject::Draw(SDL_Renderer *renderer, float dt) = 0
	 * \brief	The virtual function which will be inherited by other classes and used to define how
	 *			these objects will be draw to the screen.
	 * \param	renderer	The SDL renderer used to draw the object.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	virtual void Draw(SDL_Renderer *renderer, float dt) = 0;

	/**
	 * \fn		Transform& GameObject::GetTransform()
	 * \brief	The virtual function which will be inherited by other classes and used to retrieve the Transform structure.
	 * \return	_transform structure.
	 */
	Transform& GetTransform();

	/**
	* \fn		void GameObject::~GameObject()
	* \brief	Standard deconstructor for GameObject.
	*/
	~GameObject();

protected:
	/**
	* \fn		void GameObject::GameObject()
	* \brief	Standard constructor for GameObject.
	*/
	GameObject();

	Transform _transform;
};