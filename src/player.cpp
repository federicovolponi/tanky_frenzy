#include "player.h"
#include <raylib.h>

const Vector2 PLAYER_SIZE = {50, 40};
const int PLAYER_SPAWN_ROT = 0.0f;
const float PLAYER_SPEED = 250.0f;
const int PLAYER_ROT_SPEED = 300;

Player::Player(Vector2 position) {
    gameObjects.push_back(this);
    
    // Initialize player movement variables
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
    weapon->update();
}

// Utility to calculate the shortest angle difference
float AngleDifference(float target, float current) {
    float diff = fmodf(target - current + 180.0f, 360.0f) - 180.0f;
    return (diff < -180.0f) ? diff + 360.0f : diff;
}

// Utility to calculate angle from a direction vector
float Vector2Angle(Vector2 dir) {
    return atan2f(dir.y, dir.x) * RAD2DEG;
}

Vector2 determineMoveDirection() {
    Vector2 moveDirection = {0.0f, 0.0f};
    if (IsKeyDown(KEY_W)) moveDirection.y -= 1.0f;
    if (IsKeyDown(KEY_S)) moveDirection.y += 1.0f;
    if (IsKeyDown(KEY_A)) moveDirection.x -= 1.0f;
    if (IsKeyDown(KEY_D)) moveDirection.x += 1.0f;
    return moveDirection;
}

void Player::moveInDirection(Vector2 moveDirection) {
    // Normalize the direction vector
    float length = sqrtf(moveDirection.x * moveDirection.x + moveDirection.y * moveDirection.y);
    moveDirection.x /= length;
    moveDirection.y /= length;

    // Calculate target rotation from the direction vector
    _targetRotation = Vector2Angle(moveDirection);

    // Move the player in the direction
    _position.x += moveDirection.x * PLAYER_SPEED * GetFrameTime();
    _position.y += moveDirection.y * PLAYER_SPEED * GetFrameTime();
}

void Player::rotate() {
    float angleDiff = AngleDifference(_targetRotation, _rotation);
    float rotationStep = PLAYER_ROT_SPEED * GetFrameTime();
    if (fabsf(angleDiff) < rotationStep) {
        _rotation = _targetRotation;
    } else {
        _rotation += (angleDiff > 0 ? 1 : -1) * rotationStep;
        _rotation = fmodf(_rotation + 360.0f, 360.0f); // Keep rotation in [0, 360)
    }
}

void Player::movement() {
    Vector2 moveDirection = determineMoveDirection();

    if (moveDirection.x != 0 || moveDirection.y != 0) {
        moveInDirection(moveDirection);
    }
    rotate();
} 

void Player::render() {
    Rectangle rectangle = {_position.x, _position.y, PLAYER_SIZE.x, PLAYER_SIZE.y};
    Vector2 pivot = {rectangle.width / 2, rectangle.height / 2};
    DrawRectanglePro(rectangle, pivot, _rotation, RED);
    DrawCircleV({_position.x, _position.y}, 5, YELLOW); // Draw center for debugging
    weapon->render();
}

void Player::destroy() {
    delete this;
}

Player::~Player() {}
