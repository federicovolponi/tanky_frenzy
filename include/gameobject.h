#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
    public:
        GameObject();
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void destroy() = 0;
        bool getToDelete() const;
        void setToDelete(bool flag); //FIXME: make it accessible by derived classes only
        ~GameObject() = default;
    private:
        bool toDelete;
};

#endif
