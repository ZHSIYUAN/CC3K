
#include "wizard.h"
#include <string>
using namespace std;

Wizard::Wizard():Character(60,25,0), _GP(0), _attacked_limit(true), _attack_M(false) {
}


string Wizard::name() {
    return "Wizard";
}


int Wizard::GP() const {
    return _GP;
}

void Wizard::GP(int i) {
    _GP = _GP + i;
}

bool Wizard::move(int i) {
    Cell * current_cell = Character::GameObject::location();
    Cell * target_cell = Character::GameObject::location()->get_ith_Neighbour(i);
    
    if (target_cell == NULL) { // invalid cell
        cout << "You can't move in that direction." << endl;
        return false;
    }
    
    GameObject * obj = Character::GameObject::location()->contents();
    if(target_cell->is_occupied()){
        if(target_cell->symbol() == '$'){  // use glod pile instead of moving
            HP(5); // plus 5 HP
            use_item(i);
            return true;
        } else if (target_cell->symbol() == '>') {
            HP(5);
            throw 100; // catch in main function
        } else {                                      //is Gold
            cout << "You can't move in that direction." << endl;
            return false;
        }
    } else {
        HP(5);
        current_cell->setContents(NULL); // replace current cell
        current_cell->setOccupied();
        char sym = current_cell->symbol();
        current_cell->resetSymbol();
        current_cell->setPlayer();
        
        target_cell->setContents(obj);  // set target cell
        target_cell->setOccupied();
        target_cell->setSymbol(sym);
        target_cell->setPlayer();
        
        Character::GameObject::location(target_cell);
        
        if (i == 0) {
            cout << "You move north-west." << endl;
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

bool Wizard::use_item(int i) {
    Cell * target_cell = Character::GameObject::location()->get_ith_Neighbour(i);
    
    if (target_cell == NULL) { // check NULL pointer
        cout << "There is nothing there to use!" << endl;
        return false;
    }
    
    if (target_cell->is_item()) {
        HP(5); // plus 5 HP
        Item *target = (Item *) target_cell->contents();
        int ID = target->getid(); // determine the type of item
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
            if (HP() == 0 && !stopdeath) throw 200; // if player is dead, throw 200 to main
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
        target_cell->resetSymbol();    // memory leak????
        return true;
    } else {
        cout << "There is nothing there to use!" << endl;
        return false;
    }
}


bool Wizard::attack(int i) {
    bool attack_success = false;
    Cell *target_cell = Character::GameObject::location()->get_ith_Neighbour(i);
    if (target_cell == NULL) {  // check NULL pointer
        cerr << "There is nothing there to attack!" << endl;
        return attack_success;
    }
    for (;;) {
        if (target_cell->is_enemy()) {
            HP(5);
            Character * enemy = (Character *) target_cell->contents();
            string enemy_name = enemy->name(); // recursively check cells until find enemy
            
            int damage_to = (this->Atk() * (100 - enemy->Def()))/100;
            enemy->get_attack(damage_to);
            if (enemy_name == "merchant") {
                cout << "This is an act of war to every Merchant!" << endl;
                _attack_M = true;
            }
            cerr << "You attack the " << enemy_name <<" with your Infinite Loop Laser for "
            << damage_to << " damage!" << endl;
            attack_success = true;
            break;
        } else if (target_cell->symbol() == '|' || target_cell->symbol() == '-'
                   || target_cell->symbol() == '+' || target_cell->symbol() == '#'){
            cerr << "There is nothing there to attack!" << endl; // cannot attack through walls
            break;
        } else {
            target_cell = target_cell->get_ith_Neighbour(i);
        }
    }
    return attack_success;
}

void Wizard::get_attack(int damage) {
    HP(-damage);
}

bool Wizard::attacked_limit() {
    return _attacked_limit;
}

bool Wizard::attack_M() {
    return _attack_M;
}