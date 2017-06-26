
#include "knight.h"
#include <string>
using namespace std;


Knight::Knight(): Character(100,50,50), _GP(0), _attacked_limit(true), _attack_M(false) {
}

string Knight::name() {
    return "Knight";
}


int Knight::GP() const {
    return _GP;
}

void Knight::GP(int i) {
    _GP = _GP + i;
}




bool Knight::move(int i){
    Cell * current_cell = Character::GameObject::location();
    Cell * target_cell = Character::GameObject::location()->get_ith_Neighbour(i);
    
    if (target_cell == NULL) {  // if target_cell is NULL
        cout << "You can't move in that direction." << endl;
        return false;
    }
    
    GameObject * obj = Character::GameObject::location()->contents();
    if(target_cell->is_occupied()){
        if(target_cell->symbol() == '$'){ // gold pile, use it
            HP(5); // plus 5 HP every move
            use_item(i);
            return true;
        } else if (target_cell->symbol() == '>') { // stair, throw 100 to main
            HP(5);
            throw 100; // catch in main function
        } else {                                      //is Gold
            cout << "You can't move in that direction." << endl;
            return false;
        }
    } else {
        HP(5);
        current_cell->setContents(NULL);
        current_cell->setOccupied();
        char sym = current_cell->symbol();
        current_cell->resetSymbol();
        current_cell->setPlayer();
        
        target_cell->setContents(obj);
        target_cell->setOccupied();
        target_cell->setSymbol(sym);
        target_cell->setPlayer();
        
        Character::GameObject::location(target_cell);
        
        if (i == 0) {
            cout << "You move north-west." << endl;  // cout some information
        } else if (i == 1) {
            cout << "You move north." << endl;
        } else if (i == 2) {
            cout << "You move north-east." << endl;
        } else if (i == 3) {
            cout << "You move west." << endl;
        } else if (i == 4) {
            cout << "You move east." << endl;
        } else if (i == 5) {
            cout << "You move south-west." << endl;
        } else if (i == 6) {
            cout << "You move south." << endl;
        } else {
            cout << "You move south-east." << endl;
        }
        return true;
    }
}


bool Knight::use_item(int i) {
    
    Cell * target_cell = Character::GameObject::location()->get_ith_Neighbour(i);
    
    if (target_cell == NULL) { // check NULL pointer
        cout << "There is nothing there to use!" << endl;
        return false;
    }
    
    if (target_cell->is_item()) {
        HP(5); // add 5 HP
        Item *target = (Item *) target_cell->contents();
        int ID = target->getid();
        if (ID == 0) {
            this->HP(30);
            //  delete use
            cout << "You chug the Restore Health potion." << endl;
        } else if (ID == 1) {
            this->Atk(10);
            cout << "You chug the Boost Attack potion." << endl;
        } else if (ID == 2) {
            this->Def(10);
            cout << "You chug the Boost Defence potion." << endl;
        } else if (ID == 3) {
            this->HP(-15);
            cout << "You chug the Poison Health potion." << endl;
            if (HP() == 0 && !stopdeath) throw 200;  // if player is dead, throw 200 to main
        } else if (ID == 4) {
            this->Atk(-5);
            cout << "You chug the Wound Attack potion." << endl;
        } else if (ID == 5) {
            this->Def(-5);
            cout << "You chug the Wound Defence potion." << endl;
        } else if (ID == 6){
            this->GP(10);
            cout << "You pick up the Gold Pile worth 10GP." << endl;
        } else {
            // check dragon around it
            
            this->GP(50);
            cout << "You successfully take the Dragon Hoard!" << endl;
        }
        
        delete target;
        target_cell->setContents(NULL); // reset the target cell
        target_cell->setOccupied();
        target_cell->setItem();
        // is_item() in cell
        target_cell->resetSymbol();    // reset symbol to original one
        return true;
    } else {
        cout << "There is nothing there to use!" << endl;
        return false;
    }
}


bool Knight::attack(int i) {
    Cell * target_cell =
    Character::GameObject::location()->get_ith_Neighbour(i);
    
    if (target_cell == NULL) {  // check NULL pointer
        cout << "There is nothing there to attack!" << endl;
        return false;
    }
    
    if (target_cell->is_enemy()) {
        HP(5); // add 5 HP
        Character * enemy = (Character *) target_cell->contents();
        string enemy_name = enemy->name();
        
        int damage_to = (this->Atk() * (100 - enemy->Def()))/100;
        enemy->get_attack(damage_to); // damage to enemy
        if (enemy_name == "merchant") {
            cout << "This is an act of war to every Merchant!" << endl;
            _attack_M = true;
        }
        cout << "You attack the " << enemy_name <<" with your Sword of Segfault for "
        << damage_to << " damage!" << endl;
        
        
        return true;
    } else {
        cout << "There is nothing there to attack!" << endl; // invalid attack target
        return false;
    }
}

void Knight::get_attack(int damage) {
    HP(-damage);
}

bool Knight::attacked_limit() {
    return _attacked_limit;
}

bool Knight::attack_M() {
    return _attack_M;
}






