#ifndef BULLET_H
#define BULLET_H

#include "globals.h"
#include "arena.h"
#include <algorithm>
#include <math.h>

extern const float BULLET_SPEED;
extern const int BULLET_SIZE;
extern const int BULLET_TTL;

class Bullet : public GameObject {
    public:
        Bullet(Vector2 player_pos, Vector2 mouse_pos);
        virtual void update();
        virtual void render();
        virtual void destroy();
        virtual ~Bullet();
    private:
        Vector2 _position;
        Vector2 _direction;
        float _speed;
        float _timeAlive;

        bool checkArenaCollision();
};

#endif
