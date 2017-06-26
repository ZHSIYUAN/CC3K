
#include <sstream>
#include <iostream>
#include <string>
#include "PRNG.h"
#include "game.h"
#include "cell.h"
#include <unistd.h>
using namespace std;

PRNG prng;
int floor = 1;
int turn = 1;
bool stopdeath = false;
bool stopwander = false;

int main(int argc, const char * argv[]) {
    prng.seed(getpid());
    string s;
    cout << "Welcome to ChamberCrawler3000!" << endl;
    cout << "What would you like to play as today?" <<endl;
    cout << "w) Wizard" << endl;
    cout << "k) Knight" << endl;
    cout << "s) Samurai" << endl;
    for (;;){  // choose which hero to play with
        cin >> s;
        if(s == "w" || s == "k" || s == "s") {
            break;
        } else {
            cout<<"Did not recognize input."<<endl;
        }
    } // for
    
    Game *mygame = new Game(); // start new game
    mygame->spawnPlayer(s); // create player
    mygame->spawnEverything(); // create monsters and items
    mygame->print(); // print out map
    
    string action;
    
    while (cin >> action) {
        try {
            if (action == "u") { // if player want to use item
                string action2;
                cin >> action2;
                if (action2 == "we") {
                    if (mygame->Player->use_item(3)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                            throw 200;
                        }
                    }
                } else if (action2 == "nw") {
                    if (mygame->Player->use_item(0)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                            throw 200;
                        }
                    }
                } else if (action2 == "no") {
                    if (mygame->Player->use_item(1)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                            throw 200;
                        }
                    }
                } else if (action2 == "ne") {
                    if (mygame->Player->use_item(2)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                            throw 200;
                        }
                    }
                } else if (action2 == "ea") {
                    if (mygame->Player->use_item(4)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                            throw 200;
                        }
                    }
                } else if (action2 == "se") {
                    if (mygame->Player->use_item(7)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                            throw 200;
                        }
                    }
                } else if (action2 == "so") {
                    if (mygame->Player->use_item(6)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                            throw 200;
                        }
                    }
                } else if (action2 == "sw") {
                    if (mygame->Player->use_item(5)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                            throw 200;
                        }
                    }
                } else { // invalid input
                    cout << "Unexpected direction to use." << endl;
                    continue;
                }
            } else if (action == "a") { // if player want to attack
                string action2;
                cin >> action2;
                if (action2 == "we") {
                    if (mygame->Player->attack(3)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                            throw 200;
                        }
                    }
                } else if (action2 == "nw") {
                    if (mygame->Player->attack(0)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                            throw 200;
                        }
                    }
                } else if (action2 == "no") {
                    if (mygame->Player->attack(1)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                            throw 200;
                        }
                    }
                } else if (action2 == "ne") {
                    if (mygame->Player->attack(2)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                            throw 200;
                        }
                    }
                } else if (action2 == "ea") {
                    if (mygame->Player->attack(4)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                            throw 200;
                        }
                    }
                } else if (action2 == "se") {
                    if (mygame->Player->attack(7)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                            throw 200;
                        }
                    }
                } else if (action2 == "so") {
                    if (mygame->Player->attack(6)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                            throw 200;
                        }
                    }
                } else if (action2 == "sw") {
                    if (mygame->Player->attack(5)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                            throw 200;
                        }
                    }
                } else { // invalid input
                    cout << "Unexpected direction to attack." << endl;
                    continue;
                }
            } else if (action == "we") {
                if (mygame->Player->move(3)) {
                    mygame->moveEverything();
                    mygame->print();
                    if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                        throw 200;
                    }
                }
            } else if (action == "nw") {
                if (mygame->Player->move(0)) {
                    mygame->moveEverything();
                    mygame->print();
                    if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                        throw 200;
                    }
                }
            } else if (action == "no") {
                if (mygame->Player->move(1)) {
                    mygame->moveEverything();
                    mygame->print();
                    if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                        throw 200;
                    }
                }
            } else if (action == "ne") {
                if (mygame->Player->move(2)) {
                    mygame->moveEverything();
                    mygame->print();
                    if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                        throw 200;
                    }
                }
            } else if (action == "ea") {
                if (mygame->Player->move(4)) {
                    mygame->moveEverything();
                    mygame->print();
                    if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                        throw 200;
                    }
                }
            } else if (action == "se") {
                if (mygame->Player->move(7)) {
                    mygame->moveEverything();
                    mygame->print();
                    if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                        throw 200;
                    }
                }
            } else if (action == "so") {
                if (mygame->Player->move(6)) {
                    mygame->moveEverything();
                    mygame->print();
                    if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                        throw 200;
                    }
                }
            } else if (action == "sw") {
                if (mygame->Player->move(5)) {
                    mygame->moveEverything();
                    mygame->print();
                    if (mygame->Player->HP() == 0 && !stopdeath) { // if player is dead
                        throw 200;
                    }
                }
            } else if (action == "q") { // if player want to quit
                cout << "Are you sure your want to quit? (y/n)" << endl; // ask player to choose
                string action3;
                while (cin >> action3) {
                    if (action3 == "y") {
                        break;
                    } else if (action3 == "n") {
                        break;
                    } else {
                        cout << "Did not recognize input." << endl; // invalid input
                    }
                }
                if (action3 == "y") {
                    cout << "You have chosen to exit. At least you tried." << endl; // player want to quit
                    break;
                } else {
                    mygame->print();
                }
            } else if (action == "r") {
                cout << "Are you sure you want to restart? (y/n)" << endl; // ask player to choose
                string action3;
                while (cin >> action3) {
                    if (action3 == "y") {
                        break;
                    } else if (action3 == "n") {
                        break;
                    } else {
                        cout << "Did not recognize input." << endl;
                    }
                }
                if (action3 == "y") { // player want to restart game
                    floor = 1;
                    turn = 1;
                    stopdeath = false;
                    Cell *target_cell =
                    mygame->Player->location();
                    target_cell->setContents(NULL);
                    target_cell->setOccupied();
                    target_cell->resetSymbol();
                    target_cell->setPlayer();
                    delete mygame->Player;
                    mygame->deleteEverything();
                
                    cout << "what would you like to play as today?" <<endl;
                    cout << "w) Wizard" << endl;
                    cout << "k) Knight" << endl;
                    cout << "s) Samurai" << endl;
                    while(cin >> s){
                        if(s == "w"|| s == "k" || s == "s") {
                            break;
                        } else {
                            cout<< "Did not recognize input." <<endl;
                        }
                    }
                    mygame->spawnPlayer(s);
                    mygame->spawnEverything();
                    mygame->print();
                } else {
                   mygame->print();
                }
            } else if (action == "stopdeath") { // Player no longer be killed
                stopdeath = true;
                cout << "Player death can no longer occur." << endl;
                mygame->print();
            } else if (action == "stopwander") { // Monsters no longer move
                cout << "Enemy actions that would result in movement now do nothing instead." << endl;
                stopwander = true;
                mygame->print();
            } else { // invalid input
                cout << "Did not recognize input." << endl;
                continue;
            }                                               // end of try
        } catch (int i) {                                   // start of catch
            if (i == 100) { // if player reaches the stair
                if (floor != 5) { // go down to next floor
                    floor = floor+1;
                    ++turn;
                    cout << "You descend down to floor "  << floor <<"."<< endl;
                    
                    Cell *target_cell = mygame->Player->location();
                    target_cell->setContents(NULL);
                    target_cell->setOccupied();
                    target_cell->resetSymbol();
                    target_cell->setPlayer();
                    mygame->deleteEverything();
                    
                    mygame->refreshPlayer();
                    mygame->spawnEverything();
                    mygame->print();
                    
                } else { // won the game
                    cout << "At long last, you have outmatched the Great Cavernous Chambers. Great things await you." << endl;
                    cout << "You achieved a score of " << mygame->Player->GP() <<"."<< endl;
                    cout << "Play again? (y/n)" << endl;
                    string option;
                    while (cin >> option) {
                        if (option == "y") {
                            break;
                        } else if (option == "n") {
                            break;
                        } else {
                            cout << "Did not recognize input." << endl;
                        }
                    }
                    if (option == "y") { // start a new game
                        floor = 1;
                        turn = 1;
                        stopdeath = false;
                        Cell *target_cell = mygame->Player->location();
                        target_cell->setContents(NULL);
                        target_cell->setOccupied();
                        target_cell->resetSymbol();
                        target_cell->setPlayer();
                        delete mygame->Player;
                        mygame->deleteEverything();
                        
                        cout << "what would you like to play as today?" <<endl;
                        cout << "w) Wizard" << endl;
                        cout << "k) Knight" << endl;
                        cout << "s) Samurai" << endl;
                        while(cin >> s){
                            if(s == "w"|| s == "k" || s == "s") {
                                break;
                            } else {
                                cout<< "Did not recognize input."
                                <<endl;
                            }
                        }
                        mygame->spawnPlayer(s);
                        mygame->spawnEverything();
                        mygame->print();
                    } else {
                        break;
                    }
                }
            } // if (i == 100)
            if (i == 200) { // player get killed
                cout << "You have been bested by the Gret Cavernous Chambers. Good luck next time!" << endl;
                cout << "You achieved a score of " << mygame->Player->GP() << endl;
                cout << "Play again? (y/n)" << endl;
                string option;
                while (cin >> option) {
                    if (option == "y") {
                        break;
                    } else if (option == "n") {
                        break;
                    } else {
                        cout << "Did not recognize input." << endl;
                    }
                }
                if (option == "y") { // restart a new game
                    floor = 1;
                    turn = 1;
                    stopdeath = false;
                    Cell *target_cell =
                    mygame->Player->location();
                    target_cell->setContents(NULL);
                    target_cell->setOccupied();
                    target_cell->resetSymbol();
                    target_cell->setPlayer();
                    delete mygame->Player;
                    mygame->deleteEverything();
                    
                    cout << "what would you like to play as today?" <<endl;
                    cout << "w) Wizard" << endl;
                    cout << "k) Knight" << endl;
                    cout << "s) Samurai" << endl;
                    while(cin >> s){
                        if(s == "w"|| s == "k" || s == "s") {
                            break;
                        } else {
                            cout<<"Did not recognize input."<<endl;
                        }
                    }
                    mygame->spawnPlayer(s);
                    mygame->spawnEverything();
                    mygame->print();
                } else {
                    break;
                }
            } // if (i == 200)
        } // catch
    } // while loop
    
    delete mygame;
    return 0;
}




