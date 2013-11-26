// Stanford CS 106b Assignment 1, Fall 2013
// Author Shan Lu, Renmin University of China, contact lushan.frank@gmail.com
// Project started Oct. 26th, 2013

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "grid.h"
#include "gwindow.h"
#include "simpio.h"
using namespace std;

void intro();
void fileInput(ifstream& inf, Grid<int>& grid);
void gridDisplay(Grid<int> & grid);
void update(Grid<int> & grid);
string menu();
void animate(Grid<int> & grid);

int main() {
    setConsoleSize(700, 400);

    /* 1. Intro: Get your basic project running,
     and write code to print the introductory welcome message. */
    intro();

    /* 2. File input: Write code to prompt for a file name,
     and open and print that file's lines to the console. */
    string filename = getLine("Grid input file name? ");
    ifstream inf(filename.c_str());
    Grid<int> grid;
    fileInput(inf,grid);

    /* 3. Grid Display */
    gridDisplay(grid);

    /* 4. & 5. Overall Menu */
    string a = menu();
    while (a != string("q"))
    {
        if (a == string("t"))
        {
            /* 4. Updating to next generation */
            update(grid);
            gridDisplay(grid);
        }
        else if (a == string("a"))
            animate(grid);
        a = menu();
    }

    /* 6. End of the program */
    cout << "Have a nice Life!" << endl;

    return 0;
}

void intro()
{
    cout << "Welcome to the CS 106B Game of Life," << endl;
    cout << "a simulation of the lifecycle of a bacteria colony." << endl;
    cout << "Cells (X) live and die by the following rules:" << endl;
    cout << "- A cell with 1 or fewer neighbors dies." << endl;
    cout << "- Locations with 2 neighbors remain stable." << endl;
    cout << "- Locations with 3 neighbors will create life." << endl;
    cout << "- A cell with 4 or more neighbors dies." << endl;
    cout << endl;
}

void fileInput(ifstream &inf,
               Grid<int> &grid)
{
    string line;
    getline(inf,line);
    int nRow = stringToInteger(line);
    getline(inf,line);
    int nCol = stringToInteger(line);
    grid.resize(nRow,nCol);
    for (int i = 0; i < nRow; i++)
    {
        getline(inf,line);
        for (int j = 0; j < nCol; j++){
            if (line[j] - '-' == 0)
                grid.set(i,j,0);
            else if (line[j] - 'X' == 0)
                grid.set(i,j,1);
            else
                grid.set(i,j,-1);
        }

    }
    //cout << grid.toString() << endl;
}

void gridDisplay(Grid<int> &grid)
{
    for (int i = 0; i < grid.numRows(); i++)
        for (int j = 0; j < grid.numCols(); j++)
        {
            if (grid.get(i,j) == 1)
                cout << 'X';
            else if (grid.get(i,j) == 0)
                cout << '-';
            if (j == grid.numCols() - 1)
                cout << endl;
        }
}

void update(Grid<int> &grid)
{
    Grid<int> newGrid(grid.numRows(),grid.numCols());
    for (int i = 0; i < grid.numRows(); i++)
        for (int j = 0; j < grid.numCols(); j++)
        {
            int neighborCount = 0;
            for (int p = -1; p <= 1; p++)
                for (int q = -1; q <= 1; q++)
                {
                    // Ignore counting either grids out of bounds or itself
                    if (!grid.inBounds(i+p,j+q) || (p == 0 && q == 0)) continue;
                    int neighborGridVal =  grid.get(i+p,j+q);
                    if (neighborGridVal == 1)
                        neighborCount++;
                }
            // A location that has zero or one neighbors will be empty in the next generation.
            if (neighborCount == 0 || neighborCount == 1)
                newGrid.set(i,j,0);
            // A location with two neighbors is stable.
            else if (neighborCount == 2)
                newGrid.set(i,j,grid.get(i,j));
            // A location with three neighbors will contain a cell in the next generation.
            else if (neighborCount == 3)
                newGrid.set(i,j,1);
            // A location with four or more neighbors will be empty in the next generation.
            else if (neighborCount >= 4)
                newGrid.set(i,j,0);
        }
    grid = newGrid; // replace the old generation grid with the new one
}

string menu()
{
    return getLine("a)nimate, t)ick, q)uit? ");
}

void animate(Grid<int> & grid)
{
    string num = getLine("How many frames? ");
    for (int i = 0; i < stringToInteger(num); i++)
    {
        update(grid);
        gridDisplay(grid);
        pause(100);
        //clearConsole();
    }
}
