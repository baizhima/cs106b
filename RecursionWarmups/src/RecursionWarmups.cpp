// Programming Assignment 4, RecursionWarmups
// CS 106B Programming Abstraction, Fall 2013, Stanford University
// Author Shan Lu, Renmin University of China, contact lushan.frank@gmail.com
// Last updated Dec. 2nd, 2013
// RecursionWarmups.cpp uses recursion to solve three different problems

#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "gwindow.h"
#include "simpio.h"
using namespace std;

int countPaths(int street, int avenue) {
    // TODO: write this function    
    if (street < 1 || avenue < 1) return 0;
    if (street == 1 && avenue == 1) return 1;
    return countPaths(street - 1, avenue) + countPaths(street, avenue - 1);

}

bool isBalanced(string exp) {
    // TODO: write this function
    if (exp == "") return true;
    else
    {
        if (exp.find("()") != string::npos)
            return isBalanced(exp.replace(exp.find("()"),2,""));
        if ((exp.find("[]") != string::npos))
            return isBalanced(exp.replace(exp.find("[]"),2,""));
        if ((exp.find("{}") != string::npos))
            return isBalanced(exp.replace(exp.find("{}"),2,""));
        return false;
    }
    //return false;
}

void drawSierpinskiTriangle(GWindow& gw, double x, double y, double size, int order) {
    // TODO: write this function
    //gw.drawLine(20,20,30,80);
    if (order <= 0) return;
    if (order == 1) {
        gw.drawLine(x,y,x+size,y);
        gw.drawLine(x+size,y,x+0.5*size,y+sqrt(3)/2.0*size);
        gw.drawLine(x,y,x+0.5*size,y+sqrt(3)/2.0*size);
    }
    else
    {
        drawSierpinskiTriangle(gw, x, y, 0.5*size, order - 1);
        drawSierpinskiTriangle(gw, x + 0.5*size, y, 0.5*size, order - 1);
        drawSierpinskiTriangle(gw, x + 0.25*size, y + sqrt(3)/4.0*size, 0.5*size, order - 1);
    }



}
