#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();
    
    int cur_x = initialTX;
    int cur_y = initialTY;

    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        int norsou = lightY - cur_y;
        int easwes = lightX - cur_x;
        std::string mov;
        if (norsou < 0) {
            mov.append("N");
            cur_y--;
        }
        else if (norsou > 0) {
            mov.append("S");
            cur_y++;
        }
        if (easwes < 0) {
            mov.append("W");
            cur_x--;
        }
        else if (easwes > 0) {
            mov.append("E");
            cur_x++;
        }


        // A single line providing the move to be made: N NE E SE S SW W or NW
        cout << mov << endl;
    }
}