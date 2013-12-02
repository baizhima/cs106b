/*
 * CS 106B Assassins
 * This file contains the declaration of the Node structure.
 * See Node.cpp for implementation of each member.
 * Your code should work properly with an unmodified version of this file.
 */

#ifndef _node_h
#define _node_h

#include <iostream>
using namespace std;

/*
 * Each Node structure represents a single node in a linked list used in
 * the game of Assassin.
 */
struct Node {
    string name;     // this person's name
    string killer;   // name of who killed this person ("" if alive)
    Node* next;      // pointer to next node in the list  (NULL if none)

    /*
     * Constructs a new node storing the given name and next pointer.
     * The killer is initially an empty string, "".
     */
    Node(string name, Node* next);

    /*
     * Returns a string representation of the Node for debugging, such as
     * "Node{addr=0x7e83f4,name=\"Joe Smith\",killer=\"Suzy Jones\", next=0x43b2a0}".
     *
     * Note that the toString output includes the node's memory address, as well
     * as the memory address where its next pointer points.
     *
     * Keep in mind that toString won't be called if you try to print a Node*.
     * You must print the node itself.
     *
     * Node* myNode = new Node("foo bar", NULL);
     * cout << myNode << endl;    // prints some memory address
     * cout << *myNode << endl;   // prints toString() output
     */
    string toString() const;
};

/*
 * Outputs the given node to the given output stream (e.g. cout) in the same
 * format as returned by its toString member function.
 */
ostream& operator <<(ostream& out, const Node& node);

#endif
