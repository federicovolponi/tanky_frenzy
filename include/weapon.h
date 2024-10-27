#ifndef WEAPON_H
#define WEAPON_H

#include "globals.h"
#include "bullet.h"
#include <cmath>
#include <raylib.h>
#include <math.h>

extern const Vector2 WEAPON_SIZE;
extern const float WEAPON_SPAWN_ROT;
extern const float DELAY_SHOTS;

class Weapon : public GameObject {
    public:
        Weapon(Vector2 *player_pos);
        virtual void update();
        virtual void render();
        virtual void destroy();
        virtual ~Weapon();
    private:
        // Weapon position
        Vector2 *_position;
        float _rotation;
        float _hypotenuse;
        Vector2 getNormDirection();
        // Shooting variables
        float lastShot;
        float timeBetweenShots;

        void shooting(Vector2& direction);
};
#endif 

