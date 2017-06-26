
#include "textdisplay.h"

using namespace std;


//Initialize
TextDisplay::TextDisplay():row(25),col(80){
    theDisplay = new char *[row];
        for(int r=0;r<row;r++){
            theDisplay[r] = new char[col];
            for(int c=0;c<col;c++){
                theDisplay[r][c] = 0;
            }
        }
}


//Delete 2D array
TextDisplay::~TextDisplay(){
        for(int r=0;r<row;r++){
            delete[] theDisplay[r];
        }
        delete[] theDisplay;
}


void TextDisplay::notify(int r, int c, char symbol){
    theDisplay[r][c] = symbol;                          //assign array value
}




//print 2D array
void TextDisplay::print(){
    for(int r=0; r < row ; r++){
        for(int c = 0; c < col; c++){
            cout<<theDisplay[r][c];
        }
    }
}

