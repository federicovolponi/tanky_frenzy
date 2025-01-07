#include "arena.h"
#include <raylib.h>


Arena* Arena::_instance = nullptr;

Arena::Arena() {
    gameObjects.push_back(this);
    _boundary = {ARENA_POSITION.x, ARENA_POSITION.y, ARENA_DIMENSIONS.x, ARENA_DIMENSIONS.y};
}

// Allows only one instance of the arena class
Arena* Arena::Instance() {
    if (_instance == nullptr) {
        _instance = new Arena;
    }
    return _instance;
}

void Arena::update() {

}

//TODO: player collision does not take into account rotations
void Arena::handlePlayerCollision(Vector2& playerPosition, Vector2 playerSize) {
    float playerLength = playerSize.x / 2;
    if (playerPosition.x - playerLength < _boundary.x) playerPosition.x = _boundary.x + playerLength;
    if (playerPosition.y - playerLength < _boundary.y) playerPosition.y = _boundary.y + playerLength;
    if (playerPosition.x + playerLength > _boundary.x + _boundary.width)
        playerPosition.x = _boundary.x + _boundary.width - playerLength;
    if (playerPosition.y + playerLength > _boundary.y + _boundary.height)
        playerPosition.y = _boundary.y + _boundary.height - playerLength ;
}

bool Arena::checkBulletCollision(Vector2 bulletPosition, int bulletSize) {
    if (!CheckCollisionCircleRec(bulletPosition, bulletSize, getInternalBorder())) {
        return true;
    }
    return false;
}

void Arena::render() {
    DrawRectangleLinesEx(_boundary, ARENA_WIDTH, GRAY);
}

Rectangle Arena::getInternalBorder() const {
    return {_boundary.x, _boundary.y, _boundary.width - ARENA_WIDTH, _boundary.height - ARENA_WIDTH};
}

void Arena::destroy() {

}

Arena::~Arena() {

}
