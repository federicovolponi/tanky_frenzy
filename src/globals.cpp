#include "globals.h"

const float SCREENWIDTH = 1080.0f;
const float SCREENHEIGHT = 980.0f;

// Player constants
const Vector2 PLAYER_SIZE = {50, 40};
const int PLAYER_SPAWN_ROT = 0.0f;
const float PLAYER_SPEED = 250.0f;
const int PLAYER_ROT_SPEED = 300;

// Weapon constants
const Vector2 WEAPON_SIZE = {10, 40};
const float WEAPON_SPAWN_ROT = 90.0f;
const float DELAY_SHOTS = 0.1f;

// Arena constants
const Vector2 ARENA_POSITION = {20, 20};
const Vector2 ARENA_DIMENSIONS = {0.7f * SCREENWIDTH, 0.7f * SCREENHEIGHT};
const float ARENA_WIDTH = 1.0f;

// Bullet constants
const float BULLET_SPEED = 500.0f;
const int BULLET_SIZE = 5;
const int BULLET_TTL = 4;

std::list<GameObject*> gameObjects;
