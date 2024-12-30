#ifndef ARENA_H
#define ARENA_H

#include "globals.h"
#include <raylib.h>

extern const float ARENA_WIDTH;

// Singleton class to manage the game arena
class Arena : public GameObject {
    public:
        static Arena* Instance();
        virtual void update() override;
        virtual void render() override;
        virtual void destroy() override;
        void handlePlayerCollision(Vector2& playerPosition, Vector2 playerSize);
        bool checkBulletCollision(Vector2 bulletPosition, int bulletSize);
        ~Arena();
    private:
        Arena();
        static Arena* _instance;
        Rectangle _boundary;
        Rectangle getInternalBorder() const;
};

#endif // !ARENA_H
