#ifndef PLAYER_H
#define PLAYER_H

#include "gameobject.h"
#include "globals.h"
#include "bullet.h"
#include "raylib.h"

extern const Vector2 SIZE;
extern const int SPAWN_ROTATION;
extern const float PLAYER_SPEED;
extern const int PLAYER_ROT_SPEED;
extern const float DELAY_SHOTS;

class Player : public GameObject {
    public:
        Player(Vector2 position);
        virtual void update() override;
        virtual void render() override;
        virtual void destroy() override;
        ~Player();
    private:
        // Player movement
        Vector2 _position;
        Rectangle _rectangle;
        int _rotation;
        float _speed;
        int _rot_speed;
        // Shooting logic
        // NOTE: maybe to handle somewhere else
        float lastShot;
        float timeBetweenShots;

        void movement();
        void shooting();
};

#endif
