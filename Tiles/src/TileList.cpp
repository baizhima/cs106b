// Programming Assignment 3, Tiles
// CS 106B Programming Abstraction, Fall 2013, Stanford University
// Author Shan Lu, Renmin University of China, contact lushan.frank@gmail.com
// Last updated Nov. 30th, 2013
// TileList.cpp implements an ArrayList data structure to store arrays of Tiles using dynamic memory allocation

#include "TileList.h"
#include "strlib.h"

TileList::TileList() {
    // TODO: write this member
    m_capacity = 10;
    m_tiles = new Tile[m_capacity];
    m_size = 0;

}

TileList::~TileList() {
    // TODO: write this member
    delete[] m_tiles;
}

void TileList::addTile(Tile tile) {
    // TODO: write this member
    checkResize();
    m_tiles[m_size++] = tile;

}

void TileList::drawAll(GWindow& window) const {
    // TODO: write this member
    for (int i = 0; i < m_size; i++)
        m_tiles[i].draw(window);
}

int TileList::indexOfTopTile(int x, int y) const {
    // TODO: write this member
    int i;
    bool hasAns = false;
    for (i = m_size - 1; i > 0; i--)
        if (m_tiles[i].contains(x,y))
        {
            hasAns = true;
            break;
        }

    if (hasAns) return i;
    return -1;
}

void TileList::raise(int x, int y) {
    // TODO: write this member
    int i = indexOfTopTile(x,y);
    if (i == -1) return;
    Tile *temp = new Tile[1];
    temp[0] = m_tiles[i];
    for (int j = i; j < m_size-1; j++)
        m_tiles[j] = m_tiles[j+1];
    m_tiles[m_size - 1] = temp[0];
    delete[] temp;

}

void TileList::lower(int x, int y) {
    // TODO: write this member
    int i = indexOfTopTile(x,y);
    if (i == -1) return;
    Tile *temp = new Tile[1];
    temp[0] = m_tiles[i];
    // for all tiles in TileList before m_tiles[i], move one idx forward
    for (int j = i; j > 0; j--)
        m_tiles[j] = m_tiles[j-1] ;
    m_tiles[0] = temp[0];
    delete[] temp;
}

void TileList::remove(int x, int y) {
    // TODO: write this member
    int i = indexOfTopTile(x,y);
    if (i == -1) return;
    for (int j = i; j < m_size - 1; j++)
    {
        m_tiles[j] = m_tiles[j+1];
    }

    m_size--;

}

void TileList::removeAll(int x, int y) {
    // TODO: write this member
    Tile *newTiles = new Tile[m_capacity];
    int newTileCount = 0;

    for (int i = 0; i < m_size; i++)
    {
        if (m_tiles[i].contains(x,y)) // if current tile contains (x,y), it will not be copied to the new m_tiles
            continue;
        else
            newTiles[newTileCount++] = m_tiles[i];
    }
    delete[] m_tiles;
    m_tiles = newTiles;
    m_size = newTileCount;
}

void TileList::checkResize() {
    if (m_size == m_capacity)
    {
        Tile *newTiles = new Tile[m_capacity * 2];
        for (int i = 0; i < m_capacity; i++)
            newTiles[i] = m_tiles[i];
        delete[] m_tiles; // free old memory
        m_tiles = newTiles;
        m_capacity *= 2;
    }
}
