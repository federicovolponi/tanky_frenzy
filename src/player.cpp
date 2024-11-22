#include "player.h"
#include <string>
const Vector2 PLAYER_SIZE = {40, 50};
const int PLAYER_SPAWN_ROT = 90;
const float PLAYER_SPEED = 5.0f;
const int PLAYER_ROT_SPEED = 5; //FIXME: work only with 5 mutiples

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
    _position = position;
    _speed = PLAYER_SPEED;
    _rot_speed = PLAYER_ROT_SPEED;
    _rotation = PLAYER_SPAWN_ROT; 
    // Initialize the player's weapon
    Vector2 *ptr_pos = &_position;
    weapon.reset(new Weapon(ptr_pos)); 
}

void Player::update() {
    movement();
}

void Player::movement() {
    // Right-left movement
    if (IsKeyDown(KEY_D)) {
        if (_rotation == ANGLES.e) {
            _position.x += _speed;
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
            _position.x -= _speed;
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
            _position.y -= _speed;
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
            _position.y += _speed;
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
            _position.x += _speed * sqrt(2) / 2;
            _position.y -= _speed * sqrt(2) / 2;
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
            _position.x -= _speed * sqrt(2) / 2;
            _position.y -= _speed * sqrt(2) / 2;
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
            _position.x -= _speed * sqrt(2) / 2;
            _position.y += _speed * sqrt(2) / 2;
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
            _position.x += _speed * sqrt(2) / 2;
            _position.y += _speed * sqrt(2) / 2;
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

void Player::render() {
    Rectangle rectangle = {_position.x, _position.y, PLAYER_SIZE.x, PLAYER_SIZE.y};
    Vector2 pivot = {rectangle.width / 2, rectangle.height / 2};
    DrawRectanglePro(rectangle, pivot, _rotation, RED);
    DrawCircleV({_position.x, _position.y}, 5, YELLOW); // Draw center for debugging
}

void Player::destroy() {
    delete this;
}

Player::~Player() {}
