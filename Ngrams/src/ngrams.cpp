// Programming Assignment 2, Ngrams
// CS 106B Programming Abstraction, Fall 2013, Stanford University
// Author Shan Lu, Renmin University of China, contact lushan.frank@gmail.com
// Last updated Nov. 29th, 2013

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "grid.h"
#include "hashmap.h"
#include "hashset.h"
#include "map.h"
#include "queue.h"
#include "random.h"
#include "set.h"
#include "simpio.h"
#include "vector.h"

using namespace std;
static void welcome();
static void readFile(HashMap<Vector<string>,Vector<string> > & gramMap, ifstream & input, int N);

int main() {
    setConsoleSize(750, 450);
    setConsoleFont("Courier New-16");
    setConsoleEcho(true);
    welcome();
    string filename = getLine("Input file? "); // hamlet.txt
    //string filename = "tiny.txt"; // test unit
    ifstream input;
    input.open(filename.c_str());
    if (input.fail()) cout << "fail to open " << filename << endl;
    int N = stringToInteger(getLine("Value of N? ")); // 3
    //int N = 3; // test unit

    HashMap<Vector<string>,Vector<string> > gramMap;


    readFile(gramMap, input, N);
    while (true)
    {
    cout << endl;
    int wordNumber = stringToInteger(getLine("# of random words to generate (0 to quit)? "));
    if (wordNumber == 0)break;
    cout << "... ";
    Vector<string> window = gramMap.keys()[randomInteger(0,gramMap.size()-1)]; // randomly chosen key
    for (int i = 0; i < wordNumber; i++)
    {
        cout << window[0] << " ";
        string temp = gramMap[window][randomInteger(0,gramMap[window].size()-1)];
        for (int j = 0; j < window.size()-1; j++)
            window[j] = window[j+1];
        window[window.size()-1] = temp;
    }
    cout << "..." << endl;
    }
    // TODO: Finish the program!


    cout << "Exiting." << endl;
    return 0;
}

static void welcome()
{
    cout << "Welcome to CS 106B Random Writer (aka 'N-Grams')." << endl;
    cout << "This program generates random text based on a document." << endl;
    cout << "Give me an input file and an 'N' value for groups" << endl;
    cout << "of words, and I'll generate random text for you." << endl;
    cout << endl;
}

static void readFile(HashMap<Vector<string>,Vector<string> > & gramMap, ifstream & input, int N)
{
    Vector<string> window;
    string line;
    Vector<string> frontWord;
    // make the window full at first
    while(window.size() < N-1)
    {
        input >> line;
        window.add(line);
    }
    frontWord = window;
    while (true)
    {
        input >> line;
        if (input.fail()) break;
        gramMap[window].add(line);
        // update window vector
        for (int i = 0; i < window.size()-1; i++)
            window[i] = window[i+1];
        window[window.size()-1] = line;
    }
    // wraps around
    for (int i = 0; i < frontWord.size(); i++)
    {
        gramMap[window].add(frontWord[i]);
        for (int i = 0; i < window.size()-1; i++)
            window[i] = window[i+1];
        window[window.size()-1] = frontWord[i];
    }


}
