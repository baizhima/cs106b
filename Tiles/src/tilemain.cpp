/*
 * CS 106B Tiles
 * This client program uses your TileList class and contains the 'main'
 * function to set up the overall program's graphical user interface.
 * Your code should work properly with an unmodified version of this file.
 */

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "console.h"
#include "random.h"
#include "TileList.h"
#include "gwindow.h"
#include "gobjects.h"
#include "gevents.h"
using namespace std;

// constants
static const int WINDOW_WIDTH = 600;
static const int WINDOW_HEIGHT = 400;
static const int MIN_SIZE = 20;
static const int MAX_SIZE = 100;
static const int MIN_COLOR = 50;
static const int MAX_COLOR = 255;
static const int TILE_COUNT = 50;
static const bool RANDOM = false;   // set to false for repeatable output

// function prototype declarations
void addRandomTile(TileList& tlist);
bool processEvent(TileList& tlist);

int main() {
    setConsoleEcho(true);
    setConsolePrintExceptions(true);

    // possibly use the same random numbers every time for testing
    if (!RANDOM) {
        setRandomSeed(42);
    }

    GWindow window(WINDOW_WIDTH, WINDOW_HEIGHT);
    window.setWindowTitle("CS 106B Tiles");

    // place several random tiles onto the screen
    TileList tlist;
    for (int i = 0; i < TILE_COUNT; i++) {
        addRandomTile(tlist);
    }
    tlist.drawAll(window);

    // event loop waits for user to click on tiles
    while (true) {
        if (processEvent(tlist)) {
            window.clear();
            tlist.drawAll(window);
        } else if (!window.isVisible()) {
            // if the user closes the main graphical window, shut down
            window.close();
            exitGraphics();
            break;
        }
    }

    return 0;
}

/*
 * Creates a new tile with a random x/y position, width, height, and color,
 * and adds it to the given tile list.
 */
void addRandomTile(TileList& tlist) {
    Tile tile;
    tile.width = randomInteger(MIN_SIZE, MAX_SIZE);
    tile.height = randomInteger(MIN_SIZE, MAX_SIZE);
    tile.x = randomInteger(0, WINDOW_WIDTH - tile.width - 1);
    tile.y = randomInteger(0, WINDOW_HEIGHT - tile.height - 1);
    int r = randomInteger(MIN_COLOR, MAX_COLOR);
    int g = randomInteger(MIN_COLOR, MAX_COLOR);
    int b = randomInteger(MIN_COLOR, MAX_COLOR);
    ostringstream colorout;
    colorout << "#" << setbase(16) << setfill('0') << r << g << b;
    tile.color = colorout.str();
    tlist.addTile(tile);
}

/*
 * Waits for one mouse or window event from the graphical subsystem,
 * then handles the event appropriately if it is a mouse button press:
 *   - A left-click is a 'raise' action.
 *   - A shift-left-click is a 'lower' action.
 *   - A right-click (or ctrl-click) is a 'delete' action.
 *   - A shift-right-click (or shift-ctrl-click) is a 'delete all' action.
 * Returns true if an event was processed, or false if not.
 */
bool processEvent(TileList& tlist) {
    GEvent event = waitForEvent(MOUSE_EVENT | KEY_EVENT | WINDOW_EVENT);
    int eventClass = event.getEventClass();
    int type = event.getEventType();
    int mod = event.getModifiers();

    if (eventClass == MOUSE_EVENT) {
        GMouseEvent mouseEvent(event);
        if (type == MOUSE_PRESSED) {
            int x = (int) mouseEvent.getX();
            int y = (int) mouseEvent.getY();
            bool shift = (mod & SHIFT_DOWN) || (mod & ALT_DOWN) | (mod & META_DOWN);
            bool ctrl = mod & CTRL_DOWN;
            bool leftButton = mod & BUTTON1_DOWN;
            bool rightButton = !leftButton || ctrl;
            if (rightButton) {
                if (shift) {
                    tlist.removeAll(x, y);
                } else {
                    tlist.remove(x, y);
                }
            } else {   // left button
                if (shift) {
                    tlist.lower(x, y);
                } else {
                    tlist.raise(x, y);
                }
            }
            return true;
        }
    } else if (eventClass == KEY_EVENT) {
        // the only key press we listen for is 'N' to create a new random tile
        GKeyEvent keyEvent(event);
        if (type == KEY_PRESSED) {
            if (tolower(keyEvent.getKeyChar()) == 'n') {
                addRandomTile(tlist);
                return true;
            }
        }
    }

    return false;
}
