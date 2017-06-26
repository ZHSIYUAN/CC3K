
#include "goblin.h"
#include <iostream>
#include <string>
using namespace std;

Goblin::Goblin():Character(75,30,20), _is_dead(false) {
}

string Goblin::name() {
    return "goblin";
}



bool Goblin::move(int i){
    if (swap_item()) {
        return true;
    }
    
    int chamber_num = Character::GameObject::location()->chamber();
    
    
    if (attack(0)) {   // check if there is player around it and attack
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
    } else if (use_item(0)) { // check if there is any potion arround it, pick it up
        return true;
    } else if (use_item(1)) {
        return true;
    } else if (use_item(2)) {
        return true;
    } else if (use_item(3)) {
        return true;
    } else if (use_item(4)) {
        return true;
    } else if (use_item(5)) {
        return true;
    } else if (use_item(6)) {
        return true;
    } else if (use_item(7)) {
        return true;
    } else {
        if (stopwander) return true;
        Cell * current_cell = Character::GameObject::location();
        Cell * target_cell = Character::GameObject::location()->get_ith_Neighbour(i);
        
        if (target_cell == NULL) return false; // check NULL pointer
        
        int target_chamber = target_cell->chamber();
        
        GameObject * obj =
        Character::GameObject::location()->contents();
        
        if(target_cell->is_occupied()){ // occupied cell, could not move
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




bool Goblin::use_item(int i) {
    
    Cell * target_cell = Character::GameObject::location()->get_ith_Neighbour(i);
    
    if (target_cell == NULL) { // check NULL pointer
        return false;
    }
    
    if (target_cell->is_item()) {
        Item *target = (Item *) target_cell->contents();
        int ID = target->getid(); // only pick up potion
        if (ID == 0) {
            this->HP(30);
        } else if (ID == 1) {
            this->Atk(10);
        } else if (ID == 2) {
            this->Def(10);
        } else if (ID == 3) {
            this->HP(-15);
        } else if (ID == 4) {
            this->Atk(-5);
        } else if (ID == 5) {
            this->Def(-5);
        }  else {
            return false;
        }
        delete target;
        target_cell->setContents(NULL); // reset the target cell
        target_cell->setOccupied();
        target_cell->setItem();
        // is_item() in cell
        target_cell->resetSymbol();
        return true;
    } else {
        return false;
    }
}


bool Goblin::attack(int i) {
    Cell * target_cell =
    Character::GameObject::location()->get_ith_Neighbour(i);
    
    if (target_cell == NULL) return false; // check null pointer
    
    
    string enemy_name = "Goblin";
    
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



void Goblin::get_attack(int damage) {
    HP(-damage);
}

bool Goblin::is_dead() {
    return _is_dead;
}


bool Goblin::swap_item() { // when goblin is dead, replace it with gold pile
    if (HP() == 0) {
        Cell * current_cell = Character::GameObject::location();
        current_cell->setEnemy();
        current_cell->setItem();
        current_cell->setSymbol('$');
        
        Item *drop_item = new Item(6);
        current_cell->setContents(drop_item);
        _is_dead = true;
        cout << "The Goblin has died." << endl;
        return true;
    } else {
        return false;
    }
}











