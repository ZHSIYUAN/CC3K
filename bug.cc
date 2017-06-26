
#include "bug.h"
#include <iostream>
#include <string>
using namespace std;

Grid_Bug::Grid_Bug(): Character(50,20,10), _is_dead(false) {
}

string Grid_Bug::name() {
    return "grid_bug";
}

bool Grid_Bug::move(int i){
    if (swap_item()) {
        return true;
    }
    
    
    if (i == 0 || i == 3) { // replace the 8 direction with only four directions
        i = 3;
    } else if (i == 1 || i == 2) {
        i = 1;
    } else if (i == 4 || i == 7) {
        i = 4;
    } else {
        i = 6;
    }
    
    int chamber_num = Character::GameObject::location()->chamber();
    
    
    if (attack(3)) {   // check if there is player around it and attack if necessary
        return true;
    } else if (attack(1)) {
        return true;
    } else if (attack(4)) {
        return true;
    } else if (attack(6)) {
        return true;
    } else {
        if (stopwander) return true; // stop moving permanamtely
        Cell * current_cell = Character::GameObject::location();
        Cell * target_cell = Character::GameObject::location()->get_ith_Neighbour(i);
        
        if (target_cell == NULL) return false; // check NULL pointer
        
        int target_chamber = target_cell->chamber();
        
        GameObject * obj =
        Character::GameObject::location()->contents();
        
        if(target_cell->is_occupied()){ // occupied target cell, could not move
            return false;
        } else if (target_chamber != chamber_num) {
            return false;
        } else {
            current_cell->setContents(NULL);
            current_cell->setOccupied();
            char sym = current_cell->symbol();
            current_cell->resetSymbol();
            current_cell->setEnemy();
            
            target_cell->setContents(obj);
            target_cell->setOccupied();
            target_cell->setSymbol(sym);
            target_cell->setEnemy();
            Character::GameObject::location(target_cell);
            return true;
        }
    }
}


bool Grid_Bug::attack(int i) {
    Cell * target_cell =
    Character::GameObject::location()->get_ith_Neighbour(i);
    
    if (target_cell == NULL) return false; // check null pointer
    
    
    string enemy_name = "Gird Bug";
    
    if (target_cell->is_player()) {
        Character * player = (Character *) target_cell->contents();
        if (player->attacked_limit()) {
            int damage_get =
            (this->Atk() * (100 - player->Def())) / 100; // attack to player
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

void Grid_Bug::get_attack(int damage) {
    HP(-damage);
}

bool Grid_Bug::is_dead() {
    return _is_dead;
}


bool Grid_Bug::swap_item() { // when grid bug died, replacce it with random potion
    if (HP() == 0) {
        Cell * current_cell = Character::GameObject::location();
        current_cell->setEnemy();
        current_cell->setItem();
        current_cell->setSymbol('!');
        
        int i = prng(5);
        Item *drop_item = new Item(i);
        current_cell->setContents(drop_item);
        _is_dead = true;
        cout << "The Grid Bug has died." << endl;
        return true;
    } else {
        return false;
    }
}

