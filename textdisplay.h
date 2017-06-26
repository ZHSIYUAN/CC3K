

#ifndef __CC3K__textdisplay__
#define __CC3K__textdisplay__

#include <iostream>
#include <sstream>

class TextDisplay {
    char **theDisplay; // 2D map matrix
    const int row;
    const int col;



public:
    TextDisplay();  // constructor
    ~TextDisplay(); // destructor
    void notify(int r, int c, char symbol); // change char in unique position
    void print(); // print out map
};


#endif /* defined(__CC3K__textdisplay__) */
