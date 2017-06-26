
#ifndef __CC3K__game__
#define __CC3K__game__

#include <stdio.h>
#include "cell.h"
#include "textdisplay.h"
#include "PRNG.h"
#include <string>
#include <iomanip>
#include "character.h"
#include "gameobject.h"
#include "wizard.h"
#include "knight.h"
#include "samurai.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "goblin.h"
#include "bug.h"
#include "item.h"


extern PRNG prng;
extern int floor;
extern int turn;

class Game {
    int player_chamber = -1;   //default value is -1
    Cell ** grid;              // 2D matrix for cells
    const int row;             // position
    const int col;
    TextDisplay * display;     // textdisplay
    Character *MonsterStack[20];// array of Monsters
    
public:
    Character *Player;          // pointer of player
    void refreshPlayer();       // update the player and put it in matrix
    Game();                     // constructor
    void spawnPlayer(std::string); // initialize and place the player in matrix
    void spawnEnemy(int i, int j); // randomly place an enemy in matrix
    void spawnGold(int j);         // randomly place gold piles in matrix
    void spawnPotion(int j);       // randomly place potions in matrix
    void spawnStair();             // randomly place a stair in matrix
    void spawnEverything();        // place all enemys, items and a stair in matrix
    void auto_move(Character *enemy); // an enemy moves for one step
    void moveEverything();         // all enemy move for one step
    
    void deleteEverything();       // delete all enemys and items from matrix
    
    ~Game();                      // destructor
    void print();                 // print out the matrix
};



#endif /* defined(__CC3K__game__) */
