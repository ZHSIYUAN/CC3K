
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
int turn = 0;

int main(int argc, const char * argv[]) {
    prng.seed(getpid());
    string s;
    cout << "what would you like to play as today?" <<endl;
    cout << "w) Wizard" << endl;
    cout << "k) Knight" << endl;
    cout << "s) Samurai" << endl;
    for (;;){
        cin >> s;
        if(s == "w" || s == "k" || s == "s") {
            break;
        } else {
            cout<<"Did not recognize input."<<endl;
        }
    }
    
    cerr <<" s is: "<<s;
    Game *mygame = new Game();
    mygame->spawnPlayer(s);
    mygame->spawnEverything();
    mygame->print();
    
    string action;
    
    while (cin >> action) {
        try {
            if (action == "u") {
                string action2;
                cin >> action2;
                if (action2 == "we") {
                    if (mygame->Player->use_item(3)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0) {
                            throw 200;
                        }
                    }
                } else if (action2 == "nw") {
                    if (mygame->Player->use_item(0)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0) {
                            throw 200;
                        }
                    }
                } else if (action2 == "no") {
                    if (mygame->Player->use_item(1)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0) {
                            throw 200;
                        }
                    }
                } else if (action2 == "ne") {
                    if (mygame->Player->use_item(2)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0) {
                            throw 200;
                        }
                    }
                } else if (action2 == "ea") {
                    if (mygame->Player->use_item(4)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0) {
                            throw 200;
                        }
                    }
                } else if (action2 == "se") {
                    if (mygame->Player->use_item(7)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0) {
                            throw 200;
                        }
                    }
                } else if (action2 == "so") {
                    if (mygame->Player->use_item(6)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0) {
                            throw 200;
                        }
                    }
                } else if (action2 == "sw") {
                    if (mygame->Player->use_item(5)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0) {
                            throw 200;
                        }
                    }
                } else {
                    cout << "Unexpected direction to use." << endl;
                    continue;
                }
            } else if (action == "a") {
                string action2;
                cin >> action2;
                if (action2 == "we") {
                    if (mygame->Player->attack(3)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0) {
                            throw 200;
                        }
                    }
                } else if (action2 == "nw") {
                    if (mygame->Player->attack(0)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0) {
                            throw 200;
                        }
                    }
                } else if (action2 == "no") {
                    if (mygame->Player->attack(1)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0) {
                            throw 200;
                        }
                    }
                } else if (action2 == "ne") {
                    if (mygame->Player->attack(2)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0) {
                            throw 200;
                        }
                    }
                } else if (action2 == "ea") {
                    if (mygame->Player->attack(4)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0) {
                            throw 200;
                        }
                    }
                } else if (action2 == "se") {
                    if (mygame->Player->attack(7)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0) {
                            throw 200;
                        }
                    }
                } else if (action2 == "so") {
                    if (mygame->Player->attack(6)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0) {
                            throw 200;
                        }
                    }
                } else if (action2 == "sw") {
                    if (mygame->Player->attack(5)) {
                        mygame->moveEverything();
                        mygame->print();
                        if (mygame->Player->HP() == 0) {
                            throw 200;
                        }
                    }
                } else {
                    cout << "Unexpected direction to attack." << endl;
                    continue;
                }
            } else if (action == "we") {
                if (mygame->Player->move(3)) {
                    mygame->moveEverything();
                    mygame->print();
                    if (mygame->Player->HP() == 0) {
                        throw 200;
                    }
                }
            } else if (action == "nw") {
                if (mygame->Player->move(0)) {
                    mygame->moveEverything();
                    mygame->print();
                    if (mygame->Player->HP() == 0) {
                        throw 200;
                    }
                }
            } else if (action == "no") {
                if (mygame->Player->move(1)) {
                    mygame->moveEverything();
                    mygame->print();
                    if (mygame->Player->HP() == 0) {
                        throw 200;
                    }
                }
            } else if (action == "ne") {
                if (mygame->Player->move(2)) {
                    mygame->moveEverything();
                    mygame->print();
                    if (mygame->Player->HP() == 0) {
                        throw 200;
                    }
                }
            } else if (action == "ea") {
                if (mygame->Player->move(4)) {
                    mygame->moveEverything();
                    mygame->print();
                    if (mygame->Player->HP() == 0) {
                        throw 200;
                    }
                }
            } else if (action == "se") {
                if (mygame->Player->move(7)) {
                    mygame->moveEverything();
                    mygame->print();
                    if (mygame->Player->HP() == 0) {
                        throw 200;
                    }
                }
            } else if (action == "so") {
                if (mygame->Player->move(6)) {
                    mygame->moveEverything();
                    mygame->print();
                    if (mygame->Player->HP() == 0) {
                        throw 200;
                    }
                }
            } else if (action == "sw") {
                if (mygame->Player->move(5)) {
                    mygame->moveEverything();
                    mygame->print();
                    if (mygame->Player->HP() == 0) {
                        throw 200;
                    }
                }
            } else {
                cout << "Did not recognize input." << endl;
                continue;
            }
        } catch (int i) {
            if (i == 100) {
                if (floor != 5) {
                    // output some information
                    // "Are you sure go done to next floor?"
                    
                    Cell *target_cell =
                    mygame->Player->location();
                    target_cell->setContents(NULL);
                    target_cell->setOccupied();
                    target_cell->resetSymbol();
                    target_cell->setPlayer();
                    mygame->deleteEverything();
                    
                    mygame->refreshPlayer();
                    mygame->spawnEverything();
                    mygame->print();
                    
                } else {
                    cout << "At long last, you have outmatched the Great Cavernous Chambers. Great things await you." << endl;
                    cout << "You achieved a score of " << mygame->Player->GP() << endl;
                    cout << "Play again? (y/n)" << endl;
                    string option;
                    cin >> option;
                    if (option == "y") {
                        floor = 0;
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
            if (i == 200) {
                cout << "You have been bested by the Gret Cavernous Chambers. Good luck next time!" << endl;
                cout << "You achieved a score of " << mygame->Player->GP() << endl;
                cout << "Play again? (y/n)" << endl;
                string option;
                cin >> option;
                if (option == "y") {
                    floor = 0;
                    
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



































