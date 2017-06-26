
#include "orc.h"
#include <iostream>
#include <string>
using namespace std;

Orc::Orc():Character(120,30,30), _is_dead(false) {
} // not dead at the beginning

string Orc::name() {
    return "orc";
}

bool Orc::move(int i){
    if (swap_item()) {
        return true;
    }
    
    
    
    int chamber_num = Character::GameObject::location()->chamber();
    
    
    if (attack(0)) {   // check if there is player around it, and attack it
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
        if (stopwander) return true;  // if received stopwander command
        Cell * current_cell = Character::GameObject::location();
        Cell * target_cell = Character::GameObject::location()->get_ith_Neighbour(i);
        
        if (target_cell == NULL) return false; // check NULL pointer
        
        int target_chamber = target_cell->chamber();
       
        GameObject * obj =
        Character::GameObject::location()->contents();
        
        if(target_cell->is_occupied()){
            return false;
        } else if (target_chamber != chamber_num) {
            return false;
        } else {
            current_cell->setContents(NULL); // reset current cell
            current_cell->setOccupied();
            char sym = current_cell->symbol();
            current_cell->resetSymbol();
            current_cell->setEnemy();
            
            target_cell->setContents(obj);  // set target cell
            target_cell->setOccupied();
            target_cell->setSymbol(sym);
            target_cell->setEnemy();
            Character::GameObject::location(target_cell);
            return true;
        }
    }
}


bool Orc::attack(int i) {
    Cell * target_cell =
    Character::GameObject::location()->get_ith_Neighbour(i);
    
    if (target_cell == NULL) return false; // check null pointer
    
    
    string enemy_name = "Orc";
    
    if (target_cell->is_player()) {
        Character * player = (Character *) target_cell->contents();
        if (player->attacked_limit()) {
            int damage_get = (this->Atk() * (100 - player->Def())) / 100; // attack to player
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

void Orc::get_attack(int damage) {
    HP(-damage);
}

bool Orc::is_dead() {
    return _is_dead;
}


bool Orc::swap_item() { // if orc is dead, use gold pile to replace it
    if (HP() == 0) {
        Cell * current_cell = Character::GameObject::location();
        current_cell->setEnemy();
        current_cell->setItem();
        current_cell->setSymbol('$'); // reset symbol
        
        Item *drop_item = new Item(6);
        current_cell->setContents(drop_item);
        _is_dead = true;
        cout << "The Orc has died." << endl; // print out information
        return true;
    } else {
        return false;
    }
}



