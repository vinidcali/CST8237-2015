#pragma once

#include <GameEngine.h>
#include <SDL_image.h>
#include "Player.h"
#include "Wall.h"

union SDL_Event;

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
  Wall *_wall;
//  SDL_Texture *_banana;
};