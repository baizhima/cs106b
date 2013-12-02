/*
 * CS 106B Tiles
 * This file contains the implementation of the Tile structure.
 * See Tile.h for comments about each member.
 * Your code should work properly with an unmodified version of this file.
 */

#include "Tile.h"

Tile::Tile() {
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    color = "";
}

bool Tile::contains(int x, int y) const {
    return this->x <= x && x < this->x + this->width &&
            this->y <= y && y < this->y + this->height;
}

void Tile::draw(GWindow& window) const {
    window.setColor(color);
    window.fillRect(x, y, width, height);
}

string Tile::toString() const {
    return string("Tile{x=") + integerToString(x) + ",y=" + integerToString(y)
            + ",w=" + integerToString(width) + ",h=" + integerToString(height)
            + ",color=\"" + color + "\"}";
}

ostream& operator<<(ostream& out, const Tile& tile) {
    out << tile.toString();
    return out;
}
