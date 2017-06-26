//
//  potion.h
//  CC3K
//
//  Created by Charlie Ma on 2016-03-24.
//  Copyright (c) 2016 Yuanpei Ma. All rights reserved.
//

#ifndef __CC3K__potion__
#define __CC3K__potion__

#include <stdio.h>
#include "item.h"


class Potion : public Item{
    int _HP_effect;
    int _Atk_effect;
    int _Def_effect;
    
public:
    Potion(int row, int col, int floor, int i);
    int HP_effect() const;
    int Atk_effect() const;
    int Def_effect() const;
    
    
};


#endif /* defined(__CC3K__potion__) */
