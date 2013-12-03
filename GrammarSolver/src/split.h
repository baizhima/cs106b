/*
 * CS 106B Grammar Solver
 * This file declares a helpful 'split' function that you can call on a string
 * to break it into a vector of smaller tokens.
 */

#ifndef _split_h
#define _split_h

#include <string>
#include "vector.h"

/*
 * Breaks apart the given string 's' into a vector of smaller strings, using
 * the given delimiter as a separator.  The delimiters themselves are not
 * included in the resulting vector.
 *
 * Example: split("the|quick brown|||fox|", "|") returns {"the", "quick brown", "fox"}.
 * Example: split("a b . c.d", ".") returns {"a b ", " c", "d"}.
 */
Vector<string> split(string s, string delimiter);

#endif
