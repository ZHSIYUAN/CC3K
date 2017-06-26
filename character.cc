
#include "character.h"
using namespace std;


Character::Character(int hp, int atk, int def) : GameObject(), _HP(hp),_MaxHP(hp), _oriAtk(atk), _oriDef(def),_Atk(atk),_Def(def) {} // constructor



int Character::HP() const{
    return _HP;
}

int Character::MaxHP() const{
    return _MaxHP;
}

int Character::Atk() const {
    return _Atk;
}

int Character::Def() const {
    return _Def;
}

void Character::HP(int i){
    _HP += i;
    if(_HP > _MaxHP) _HP = _MaxHP; // HP should not exceed max_HP
    if(_HP <=0) _HP = 0; // HP should not less than 0
};

void Character::Atk(int i){
    _Atk += i;
    if (_Atk < 0) _Atk = 0; // attack should not less than 0
};

void Character::Def(int i){
    _Def += i;
    if (_Def < 0) _Def = 0; // defence should not less than 0
    if (_Def > 100) _Def = 100; // defence should not exceed 100
};


void Character::refresh() {
    _Atk = _oriAtk; // reset attack
    _Def = _oriDef; // reset defence
}
