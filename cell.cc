

#include "cell.h"

using namespace std;

TextDisplay * Cell::_display = NULL; // decalare the textdisplay


Cell::Cell() {
    _chamber = -1;
}



//getter
int Cell::chamber() const{return _chamber;}

GameObject * Cell::contents() const{ // return GameObject
    return _contents;
};



char Cell::symbol() const{return _symbol;}

bool Cell::is_occupied()const{return _occupied;}

int Cell::row()const{return _row;}

int Cell::col()const{return _col;}


Cell *Cell::get_ith_Neighbour(int i){return _neighbours[i];}



bool Cell::is_character()const{ // check symbol of this cell
    if(_symbol == '@' || _symbol == 'X' || _symbol == 'g' || _symbol == 'M' || _symbol == 'O' || _symbol == 'D') return 1;
    else return 0;
}

bool Cell::is_enemy()const{
    return _is_enemy;
}

bool Cell::is_player()const{
    return _is_player;
}

bool Cell::is_item()const{
    return _is_item;
}

//setter
void Cell::setSymbol(char change){
    _symbol = change;
    _display->notify(_row, _col, change);
}

void Cell::resetSymbol(){
    _symbol = _initSymbol;
    _display->notify(_row, _col, _initSymbol);
}

void Cell::setCoords(int r, int c){
    _row = r;
    _col = c;
};

void Cell::setOccupied(){
    _occupied = !_occupied;
}

void Cell::setContents(GameObject * contents){
    _contents = contents;
}


void Cell::addNeighbour(int index, Cell * neighbour){
    _neighbours[index] = neighbour;            //add neighbour
}

void Cell::addDisplay(TextDisplay* display){
    _display = display;
}

void Cell::intepret(char c){  // set the symbol and character of cells
    if(c == '|' || c == '\n' || c == ' ' || c == '-'){
        _symbol = c;
        _initSymbol = c;
        _occupied = 1;
        
    }else if( c >= '0' && c <= '4'){
        _chamber = c - '0';
        _initSymbol = '.';
        _symbol = '.';
    }
    else{
        _symbol = c;
        _initSymbol = c;
    }
}




// redo

void Cell::setEnemy(){ 
    _is_enemy = !_is_enemy;
}

void Cell::setPlayer(){
    _is_player = !_is_player;
}


void Cell::setItem() {
    _is_item = !_is_item;
}
// void Cell::setItem();

void Cell::notifyDisplay() {  // notify textdisplay the changes
    _display->notify(_row, _col, _symbol);
}









