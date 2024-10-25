#include "player.h"
#include <raylib.h>
#include <string>
const Vector2 SIZE = {40, 50};
const int SPAWN_ROTATION = 90;
const float PLAYER_SPEED = 5.0f;
const int PLAYER_ROT_SPEED = 5; //FIXME: work only with 5 mutiples
const float DELAY_SHOTS = 0.1f;

struct CardinalPoints {
    const int n = 180;
    const int s = 0;
    const int e = 270;
    const int o = 90;
    const int ne = 225;
    const int no = 135;
    const int se = 315;
    const int so = 45;
} ANGLES;

Player::Player(Vector2 position) {
    gameObjects.push_back(this);
    _rectangle = {position.x, position.y, SIZE.x, SIZE.y};
    _speed = PLAYER_SPEED;
    _rot_speed = PLAYER_ROT_SPEED;
    _rotation = SPAWN_ROTATION;
    
    timeBetweenShots = DELAY_SHOTS;
    lastShot = (float)GetTime() - timeBetweenShots;
}

void Player::update() {
    movement();
    shooting();
}

void Player::movement() {
    // Right-left movement
    if (IsKeyDown(KEY_D)) {
        if (_rotation == ANGLES.e) {
            _rectangle.x += _speed;
        }
        else if (_rotation >= ANGLES.o && _rotation < ANGLES.e) {
            _rotation += _rot_speed;
        }
        else if ((_rotation >= ANGLES.s && _rotation <= ANGLES.o) || (_rotation > ANGLES.e && _rotation < 360)) {
            _rotation -= _rot_speed;
         }
    }
    if (IsKeyDown(KEY_A)){
        if (_rotation == ANGLES.o) {
            _rectangle.x -= _speed;
        }
        else if (_rotation > ANGLES.o && _rotation <= ANGLES.e) {
            _rotation -= _rot_speed;
        }
        else if ((_rotation >= ANGLES.s && _rotation < ANGLES.o) || (_rotation > ANGLES.e && _rotation < 360)) {
            _rotation += _rot_speed;
        }
    }
    // Up-down movement
    if (IsKeyDown(KEY_W)) {
        if (_rotation == ANGLES.n) {
            _rectangle.y -= _speed;
        }
        else if (_rotation >= ANGLES.s && _rotation < ANGLES.n) {
            _rotation += _rot_speed;
        }
        else if (_rotation > ANGLES.n && _rotation <= 360) {
            _rotation -= _rot_speed;
        }
    } 
    if (IsKeyDown(KEY_S)) {
        if (_rotation == ANGLES.s) {
            _rectangle.y += _speed;
        }
        else if (_rotation <= ANGLES.n && _rotation > ANGLES.s) {
            _rotation -= _rot_speed;
        }
        else if ((_rotation > ANGLES.n && _rotation < 360)) {
            _rotation += _rot_speed;
        }
    }
    // Combined movement
    if (IsKeyDown(KEY_W) && IsKeyDown(KEY_D)) {
        if (_rotation == ANGLES.ne) {
            _rectangle.x += _speed;
            _rectangle.y -= _speed;
        }
        else if (_rotation < ANGLES.ne && _rotation >= ANGLES.so) {
            _rotation += _rot_speed;
        }
        else if ((_rotation > ANGLES.ne && _rotation < 360) || (_rotation >= ANGLES.s && _rotation < ANGLES.so)) {
            _rotation -= _rot_speed;
        }
    }
    if (IsKeyDown(KEY_W) && IsKeyDown(KEY_A)) {
        if (_rotation == ANGLES.no) {
            _rectangle.x -= _speed;
            _rectangle.y -= _speed;
        }
        else if (_rotation > ANGLES.no && _rotation <= ANGLES.se) {
            _rotation -= _rot_speed;
        }
        else if ((_rotation < ANGLES.no && _rotation > ANGLES.s) || (_rotation >= ANGLES.s && _rotation < ANGLES.se)) {
            _rotation += _rot_speed;
        }
    }
    if (IsKeyDown(KEY_S) && IsKeyDown(KEY_A)) {
        if (_rotation == ANGLES.so) {
            _rectangle.x -= _speed;
            _rectangle.y += _speed;
        }
        else if (_rotation > ANGLES.so && _rotation <= ANGLES.ne) {
            _rotation -= _rot_speed;
        }
        else if ((_rotation < ANGLES.so && _rotation >= ANGLES.s) || (_rotation > ANGLES.so && _rotation < ANGLES.ne)) {
            _rotation += _rot_speed;
        }
    }
    if (IsKeyDown(KEY_S) && IsKeyDown(KEY_D)) {
        if (_rotation == ANGLES.se) {
            _rectangle.x += _speed;
            _rectangle.y += _speed;
        }
        else if (_rotation >= ANGLES.no && _rotation < ANGLES.se) {
            _rotation += _rot_speed;
        }
        else if ((_rotation > ANGLES.se && _rotation < 360) || (_rotation >= ANGLES.s && _rotation < ANGLES.no)) {
            _rotation -= _rot_speed;
        }
    }
    _rotation = (_rotation % 360 + 360) % 360;

} 

void Player::shooting() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && lastShot + timeBetweenShots <= GetTime()) {
        new Bullet({_rectangle.x, _rectangle.y}, GetMousePosition());
        lastShot = (float)GetTime();
    }

}

void Player::render() {
    Vector2 pivot = {_rectangle.width / 2, _rectangle.height / 2};
    DrawRectanglePro(_rectangle, pivot, _rotation, RED);
    DrawCircleV({_rectangle.x, _rectangle.y}, 5, YELLOW); // Draw center for debugging
}

void Player::destroy() {
    delete this;
}

Player::~Player() {}
