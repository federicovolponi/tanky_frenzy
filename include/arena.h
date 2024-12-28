#ifndef ARENA_H
#define ARENA_H

#include "globals.h"

extern const float ARENA_WIDTH;

// Singleton class to manage the game arena
class Arena : public GameObject {
    public:
        static Arena* Instance();
        virtual void update() override;
        virtual void render() override;
        virtual void destroy() override;
        Rectangle getInternalBorder() const;
        ~Arena();
    protected:
        Arena();
    private:
        static Arena* _instance;
        Rectangle _shape;
};

#endif // !ARENA_H
