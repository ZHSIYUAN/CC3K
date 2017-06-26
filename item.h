
#ifndef __CC3K__item__
#define __CC3K__item__

#include <stdio.h>
#include "gameobject.h"


class Item : public GameObject{
    int _id;    // ID for 8 different items
    
public:
    Item(int id);
    int getid()const;
};

#endif /* defined(__CC3K__item__) */
