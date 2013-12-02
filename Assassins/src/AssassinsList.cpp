// Programming Assignment 3, Assassins
// CS 106B Programming Abstraction, Fall 2013, Stanford University
// Author Shan Lu, Renmin University of China, contact lushan.frank@gmail.com
// Last updated Dec. 1st, 2013
// AssassinsList.cpp implements a LinkList data structure to store Assassins information


#include "AssassinsList.h"
#include "strlib.h"

AssassinsList::AssassinsList(istream& input) {
    // TODO: write this member
    gameRing = NULL; // initializaion , or it is not set to NULL at first
    graveYard = NULL; // initializaion , or it is not set to NULL at first
    string line;
    if (input.fail())
        throw new string("the list file does not contain any names.");
    while (true) // read input stream
    {
        getline(input,line);
        if (input.fail())break;
        Node* oldFirst = gameRing;
        gameRing = new Node(line,oldFirst);
    }

}

AssassinsList::~AssassinsList() {
    // TODO: write this member
    while (gameRing)
    {
        Node *trash = gameRing;
        gameRing = gameRing->next;
        delete trash;
    }
    while (graveYard)
    {
        Node *trash = graveYard;
        graveYard = graveYard->next;
        delete trash;
    }
}

void AssassinsList::printGameRing() {
    // TODO: write this member
    Node *current = gameRing;

    while (current != NULL)
    {
        cout << "  " << current->name << " is targeting ";
        if (current->next != NULL)
            cout << current->next->name << endl;
        else
            cout << gameRing->name << endl;
        current = current ->next;
    }
}

void AssassinsList::printGraveyard() {
    // TODO: write this member
    Node *current = graveYard;
    while (current != NULL)
    {
        cout << "  " << current->name << " was eliminated by " << current->killer << endl;
        current = current ->next;
    }
}

bool AssassinsList::isAlive(string& player) {
    // TODO: write this member
    Node *current = gameRing;

    while (current != NULL)
    {
        if (equalsIgnoreCase(current->name, player))
            return true;
        current = current ->next;
    }
    return false;
}

bool AssassinsList::isDead(string& player) {
    Node *current = graveYard;
    while (current != NULL)
    {
        if (equalsIgnoreCase(current->name, player))
            return true;
        current = current ->next;
    }
    return false;
}

bool AssassinsList::isGameOver() {
    return gameRing->next == NULL;
}

string AssassinsList::winner() {
    if (!isGameOver())
        return "";
    else
        return gameRing->name;
}

void AssassinsList::eliminate(string& player) {
    if (!isAlive(player))
        throw new string("The name is not part of game ring");
    if (isGameOver())
        throw new string("The game is over");
    Node *prev = NULL;
    Node *lastNode = NULL;
    Node *current = gameRing;
    // find the last Node
    while (current != NULL) // initiate killer names
    {
        if (current->next == NULL)
            lastNode = current;
        current = current->next;
    }
    // find the Node to be deleted
    current = gameRing;
    while (current != NULL)
    {
        if (equalsIgnoreCase(current->name, player))
            break;
        else
        {
            prev = current;
            current = current->next;
        }
    }
    // delete the first node case
    if (prev == NULL)
    {
        gameRing = current->next;
        current->killer = lastNode->name;
    }
    else //delete the nonfirst node case
    {
        prev->next = current->next;
        current->killer = prev->name;
    }
    current->next = NULL;
    Node *gravePtr = graveYard;
    if (gravePtr == NULL)
        graveYard = current;
    else
    {
        current->next = graveYard;
        graveYard = current;
    }
}
