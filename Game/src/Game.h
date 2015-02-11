#pragma once

#include <GameEngine.h>
#include <SDL_image.h>
#include "Player.h"
#include "Wall.h"


union SDL_Event;


class b2World;				//manages all the bodies
class b2Body;				//a logical whole (like a car: it's made of 2 circles and a square, all together nakes a body)
class b2Fixture;			//the shape bodies are made of


class Game: public GameEngine
{
  friend class GameEngine;

public:
  ~Game();

protected:
  Game();

  void InitializeImpl();
  void UpdateImpl(float dt);
  void DrawImpl(SDL_Renderer *renderer, float dt);

  void Reset();
  void CalculateDrawOrder(std::vector<GameObject *>& drawOrder);

  Player *_player1, *_player2;
  std::vector<Wall *> _walls;
//  SDL_Texture *_banana;


	b2World *_world;
	b2Body *_boxBody;
	b2Fixture *_boxFixture;

};