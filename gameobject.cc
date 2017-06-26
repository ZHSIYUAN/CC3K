
#include "gameobject.h"

using namespace std;





GameObject::GameObject() : _location(NULL) {}

int GameObject::row() const{
    return _location->row();
};                              // getters
int GameObject::col() const{
    return _location->col();
};

Cell * GameObject::location() const{
    return _location;
}

void GameObject::location(Cell *change) {
    _location = change;
}
