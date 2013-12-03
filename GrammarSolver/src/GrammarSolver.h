// Programming Assignment 4, GrammarSolver
// CS 106B Programming Abstraction, Fall 2013, Stanford University
// Author Shan Lu, Renmin University of China, contact lushan.frank@gmail.com
// Last updated Dec. 3rd, 2013
// GrammarSolver.cpp generates English phrases or sentences using recursion


#ifndef _grammarsolver_h
#define _grammarsolver_h

#include <fstream>
#include <iostream>
#include <string>
#include "hashmap.h"
#include "map.h"
#include "set.h"
#include "vector.h"

using namespace std;

class GrammarSolver {
public:
    GrammarSolver(istream& input);
    bool contains(string symbol);
    string generate(string symbol);
    void getSymbols(Set<string>& out);

private:
    Map<string,Vector<string> > grammar;

};

#endif
