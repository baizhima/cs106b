/*
 * File: console.cpp
 * -----------------
 * This file implements the console.h interface.
 */

#include <string>
#include "console.h"
#include "platform.h"
using namespace std;

static Platform *pp = getPlatform();
static bool consoleEcho = false;
static string consoleLogFile = "";

void clearConsole() {
   pp->clearConsole();
}

bool getConsoleEcho() {
   return consoleEcho;
}

string getConsoleLogFile() {
   return consoleLogFile;
}

void setConsoleEcho(bool echo) {
   consoleEcho = echo;
}

void setConsoleFont(const string & font) {
   pp->setConsoleFont(font);
}

void setConsoleLogFile(const string & filename) {
   consoleLogFile = filename;
}

void setConsoleSize(double width, double height) {
   pp->setConsoleSize(width, height);
}
