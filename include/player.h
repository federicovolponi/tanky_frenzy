#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include <cmath>
#include "bullet.h"
#include "weapon.h"
#include <memory>
#include <raylib.h>

extern const Vector2 PLAYER_SIZE;
extern const int PLAYER_SPAWN_ROT;
extern const float PLAYER_SPEED;
extern const int PLAYER_ROT_SPEED;

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
        int _rotation;
        float _speed;
        int _rot_speed;

        std::unique_ptr<Weapon> weapon;

        void movement();
};

#endif
