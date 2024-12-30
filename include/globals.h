#ifndef GLOBALS_H
#define GLOBALS_H

#include "gameobject.h"
#include "raylib.h"
#include <list>

extern float SCREENWIDTH;
extern float SCREENHEIGHT;

extern Vector2 ARENA_POSITION;
extern Vector2 ARENA_DIMENSIONS;

//All gameobjects in the game
extern std::list<GameObject*> gameObjects;

#endif
