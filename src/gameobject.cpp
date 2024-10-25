#include "gameobject.h"

GameObject::GameObject() {
    toDelete = false;
}

bool GameObject::getToDelete() const {
    return toDelete;
}

void GameObject::setToDelete(bool flag) {
    toDelete = flag;
} 
