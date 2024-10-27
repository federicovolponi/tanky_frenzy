#include "weapon.h"
#include <cmath>
#include <raylib.h>

const Vector2 WEAPON_SIZE = {10, 40};
const float WEAPON_SPAWN_ROT = 90.0f;
const float DELAY_SHOTS = 0.1f;

Weapon::Weapon(Vector2 *player_pos) {
    gameObjects.push_back(this);
    _position = player_pos;
    _rotation = WEAPON_SPAWN_ROT;
    _hypotenuse = sqrt(pow(WEAPON_SIZE.x, 2) + pow(WEAPON_SIZE.y, 2));
    
    timeBetweenShots = DELAY_SHOTS;
    lastShot = (float)GetTime() - timeBetweenShots;
}

void Weapon::update() {
    Vector2 direction = getNormDirection();
    _rotation = - atan2(direction.x, direction.y) * (180.0f / M_PI);
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && lastShot + timeBetweenShots <= GetTime()) {
        shooting(direction);
    }
}

void Weapon::render() {
    float x_pos = _position->x;
    float y_pos = _position->y;
    Rectangle rectangle = {x_pos, y_pos, WEAPON_SIZE.x, WEAPON_SIZE.y};
    Vector2 pivot = {rectangle.width / 2, 0};
    DrawRectanglePro(rectangle, pivot, _rotation, BLUE);
}

void Weapon::destroy() {
    delete this;
}

void Weapon::shooting(Vector2& direction) {
    Vector2 shoot_origin = *_position;
    shoot_origin.x += direction.x * _hypotenuse;
    shoot_origin.y += direction.y * _hypotenuse;
    new Bullet(shoot_origin, GetMousePosition());
    lastShot = (float)GetTime();
}

Vector2 Weapon::getNormDirection() {
    Vector2 mouse_pos = GetMousePosition();
    Vector2 direction = {mouse_pos.x - _position->x, mouse_pos.y - _position->y};
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {
        direction.x /= length;
        direction.y /= length;
    }
    return direction;
}


Weapon::~Weapon() {}
