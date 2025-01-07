#ifndef GLOBALS_H
#define GLOBALS_H

#include "gameobject.h"
#include "raylib.h"
#include <list>

// Screen window dimensions
extern const float SCREENWIDTH;
extern const float SCREENHEIGHT;

// Player constants
extern const Vector2 PLAYER_SIZE;
extern const int PLAYER_SPAWN_ROT;
extern const float PLAYER_SPEED;
extern const int PLAYER_ROT_SPEED;

// Weapon constants
extern const Vector2 WEAPON_SIZE;
extern const float WEAPON_SPAWN_ROT;
extern const float DELAY_SHOTS;

// Arena constants
extern const Vector2 ARENA_POSITION;
extern const Vector2 ARENA_DIMENSIONS;
extern const float ARENA_WIDTH;

// Bullet constants
extern const float BULLET_SPEED;
extern const int BULLET_SIZE;
extern const int BULLET_TTL;

//All gameobjects in the game
extern std::list<GameObject*> gameObjects;

#endif
