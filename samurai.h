#ifndef samurai_h
#define samurai_h

#include <stdio.h>
#include "character.h"
#include <string>

class Samurai : public Character{
    int _GP;
    bool _attacked_limit; // if true, can be attacked, otherwise, can't
    bool _attack_M;       // if true, player has attacked merchant
public:
    Samurai();
    bool move(int i);
    bool use_item(int i);
    bool attack(int i);
    
    std::string name();
    bool attacked_limit();
    bool attack_M();
    
    void get_attack(int damage);
    int GP() const;
    void GP(int i);
    bool is_dead() {return true;}
};

extern bool stopdeath;

#endif /* samurai_h */
