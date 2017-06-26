
#ifndef __CC3K__knight__
#define __CC3K__knight__

#include <stdio.h>
#include "character.h"
#include <string>

class Knight : public Character{
    int _GP;
    bool _attacked_limit; // if true, can be attacked, otherwise, can't
    bool _attack_M; // if true, merchant can attack player
public:
    Knight(); // constructor
    bool move(int i);     // explained in charactr.h
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

extern bool stopdeath;  // globle value of stopdeath command

#endif /* defined(__CC3K__knight__) */
