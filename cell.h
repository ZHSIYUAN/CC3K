
#ifndef __CC3K__cell__
#define __CC3K__cell__

#include "textdisplay.h"
#include "gameobject.h"


static const int MAX_NEIGHBOURS = 8;


class GameObject; // forward decalaration

class Cell{
    static TextDisplay * _display; // a static textdisplay 
    Cell* _neighbours[MAX_NEIGHBOURS]; // array which stores neighbours of this cell
    
    int _row; // position of this cell
    int _col;
    
    char _symbol; // symbol of this cell in map
    char _initSymbol; // original symbol of this cell in map
    int _chamber; // chamber number of this cell
    
    GameObject *_contents; // gameobjects in this cell
    bool _occupied;        // determine if this cell is occupied
    bool _is_player = false; // determine if this cell is a player
    bool _is_enemy = false;  // determine if this cell is an enemy
    bool _is_item = false;   // determine if this cell is an item
    
public:
    Cell(); // constructor
    ~Cell(){}  // destructor
    
    
    void notifyDisplay();  // announce textdisplay to change
    void intepret(char c); // set char
    
    
    //getter
    GameObject * contents() const; // return gameobject in this cell
    char symbol() const;           // return symbol in this cell
    int chamber() const;           // return chamber number of this cell
    bool is_occupied() const;      // return true if this cell is occupied
    int row()const;                // position of this cell
    int col()const;
    Cell * get_ith_Neighbour(int i); // return ith neighbour of this cell
    bool is_item()const;           // return true if this cell is an item
    bool is_character()const;      // return true if this cell is an character
    bool is_enemy()const;          // return true if this cell is an enemy
    bool is_player()const;         // return true if this cell is a player
    
    //setter
    void setSymbol(char change);   // set symbol of this cell
    void resetSymbol();            // reset to original symbol
    void setCoords(int row, int col); // set row and column of this cell
    void setOccupied();            // reset is_occupied
    void setContents(GameObject * contents); // set content
    void setEnemy();               // reset is_enemy
    void setPlayer();              // reset is_player
    void setItem();                // reset is_item

    
    
    static void addDisplay(TextDisplay* dis);
    void addNeighbour(int index, Cell * ngh = NULL);
};


#endif /* defined(__CC3K__cell__) */
