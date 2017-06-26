
#ifndef __CC3K__gameobject__
#define __CC3K__gameobject__

#include <stdio.h>
#include "cell.h"

// forward declaration because mutual reference
class Cell;



class GameObject {
    Cell * _location; 
public:
    GameObject();
    int row() const;  // getters
    int col() const;
    Cell * location() const;

    void location(Cell *change); //setters
};


#endif /* defined(__CC3K__gameobject__) */
