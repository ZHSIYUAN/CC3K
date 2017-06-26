
#ifndef orc_h
#define orc_h

#include <stdio.h>
#include "character.h"
#include <string>


class Orc : public Character{
    bool _is_dead;
public:
    Orc();
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

extern bool stopwander;







#endif /* orc_h */
