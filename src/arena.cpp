#include "arena.h"
#include <raylib.h>

const float ARENA_WIDTH = 15.0f;

Arena* Arena::_instance = nullptr;

Arena::Arena() {
    gameObjects.push_back(this);
    _shape = {0, 0, SCREENWIDTH, SCREENHEIGHT};
}

Arena* Arena::Instance() {
    /* Allows only one instance of the arena class */
    if (_instance == nullptr) {
        _instance = new Arena;
    }
    return _instance;
}

void Arena::update() {

}

void Arena::render() {
    DrawRectangleLinesEx(_shape, ARENA_WIDTH, GRAY);
}

Rectangle Arena::getInternalBorder() const {
    return {_shape.x, _shape.y, _shape.width - ARENA_WIDTH, _shape.height - ARENA_WIDTH};
}

void Arena::destroy() {

}

Arena::~Arena() {

}
