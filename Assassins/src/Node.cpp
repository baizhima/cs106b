#include <iomanip>
#include <iostream>
#include <sstream>
#include "Node.h"

Node::Node(string name, Node* next = NULL) {
    this->name = name;
    this->killer = "";
    this->next = next;
}

string Node::toString() const {
    stringstream out;
    out << "Node{addr=" << ((void*) this);
    out << ",name=\"" << name << "\"";
    if (killer.length() > 0) {
        out << ",killer=\"" << killer << "\"";
    }
    if (next) {
        out << ",next=" << ((void*) next);
    } else {
        out << ",next=NULL";
    }
    out << "}";
    return out.str();
}

ostream& operator <<(ostream& out, const Node& node) {
    out << node.toString();
    return out;
}
