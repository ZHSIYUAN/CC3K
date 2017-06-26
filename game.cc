
#include <iostream>
#include <fstream>
#include "game.h"
#include "textdisplay.h"
#include <string>
using namespace std;



Game::Game():row(25),col(80){//Game constructor
    display = new TextDisplay();
    Cell::addDisplay(display);
   
    
    
    std::ifstream in("map.cc"); // read map form a file
    
    char temp = 0;
    grid = new Cell* [row]; 
    for(int r=0;r < row;r++){ //  creat a cell matrix
        grid[r] = new Cell [col];
        for(int c=0; c < col;c++){
            in.read(&temp,1);
            grid[r][c].setCoords(r, c);
            grid[r][c].intepret(temp);
            grid[r][c].notifyDisplay();
        }
    }//for
    
    
    
   for(int r=0;r<row;r++){ // add neighbours to each cell
        for(int c=0;c<col;c++){
            if(r != 0 && c !=0){
                grid[r][c].addNeighbour(0,&(grid[r-1][c-1]));
            }else{
                grid[r][c].addNeighbour(0);
            }
            if(r != 0){
                grid[r][c].addNeighbour(1,&(grid[r-1][c]));
            }else{
                grid[r][c].addNeighbour(1);
            }
            if(r != 0 && c != col-1){
                grid[r][c].addNeighbour(2,&(grid[r-1][c+1]));
            }else{
                grid[r][c].addNeighbour(2);
            }
            if(c != 0){
                grid[r][c].addNeighbour(3, &(grid[r][c-1]));
            }else{
                grid[r][c].addNeighbour(3);
            }
            if(c != col-1){
                grid[r][c].addNeighbour(4,&(grid[r][c+1]));
            }else{
                grid[r][c].addNeighbour(4);
            }
            if(r != row-1 && c !=0 ){
                grid[r][c].addNeighbour(5,&(grid[r+1][c-1]));
            }else{
                grid[r][c].addNeighbour(5);
            }
            if(r != row-1){
                grid[r][c].addNeighbour(6,&(grid[r+1][c]));
            }else{
                grid[r][c].addNeighbour(6);
            }
            if(r != row-1 && c != col-1){
                grid[r][c].addNeighbour(7,&(grid[r+1][c+1]));
            }else{
                grid[r][c].addNeighbour(7);
            }
        }//for
    
    }//for
    
    
}
    
    




Game::~Game(){ // destructor
    delete Player;
    deleteEverything();
    for(int r=0;r<row;r++){
            delete[] grid[r];
        }
    delete[] grid;
    delete display;
}


void Game::spawnPlayer(std::string s){
    for(;;){
        int row_random = prng(24);  // get random position
        int col_random = prng(79);
        if (grid[row_random][col_random].symbol() == '.'){
            Cell *target_cell = &(grid[row_random][col_random]);
            if( s == "w"){
                Player = new Wizard(); // initialize a wizard
                //Player = Hero;
                Player->location(target_cell);
                target_cell->setSymbol('@');
                target_cell->setContents(Player);
                target_cell->setOccupied();
                target_cell->setPlayer();
                player_chamber = target_cell->chamber();
                cout<<"You have chosen to play as a Wizard. Good luck."<<endl;
            } else if (s == "k") {
                Character * Hero = new Knight(); // initialize a knight
                Player = Hero;
                Hero->location(target_cell);
                target_cell->setSymbol('@');
                target_cell->setContents(Hero);
                target_cell->setOccupied();
                target_cell->setPlayer();
                player_chamber = target_cell->chamber();
                cout<<"You have chosen to play as a Knight. Good luck."<<endl;
            } else {
                Character * Hero = new Samurai(); // initialize a samurai
                Player = Hero;
                Hero->location(target_cell);
                target_cell->setSymbol('@');
                target_cell->setContents(Hero);
                target_cell->setOccupied();
                target_cell->setPlayer();
                player_chamber = target_cell->chamber();
                cout<<"You have chosen to play as a Samurai. Good luck."<<endl;

            }
            break;
        } // if
    }  //for
}


void Game::spawnEnemy(int i, int j) {
    int enemy_type = prng(5); // determine a random enemy to set
    for (;;) {
        int row_random = prng(24); // get a random place
        int col_random = prng(79);
        if (grid[row_random][col_random].symbol() == '.' && grid[row_random][col_random].chamber() == j) {
            Cell *target_cell =&(grid[row_random][col_random]);
            if (enemy_type == 0 || enemy_type == 1) {  // set a grid bug in map
                this->MonsterStack[i] = new Grid_Bug();
                MonsterStack[i]->location(target_cell);
                target_cell->setSymbol('X');
                target_cell->setContents(MonsterStack[i]);
                target_cell->setOccupied();
                target_cell->setEnemy();
                
            } else if(enemy_type == 2 || enemy_type == 3){ // set a goblin in map
                this->MonsterStack[i] = new Goblin();
                MonsterStack[i]->location(target_cell);
                target_cell->setSymbol('g');
                target_cell->setContents(MonsterStack[i]);
                target_cell->setOccupied();
                target_cell->setEnemy();
            } else if (enemy_type == 4) { // set a merchant in map
                this->MonsterStack[i] = new Merchant();
                MonsterStack[i]->location(target_cell);
                target_cell->setSymbol('M');
                target_cell->setContents(MonsterStack[i]);
                target_cell->setOccupied();
                target_cell->setEnemy();
            } else {
                this->MonsterStack[i] = new Orc(); // set an orc in map
                MonsterStack[i]->location(target_cell);
                target_cell->setSymbol('O');
                target_cell->setContents(MonsterStack[i]);
                target_cell->setOccupied();
                target_cell->setEnemy();
            }
            break;
        }
    }
}


void Game::spawnGold(int j) {
    int gold_type = prng(7);
    for (;;) {
        int row_random = prng(24);
        int col_random = prng(79);
        if (grid[row_random][col_random].symbol() == '.' && grid[row_random][col_random].chamber() == j) {
            Cell *target_cell =&(grid[row_random][col_random]);
            if (gold_type != 7) {
                GameObject *gold = new Item(6); // set a gold pile in map
                target_cell->setSymbol('$');
                gold->location(target_cell);
                target_cell->setContents(gold);
                target_cell->setOccupied();
                target_cell->setItem();
            } else {
                GameObject *gold = new Item(7); // set a dragon hoard in map
                target_cell->setSymbol('$');
                gold->location(target_cell);
                target_cell->setContents(gold);
                target_cell->setOccupied();
                target_cell->setItem();
            }
            break;
        }
    }
}


void Game::spawnPotion(int j) {
    int potion_type = prng(5); // determine a random potion in map
    for (;;) {
        int row_random = prng(24);
        int col_random = prng(79);
        if (grid[row_random][col_random].symbol() == '.' && grid[row_random][col_random].chamber() == j) {
            Cell *target_cell =&(grid[row_random][col_random]);
            GameObject *potion = new Item(potion_type);
            target_cell->setSymbol('!');
            potion->location(target_cell);
            target_cell->setContents(potion);
            target_cell->setOccupied();
            target_cell->setItem();
            break;
        }
    }
}


void Game::spawnStair() { // set a stair in map but in different chamber with player
    for(;;){
        int row_random = prng(24);
        int col_random = prng(79);
        if(grid[row_random][col_random].symbol() == '.'
           && grid[row_random][col_random].chamber() != player_chamber) {
            Cell *target_cell =&(grid[row_random][col_random]);
            target_cell->setSymbol('>');
            target_cell->setOccupied();
            break;
        } // if
    }
}


void Game::spawnEverything() {
    spawnStair(); // set stair
    for (int i = 0; i < 20; ++i) {
        int j = prng(4);
        spawnEnemy(i,j);
    }
    for (int i=0; i < 10; ++i) { // set 10 potions
        int j = prng(4);
        spawnPotion(j);
    }
    for (int i=0; i<10; ++i){ // set 20 enemys
        int j = prng(4);
        spawnGold(j);
    }
}


void Game::auto_move(Character * enemy) {
    for (;;) {
        int move_direction= prng(7); // randomly choose a direction
        if (enemy->move(move_direction)){
            break;
        }
    }
}


void Game::moveEverything() {
    for (int i = 0; i < 20; ++i) { // move 20 enemys randomly
        if (MonsterStack[i]->is_dead() == false) {
        auto_move(MonsterStack[i]);
        }
    }
    ++turn;
}


void Game::deleteEverything() {
    for (int i = 0; i < 20; ++i) { // delete all enemys
        delete MonsterStack[i];
    }
    
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            if(grid[r][c].is_item()){ // delete all items
                GameObject *item = grid[r][c].contents();
                delete item;
                grid[r][c].setContents(NULL);
                grid[r][c].resetSymbol();
                grid[r][c].setOccupied();
                grid[r][c].setItem();
            } else if (grid[r][c].is_enemy()) { // reset all cell that used to contain an enemy
                grid[r][c].setContents(NULL);
                grid[r][c].resetSymbol();
                grid[r][c].setOccupied();
                grid[r][c].setEnemy();
            } else if (grid[r][c].symbol() == '>') { // reset the stair for next floor
                grid[r][c].setContents(NULL);
                grid[r][c].resetSymbol();
                grid[r][c].setOccupied();
            } else {
                
            }
        } // inside for
    } // outside for
    
    
}



void Game::refreshPlayer() {
    Player->refresh(); // update player's attack and defence
    for(;;){           // randomly place the player in the map
        int row_random = prng(24);
        int col_random = prng(79);
        if (grid[row_random][col_random].symbol() == '.') {
            Cell *target_cell = &(grid[row_random][col_random]);
            Player->location(target_cell);
            target_cell->setSymbol('@');
            target_cell->setContents(Player);
            target_cell->setOccupied();
            target_cell->setPlayer();
            player_chamber = target_cell->chamber();
            break;
        } // if
    }
}








void Game::print() { // print all necessary message including map
    display->print(); // print map

    
    //print Class
    cout << "        Class: ";
    cout << left<<setw(12)<<Player->name();
    //print GP
    cout <<"GP: ";
    cout <<left<<setw(15)<< Player->GP();
    //print Floor
    cout << "Floor " << floor <<"      "<< endl;
    cout << "        HP: ";
    
    
    //print Atk
    string s1 = to_string(Player->HP());
    string s2 = to_string(Player->MaxHP());
    string s3 = s1+"/"+s2;
    cout << left<<setw(15)<<s3;
    cout << "Atk: ";
    cout <<left<<setw(14)<< Player->Atk();
    
    //print Def
    cout << "Def: ";
    string s4 = to_string(Player->Def());
    string s5 = s4 + "%";
    cout << left << setw(8)<<s5;
    
    //print Turn
    cout << "Turn: " << turn <<"      "<< endl;
    cout << endl;
    cout << "What will you do?" << endl;
}
