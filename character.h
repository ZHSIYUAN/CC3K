#ifndef CHARACTER_H
#define CHARACTER_H
#include "gameobject.h"
#include <string>
#include "item.h"

class Character : public GameObject {
    int _HP;
    const int _MaxHP;
    int _oriAtk;
    int _oriDef;
    int _Atk;
    int _Def;
    
public:
    Character(int hp, int atk, int def);
    virtual ~Character(){}
    //getter
    int HP() const; // return current HP
    int Atk() const; // return current attack
    int Def() const; // return current defence
    int MaxHP() const; // return maximum HP
    //setter
    void HP(int i); // add HP
    void Atk(int i); // add attack
    void Def(int i); // add defence
    void refresh(); // refresh players 
    
    //pure virtual
    virtual bool is_dead() = 0; // determine if character is dead
    virtual bool move(int i) = 0;   // character move to one direction
    virtual bool attack(int i) = 0; // character move to one direction
    virtual bool use_item(int i) = 0; // character pick up an item in
    virtual void get_attack(int damage) = 0; // character get damage
    virtual bool attacked_limit() = 0; // determin if character could be attacked
    virtual bool attack_M() = 0; // if player has attacked Merchant, return true;
    virtual int GP() const = 0;  // return player's gold
    virtual std::string name() = 0; // return player's name
    
};

#endif