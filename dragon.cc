
#include "dragon.h"

#include <iostream>
#include <string>
using namespace std;

Dragon::Dragon(): Character(150,50,10), _is_dead(false) {
}

string Dragon::name() {
    return "dragon";
}

bool Dragon::move(int i){
    
    if (swap_item()) { // if dragon died, swap it with necessary information
        return true;
    }
    
    
    if (attack(0)) {   // check if there is player around it, and attack
        return true;
    } else if (attack(1)) {
        return true;
    } else if (attack(2)) {
        return true;
    } else if (attack(3)) {
        return true;
    } else if (attack(4)) {
        return true;
    } else if (attack(5)) {
        return true;
    } else if (attack(6)) {
        return true;
    } else if (attack(7)) {
        return true;
    } else {
        return true;
    }
}


bool Dragon::attack(int i) {
    Cell * target_cell =
    Character::GameObject::location()->get_ith_Neighbour(i);
    
    if (target_cell == NULL) return false; // check null pointer
    
    
    string enemy_name = "Dragon";
    
    if (target_cell->is_player()) {
        Character * player = (Character *) target_cell->contents();
        if (player->attacked_limit()) {
            int damage_get =
            (this->Atk() * (100 - player->Def())) / 100; // damage to player
            player->get_attack(damage_get);
            cout << "The evil " << enemy_name << " strikes you for " << damage_get << " damage!" << endl;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}



void Dragon::get_attack(int damage) {
    HP(-damage);
}

bool Dragon::is_dead() {
    return _is_dead;
}


bool Dragon::swap_item() { // when dragon died, it does not drop anything
    if (HP() == 0) {
        Cell * current_cell = Character::GameObject::location();
        
        current_cell->setOccupied();
        current_cell->setEnemy();
        current_cell->resetSymbol();
        current_cell->setContents(NULL);
        
        _is_dead = true;
        cout << "The Dragon has died." << endl;
        
        return true;
    } else {
        return false;
    }
}
















