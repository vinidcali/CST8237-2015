/**
 * \class Game
 * \brief Inheriting from GameEngine, represents the game environment.
 * \author Vinícius de Carli
 * \date February 12, 2015
 */

#pragma once

#include <GameEngine.h>
#include <SDL_image.h>
#include "Player.h"
#include "Wall.h"
#include "Projectile.h"


union SDL_Event;


class b2World;				//manages all the bodies
class b2Body;				//a logical whole (like a car: it's made of 2 circles and a square, all together nakes a body)
class b2Fixture;			//the shape bodies are made of


struct _Mix_Music;			//compressed, long, large file -> stream
struct Mix_Chunk;			//short, 



class Game: public GameEngine
{
  friend class GameEngine;

public:
	/**
	* \fn		void Game::~Game()
	* \brief	Standard deconstructor for Game.
	*/
  ~Game();

protected:
	/**
	* \fn		void Game::Game()
	* \brief	Standard constructor for Game.
	*/
	Game();

	/**
	 * \fn		void Game::InitializeImpl()
	 * \brief	The virtual function inherited from GameEngine. It is used to set initial
	 *			values and run initalizing routines.
	 */
	void InitializeImpl();

	/**
	 * \fn		void Game::UpdateImpl(float dt)
	 * \brief	The virtual function inherited from GameEngine. It is used to update the
	 *			objects in the game while the program is running.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	void UpdateImpl(float dt);

	/**
	 * \fn		void Game::DrawImpl(SDL_Renderer *renderer, float dt)
	 * \brief	The virtual function inherited from GameEngine. It is used to define how
	 *			the objects in the game will be draw to the screen.
	 * \param	renderer	The SDL renderer used to draw the object.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	void DrawImpl(SDL_Renderer *renderer, float dt);

	void Reset();
	void CalculateDrawOrder(std::vector<GameObject *>& drawOrder);


	Player *_player1, *_player2;
	std::vector<Wall *> _walls;
	Projectile *_proj1, *_proj2;

	std::string _title;

	b2World *_world;
	b2Body *_boxBody;
	b2Fixture *_boxFixture;

	_Mix_Music* _music;
	Mix_Chunk* _sfx;

};