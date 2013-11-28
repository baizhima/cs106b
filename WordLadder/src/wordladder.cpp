// Programming Assignment 2, Word Ladder
// CS 106B Programming Abstraction, Fall 2013, Stanford University
// Author Shan Lu, Renmin University of China, contact lushan.frank@gmail.com
// Last updated Nov. 28th, 2013

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
#include "stack.h"
#include "vector.h"

using namespace std;

static void wordLadder(string w1, string w2);
static void readDict(Set<string> & d);

int main() {
    setConsoleSize(750, 450);
    setConsoleFont("Courier New-16");
    setConsoleEcho(true);

    cout << "Welcome to CS 106B Word Ladder." << endl;
    cout << "If you give me two English words, I will transform the" << endl;
    cout << "first into the second by changing one letter at a time." << endl;
    cout << endl;

    cout << "Please type two words: ";
    string word1;
    string word2;
    cin >> word1 >> word2;
    word1 = toLowerCase(word1);
    word2 = toLowerCase(word2);

    wordLadder(word1,word2);


    cout << "Have a nice day." << endl;
    return 0;
}

static void wordLadder(string w1, string w2)
{
    // English word dictionary
    Set<string> wordDictionary;
    readDict(wordDictionary);
    // create an empty queue of stacks.
    Queue<Stack<string> > qLadder;

    // create/add a stack containing {w1} to the queue.
    Stack<string> firstStack;
    firstStack.push(w1);
    qLadder.enqueue(firstStack);
    // keep track of the set of words that have already been used in a ladder
    Set<string> wordSet;
    wordSet.add(w1);
    // while the queue is not empty:
    while (!qLadder.isEmpty())
    {
        // dequeue the partial-ladder stack from the front of the queue.
        Stack<string> stack = qLadder.dequeue();
        string word = stack.peek();
        if (word == w2)
        {
            /* if the word on top of the stack is the destination word:
               hooray! output the elements of the stack as the solution. */
            cout << "Ladder from " << w2 << " back to "<< w1 << ":" << endl;
            while(!stack.isEmpty())
            {
                cout << stack.pop();
                if (!stack.isEmpty())
                    cout << " ";
                else
                    cout << endl;
            }
            return;
        }
        else
        {
            /*
                otherwise:
                for each valid English word that is a "neighbor" (differs by 1 letter)
                of the word on top of the stack:
                if that neighbor word has not already been used in a ladder before:
                create a copy of the current ladder stack.
                put the neighbor word on top of the copy stack.
                add the copy stack to the end of the queue.
              */
            for (int i = 0; i < (int)word.length(); i++)
                for (int j = 0; j < 26; j++)
                {
                    string candidate = word;
                    char letter = 'a' + j;
                    candidate[i] = letter;
                    if (!wordSet.contains(candidate)
                            && wordDictionary.contains(candidate))
                    {
                        wordSet.add(candidate); // set operation might be wrong
                        Stack<string> newStack = stack;
                        newStack.push(candidate);
                        qLadder.enqueue(newStack);
                    }

                }
        }
    }

    cout << "No word ladder found from ";
    cout << w2;
    cout << " back to ";
    cout << w1;
    cout << "." << endl;
}

static void readDict(Set<string> & dict)
{
    ifstream input;
    input.open("dictionary.txt");
    if (!input.fail())
    {
        string line;
        while (true)
        {
            input >> line;
            if (input.fail()) break;
            dict.add(line);
        }
    }
    else
        cout << "failed to open dictionary.txt" << endl;
}
