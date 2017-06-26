//
//  potion.cc
//  CC3K
//
//  Created by Charlie Ma on 2016-03-24.
//  Copyright (c) 2016 Yuanpei Ma. All rights reserved.
//

#include "potion.h"

using namespace std;

Potion::Potion(int row, int col, int floor, int i):Item(row,col,floor,i){
    if(i == 0){
        _HP_effect = 30;
    }else if(i == 1){
        _Atk_effect = 10;
    }else if(i == 2){
        _Def_effect = 10;
    }else if(i == 3){
        _HP_effect = -15;
    }else if(i == 4){
        _Atk_effect = -5;
    }else if(i == 5){
        _Def_effect = -5;
    }
    
}

int Potion::HP_effect() const {
    return _HP_effect;
}

int Potion::Atk_effect() const {
    return _Atk_effect;
}
int Potion::Def_effect() const {
    return _Def_effect;
}