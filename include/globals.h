#ifndef GLOBALS_H
#define GLOBALS_H

#include "gameobject.h"
#include "raylib.h"
#include <list>

extern float SCREENWIDTH;
extern float SCREENHEIGHT;

//All gameobjects in the game
extern std::list<GameObject*> gameObjects;

#endif
