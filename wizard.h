
#ifndef wizard_h
#define wizard_h

#include <stdio.h>
#include "character.h"
#include <string>

class Wizard : public Character{
    int _GP;        // gold pile, points
    bool _attacked_limit;
    bool _attack_M;
    
public:
    Wizard(); // constructor
    bool move(int i);
    bool use_item(int i);
    bool attack(int i);
    void get_attack(int damage);
    
    std::string name();
    bool attacked_limit();
    bool attack_M();
    
    int GP() const;
    void GP(int i);
    bool is_dead(){return true;}
};

extern bool stopdeath;  // global value for stopdeath


#endif /* wizard_h */
