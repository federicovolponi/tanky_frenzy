#include "bullet.h"

const float BULLET_SPEED = 500.0f;
const int BULLET_SIZE = 5;
const int BULLET_TTL = 4;

Bullet::Bullet(Vector2 player_pos, Vector2 mouse_pos) {
    gameObjects.push_back(this);
    _position = player_pos;
    _direction = getNormDirection(player_pos, mouse_pos);
    _speed = BULLET_SPEED;
    _timeAlive = 0;

}

void Bullet::update() {
    _position.x += _direction.x * _speed * GetFrameTime();
    _position.y += _direction.y * _speed * GetFrameTime();
    // Destroy the bullet
    if (_timeAlive < BULLET_TTL) {
        _timeAlive += GetFrameTime();
    }
    else {
        setToDelete(true);
    }

}

void Bullet::render() {
    DrawCircleV(_position, BULLET_SIZE, GREEN);
}

void Bullet::destroy() {
    delete this;
}

Vector2 Bullet::getNormDirection(Vector2 start, Vector2 end) {
    Vector2 direction = { end.x - start.x, end.y - start.y };
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {
        direction.x /= length;
        direction.y /= length;
    }
    return direction;
}

Bullet::~Bullet() {}
