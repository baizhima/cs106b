/*
 * CS 106B Recursion Warmups
 * This client program contains a text menu for running your various
 * recursion warm-up problems.
 * You don't need to modify this file.
 */

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "console.h"
#include "gwindow.h"
#include "random.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

// function prototype declarations
int countPaths(int street, int avenue);
bool isBalanced(string exp);
void drawSierpinskiTriangle(GWindow& gw, double x, double y, double size, int order);
void test_karelGoesHome();
void test_balancingParentheses();
void test_sierpinskiTriangle();


int main() {
    setConsoleSize(750, 450);
    setConsoleFont("Monospaced-Bold-16");
    setConsoleEcho(true);
    setConsolePrintExceptions(true);

    cout << "CS 106B Recursion Warm-ups" << endl;
    cout << "Choose a warmup problem:" << endl;
    cout << "A) Karel Goes Home" << endl;
    cout << "B) Balancing Parentheses" << endl;
    cout << "C) Sierpinski Triangle" << endl;
    string choice = toUpperCase(trim(getLine("Enter your choice: ")));

    if (choice == "A") { test_karelGoesHome(); }
    if (choice == "B") { test_balancingParentheses(); }
    if (choice == "C") { test_sierpinskiTriangle(); }

    return 0;
}

/*
 * This function runs and tests your countPaths function.
 */
void test_karelGoesHome() {
    const int GRID_SIZE = 10;
    const int FIELD_WIDTH = 7;

    cout << "Karel's path count for several possible locations:" << endl;
    for (int street = GRID_SIZE; street > 0; street--) {
        for (int avenue = 1; avenue <= GRID_SIZE; avenue++) {
            int nPaths = countPaths(street, avenue);
            cout << right << setw(FIELD_WIDTH) << nPaths;
        }
        cout << endl;
    }
}

/*
 * This function runs and tests your isBalanced function.
 */
void test_balancingParentheses() {
    while (true) {
        cout << "Enter a string (or Q to quit): ";
        string exp = toLowerCase(getLine());
        if (exp == "q") {
            break;
        }
        if (isBalanced(exp)) {
            cout << "Yes, that string is balanced!" << endl;
        } else {
            cout << "No, that string is not balanced." << endl;
        }
    }
}

/*
 * This function runs and tests your isBalanced function.
 */
void test_sierpinskiTriangle() {
    const double WINDOW_WIDTH = 700;
    const double WINDOW_HEIGHT = 470;
    const double SIZE = 520;

    int order = getInteger("order? ");
    GWindow gw(WINDOW_WIDTH, WINDOW_HEIGHT);
    gw.setWindowTitle("CS 106B Sierpinski Triangle");
    double x0 = (WINDOW_WIDTH - SIZE) / 2;
    double y0 = 20;

    drawSierpinskiTriangle(gw, x0, y0, SIZE, order);
}
