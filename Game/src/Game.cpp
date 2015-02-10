#include "Game.h"
#include <GameObject.h>
#include <SDL.h>
#include <math.h>
#include <SDL_image.h>
#include <Box2D\Box2D.h>

// Initializing our static member pointer.
GameEngine* GameEngine::_instance = nullptr;

GameEngine* GameEngine::CreateInstance()
{
  if (_instance == nullptr)
  {
    _instance = new Game();
  }
  return _instance;
}

Game::Game() : GameEngine()
{

}

Game::~Game()
{
}

void Game::InitializeImpl()
{
  SDL_SetWindowTitle(_window, "Game");
  
  _player1 = new Player();
  _objects.push_back(_player1);

  _player2 = new Player();
  _objects.push_back(_player2);
//  _objects.push_back(_wall);

  for (auto itr = _objects.begin(); itr != _objects.end(); itr++)
  {
    (*itr)->Initialize(_renderer);
  }
  
 // IMG_Init(IMG_INIT_PNG);						//initalizes the kind of image we will use
  //_banana = IMG_LoadTexture(_renderer, "./banana.png");		//loads the image


//Initialize Box2D world
  b2Vec2 gravity(0.0f, 1.0f);
  _world = new b2World(gravity);

  b2BodyDef boxBodyDef;					//dynamic (moves in the world, influenced by gravity), static (fixed, doesn't move)
  boxBodyDef.type =	b2_dynamicBody;		// and kinematic (0 mass object, but is moved automatically)
  _boxBody = _world->CreateBody(&boxBodyDef);		//gets the actual body object

  b2Vec2 boxPos(250, 0);
  _boxBody->SetTransform(boxPos, 0.0f);		//places the box in the top of the screen

  b2PolygonShape boxShape;
  boxShape.SetAsBox(5, 5);
  _boxFixture = _boxBody->CreateFixture(&boxShape, 0.0f);		//fixes the shape inside the body
//however, so far we dont have a visual representation to it yet, so we cant see anything

}

void Game::UpdateImpl(float dt)
{
  SDL_Event evt;
  SDL_PollEvent(&evt);

  if (evt.type == SDL_KEYDOWN) {
		SDL_KeyboardEvent &keyboardEvt = evt.key;
		SDL_Keycode &keyCode = keyboardEvt.keysym.sym;			//key symbols
		switch(keyCode) {
			case SDLK_UP: case SDLK_DOWN: SDLK_LEFT: case SDLK_RIGHT:
				_player2 -> move(dt, keyCode);
				break;
			case SDLK_w: case SDLK_s: SDLK_a: case SDLK_d:
				_player1 -> move(dt, keyCode);
				break;
			default:
				break;
		}
  }


  for (auto itr = _objects.begin(); itr != _objects.end(); itr++)
  {
    (*itr)->Update(dt);
  }
}

void Game::DrawImpl(SDL_Renderer *renderer, float dt)
{
  std::vector<GameObject *> renderOrder;
  CalculateDrawOrder(renderOrder);

  for (auto itr = renderOrder.begin(); itr != renderOrder.end(); itr++)
  {
    (*itr)->Draw(renderer, dt);
  }

/*  int w, h, winW, winH;
	SDL_QueryTexture(_banana, NULL, NULL, &w, &h);
	SDL_GetWindowSize(_window, &winW, &winH);

	SDL_Rect r;
	r.h = h; r.w = w; r.x = winW/2 - w/2; r.y = winH/2 - h/2;
	
	SDL_RenderCopy(renderer, _banana, NULL, &r);
*/
}

void Game::CalculateDrawOrder(std::vector<GameObject *>& drawOrder)
{
  // SUPER HACK GARBAGE ALGO.
  drawOrder.clear();

  auto objectsCopy = _objects;
  auto farthestEntry = objectsCopy.begin();
  while (objectsCopy.size() > 0)
  {
    bool entryFound = true;
    for (auto itr = objectsCopy.begin(); itr != objectsCopy.end(); itr++)
    {
      if (farthestEntry != itr)
      {
        if ((*itr)->GetTransform().position.y < (*farthestEntry)->GetTransform().position.y)
        {
          entryFound = false;
          farthestEntry = itr;
          break;
        }
      }
    }

    if (entryFound)
    {
      GameObject *farthest = *farthestEntry;

      drawOrder.push_back(farthest);
      objectsCopy.erase(farthestEntry);
      farthestEntry = objectsCopy.begin();
    }
  }
}
