// Programming Assignment 3, Assassins
// CS 106B Programming Abstraction, Fall 2013, Stanford University
// Author Shan Lu, Renmin University of China, contact lushan.frank@gmail.com
// Last updated Dec. 1st, 2013
// AssassinsList.h shows the prototype of class AssassinList

#ifndef _assassinslist_h
#define _assassinslist_h

#include <fstream>
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

class AssassinsList {
public:
    AssassinsList(istream& input);
    ~AssassinsList();
    void printGameRing();
    void printGraveyard();
    bool isAlive(string& player);
    bool isDead(string& player);
    bool isGameOver();
    string winner();
    void eliminate(string& player);

private:
    Node *gameRing;
    Node *graveYard;
};

#endif
