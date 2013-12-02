/*
 * CS 106B Assassins
 * This client program uses your AssassinsList class and contains the 'main'
 * function to open the input file and set up the program's user interface,
 * prompting the user for each player to eliminate and printing the game state.
 * Your code should work properly with an unmodified version of this file.
 */

#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
#include "simpio.h"
#include "strlib.h"
#include "AssassinsList.h"
using namespace std;

// constant for file name to read initial player data from
static const string DEFAULT_INPUT_FILENAME = "players.txt";

// function prototype declarations
bool doOneElimination(AssassinsList& alist);
void intro();
void openInputFile(ifstream& input);

int main() {
    intro();

    // prompt for input file name and open the input file
    ifstream input;
    openInputFile(input);

    // main game loop
    AssassinsList alist(input);
    while (!alist.isGameOver()) {
        if (!doOneElimination(alist)) {
            cout << "Aborted." << endl;
            return 0;
        }
    }

    cout << "Game was won by " << alist.winner() << endl;
    cout << "Final graveyard is as follows:" << endl;
    alist.printGraveyard();
    return 0;
}

/*
 * Sets up the output console and explains the game to the player.
 */
void intro() {
    setConsoleSize(750, 450);
    setConsoleFont("Monospaced-Bold-16");
    setConsoleEcho(true);
    setConsolePrintExceptions(true);

    cout << "Welcome to CS 106B Assassins." << endl;
    cout << "In this game, a 'game ring' of players are trying to" << endl;
    cout << "eliminate each other and be the last one standing." << endl;
    cout << "Each player targets the one after him/her in the ring." << endl;
    cout << "Eliminated players are placed into a graveyard." << endl;
    cout << endl;
}

void openInputFile(ifstream& input) {
    while (true) {
        string filename = trim(getLine(string("Input file name (Enter for ")
                                  + DEFAULT_INPUT_FILENAME + ")? "));
        if (filename == "") {
            filename = DEFAULT_INPUT_FILENAME;
        }
        input.open(filename.c_str());
        if (input.fail()) {
            cout << "Unable to open input file " << filename << "." << endl;
        } else {
            break;
        }
    }
}

/*
 * Performs one elimination round in the game, prompting the user for a name
 * to eliminate and removing that player from the game.
 */
bool doOneElimination(AssassinsList& alist) {
    // print both linked lists
    cout << "Current game ring:" << endl;
    alist.printGameRing();
    cout << "Current graveyard:" << endl;
    alist.printGraveyard();

    // prompt for next victim to eliminate
    cout << endl;
    string name = trim(getLine("next victim? "));

    // eliminate the victim, if possible
    if (name == "") {
        return false;
    } else if (alist.isDead(name)) {
        cout << name << " is already eliminated." << endl;
    } else if (!alist.isAlive(name)) {
        cout << "Unknown person." << endl;
    } else {
        alist.eliminate(name);
    }
    cout << endl;
    return true;
}
