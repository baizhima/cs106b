// Programming Assignment 4, GrammarSolver
// CS 106B Programming Abstraction, Fall 2013, Stanford University
// Author Shan Lu, Renmin University of China, contact lushan.frank@gmail.com
// Last updated Dec. 3rd, 2013
// GrammarSolver.cpp generates English phrases or sentences using recursion


#include "random.h"
#include "split.h"
#include "tokenscanner.h"
#include "GrammarSolver.h"

// TODO: write the members
GrammarSolver::GrammarSolver(istream& input)
{
    string s;
    while (true)
    {
        getline(input,s);
        if (input.fail()) break;
        Vector<string> v = split(s,"::=");
        if (grammar.containsKey(v[0]))
            throw new string("illegal input files");
        Vector<string> token = split(v[1],"|");
        grammar.put(v[0],token);
    }

}

bool GrammarSolver::contains(string symbol) // whether symbol is a non-terminal
{
    return grammar.containsKey(symbol);
}

string GrammarSolver::generate(string symbol)
{
    if (!grammar.containsKey(symbol))
        return symbol;
    int rulesNum = grammar[symbol].size();
    string rule = grammar[symbol][randomInteger(0,rulesNum - 1)];
    Vector<string> nonterminals = split(rule," ");
    string output = "";
    for (int i = 0; i < nonterminals.size(); i++)
    {
        output.append(generate(nonterminals[i]));
        if (i < nonterminals.size() - 1)
            output.append(" ");
    }
    return trim(output);
}

void GrammarSolver::getSymbols(Set<string>& out)
{
    foreach (string s in grammar.keys()){
        out.add(s);
    }
    return;
}
