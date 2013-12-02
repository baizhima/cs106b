// Programming Assignment 3, Tiles
// CS 106B Programming Abstraction, Fall 2013, Stanford University
// Author Shan Lu, Renmin University of China, contact lushan.frank@gmail.com
// Last updated Nov. 30th, 2013
// TileList.h defines the TileList class, which is designed to store and manage Tile objects dynamically

#ifndef _tilelist_h
#define _tilelist_h

#include <iostream>
#include <string>
#include "gobjects.h"
#include "gwindow.h"
#include "strlib.h"
#include "Tile.h"
using namespace std;

class TileList {
public:
    TileList();
    ~TileList();
    void addTile(Tile tile);
    void drawAll(GWindow& window) const;
    int indexOfTopTile(int x, int y) const;
    void lower(int x, int y);
    void raise(int x, int y);
    void remove(int x, int y);
    void removeAll(int x, int y);

private:
    Tile *m_tiles;
    int m_size;
    int m_capacity;
    void checkIndex(int index, int min, int max) const;
    void checkResize();
    void copy(const TileList& other);
};

#endif
