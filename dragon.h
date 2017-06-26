
#ifndef dragon_h
#define dragon_h

#include <stdio.h>
#include "character.h"
#include <string>


class Dragon : public Character{
    bool _is_dead;
public:
    Dragon();
    std::string name();
    bool move(int i);
    bool attack(int i);
    void get_attack(int damage);
    
    bool is_dead();   // determin death from outside
    bool swap_item(); // replace it with item
    
    bool attacked_limit() {return true;}
    bool attack_M() {return true;}
    bool use_item(int i) {return true;}
    int GP() const {return 0;}
};





#endif /* dragon_h */
