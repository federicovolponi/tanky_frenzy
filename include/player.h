#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "weapon.h"
#include <memory>

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
        float _rotation;
        Vector2 _size;
        float _targetRotation;
        float _speed;
        int _rot_speed;
        
        // Weapon is totally managed by player instance
        std::unique_ptr<Weapon> weapon;

        void movement();
        void moveInDirection(Vector2 moveDirection);
        void rotate();
        
        bool checkArenaCollision(Rectangle playerHitBox);
};

#endif
