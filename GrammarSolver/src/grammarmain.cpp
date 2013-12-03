/*
 * CS 106B Grammar Solver
 * This file contains the main program and user interface for running your
 * grammar solver to generate random sentences.
 */

#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
#include "simpio.h"
#include "strlib.h"
#include "GrammarSolver.h"
using namespace std;

// constant for file name to read grammar data from
static const string DEFAULT_INPUT_FILENAME = "sentence.txt";

// function prototype declarations
void intro();
void openInputFile(ifstream& input);
string askSymbol(GrammarSolver& solver);
void doGeneration(GrammarSolver& solver, const string& symbol);

int main() {
    intro();

    // prompt for input file name and open the input file
    ifstream input;
    openInputFile(input);

    // main loop prompts for a symbol and number, then generates sentences
    GrammarSolver solver(input);
    while (true) {
        string symbol = askSymbol(solver);
        if (symbol.length() == 0) {
            break;
        } else if (solver.contains(symbol)) {
            doGeneration(solver, symbol);
        } else {
            cout << "Unknown symbol." << endl;
        }
    }

    cout << "Exiting." << endl;
    return 0;
}

/*
 * Sets up the output console and explains the program to the user.
 */
void intro() {
    setConsoleSize(850, 450);
    setConsoleFont("Monospaced-Bold-16");
    setConsoleEcho(true);
    setConsolePrintExceptions(true);

    cout << "Welcome to the CS 106B random sentence generator!" << endl;
    cout << "This program recursively generates random sentences" << endl;
    cout << "based on a grammar in Backus-Naur Format (BNF)." << endl;
    cout << endl;
}

/*
 * Prompts the user for an input file name until a valid file is found,
 * opening the file using the given input stream for reading.
 */
void openInputFile(ifstream& input) {
    while (true) {
        string filename = trim(getLine(string("Grammar file name (Enter for ")
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
 * Lists the available symbols and prompts the user to generate a symbol.
 */
string askSymbol(GrammarSolver& solver) {
    cout << endl;
    cout << "Available symbols to generate are:" << endl;
    Set<string> symbols;
    solver.getSymbols(symbols);
    foreach (string symbol in symbols) {
        cout << symbol << " ";
    }
    cout << endl;
    return trim(getLine("What do you want to generate (Enter to quit)? "));
}

/*
 * Prompts the user for how many symbols to generate and then generates
 * the symbol that many times using the GrammarSolver.
 */
void doGeneration(GrammarSolver& solver, const string& symbol) {
    int howMany = getInteger("How many to generate? ");
    cout << endl;
    for (int i = 0; i < howMany; i++) {
        string result = solver.generate(symbol);
        cout << result << endl;
    }
}
