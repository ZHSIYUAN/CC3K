//
//  gold.h
//  CC3K
//
//  Created by Charlie Ma on 2016-03-24.
//  Copyright (c) 2016 Yuanpei Ma. All rights reserved.
//

#ifndef __CC3K__gold__
#define __CC3K__gold__

#include <stdio.h>
#include "item.h"


class Gold : public Item{
    int _GP_effect;
    
public:
    Gold(int row, int col, int floor, int i);
    int GP_effect() const;
    
    
};

#endif /* defined(__CC3K__gold__) */
