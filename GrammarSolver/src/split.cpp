/*
 * CS 106B Grammar Solver
 * This file contains a helpful 'split' function that you can call on a string
 * to break it into a vector of smaller tokens.
 */

#include "split.h"
#include "tokenscanner.h"

static const string CHARS = "<>+-_?!.,@#$%^&*()[]{}/\\;:|='\" ";

/*
 * see split.h for documentation
 */
Vector<string> split(string s, string delimiter) {
    // initialize a token scanner to include all chars not in the delimiter
    TokenScanner scan(trim(s));
    for (int i = 0; i < (int) CHARS.length(); i++) {
        if (delimiter.find(CHARS[i]) == string::npos) {
            scan.addWordCharacters(string("") + CHARS[i]);
        }
    }
    scan.addOperator(delimiter);

    // chop up the tokens and put into vector
    Vector<string> result;
    while (scan.hasMoreTokens()) {
        string token = scan.nextToken();
        if (scan.getTokenType(token) == OPERATOR) { continue; }
        if (delimiter.find(" ") != string::npos
                && scan.getTokenType(token) == SEPARATOR) { continue; }
        token = trim(token);
        if (token.length() == 0) { continue; }

        result += trim(token);
    }
    return result;
}
