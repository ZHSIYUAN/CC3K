

#ifndef goblin_h
#define goblin_h

#include <stdio.h>
#include "character.h"
#include <string>


class Goblin : public Character{
    bool _is_dead;
public:
    Goblin();
    std::string name();
    bool move(int i);
    bool attack(int i);
    void get_attack(int damage);
    bool use_item(int i);
    
    bool is_dead();   // determin death from outside
    bool swap_item(); // replace it with item
    
    bool attacked_limit() {return true;}
    bool attack_M() {return true;}
    int GP() const {return 0;}
};


extern bool stopwander; // globle value of stopwander command




#endif /* goblin_h */
