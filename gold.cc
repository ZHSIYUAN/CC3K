//
//  gold.cc
//  CC3K
//
//  Created by Charlie Ma on 2016-03-24.
//  Copyright (c) 2016 Yuanpei Ma. All rights reserved.
//

#include "gold.h"

using namespace std;


Gold::Gold(int row, int col, int floor, int i):Item(row,col,floor,i){
    if(i == 6){
        _GP_effect = 10;
    }else if(i == 7){
        _GP_effect = 50;
    }
    
}

int Gold::GP_effect() const {
    return _GP_effect;
}