/*
 * CS 106B Tiles
 * This file contains the declaration of the Tile structure.
 * See Tile.cpp for implementation of each member.
 * Your code should work properly with an unmodified version of this file.
 */

#ifndef _tile_h
#define _tile_h

#include <iostream>
#include <string>
#include "gwindow.h"
#include "strlib.h"
using namespace std;

/*
 * Each Tile structure represents a single rectangular tile in the simulation.
 * A tile knows its position, size, and color.
 * It contains members that can draw itself, tell you whether it touches a
 * given x/y pixel, and print it on the console for debugging.
 */
struct Tile {
public:
    int x;         // (x, y) position of tile's top-left corner
    int y;
    int width;     // tile's dimensions in pixels
    int height;
    string color;  // tile's color as a hex RRGGBB string like "#ff00ff" for purple

    /*
     * Constructs a new tile with all fields initialized to 0-equivalent values.
     */
    Tile();

    /*
     * Returns true if this Tile touches the given x/y pixel.
     * For example, if (x, y) is (10, 20) and width x height are 5 x 30,
     * the tile returns true for (10 <= x <= 14, 20 <= y <= 49) inclusive.
     */
    bool contains(int x, int y) const;

    /*
     * Draws the given tile onto the given graphical GWindow.
     */
    void draw(GWindow& window) const;

    /*
     * Returns a string representation of the tile, such as
     * Tile{x=10,y=20,w=5,h=30,color=\"#ff00ff\"}".
     */
    string toString() const;
};

/*
 * Outputs the given tile to the given output stream (e.g. cout) in the same
 * format as returned by its toString member function.
 */
ostream& operator<<(ostream& out, const Tile& tile);

#endif
