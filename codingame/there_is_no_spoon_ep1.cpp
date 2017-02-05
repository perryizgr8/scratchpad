#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef std::vector< std::vector<int> > matrix;
//matrix name(sizeX, std::vector<int>(sizeY));

pair<int, int> find_right_nbr(matrix grid, int x, int y)
{
    cerr << "finding right_nbr of " << x <<"," << y << endl;
    int width = grid.size();
    int height = grid[0].size();
    cerr << "h=" << height << " w=" << width << endl;
    pair <int, int> coord;
    
    for (x++; x < width; x++) {
        if (grid[x][y] != -1) {
            cerr << "found nbr " << x << "," << y << endl;
            coord = make_pair(x, y);
            return coord;
        }
    }
    
    //no nbr found
    coord = make_pair(-1, -1);
    return coord;
}

pair<int, int> find_bot_nbr(matrix grid, int x, int y)
{
    cerr << "finding bot_nbr of " << x <<"," << y << endl;
    int width = grid.size();
    int height = grid[0].size();
    cerr << "h=" << height << " w=" << width << endl;
    pair <int, int> coord;
    
    for (y++; y < height; y++) {
        if (grid[x][y] != -1) {
            cerr << "found nbr " << x << "," << y << endl;
            coord = make_pair(x, y);
            return coord;
        }
    }
    
    //no nbr found
    coord = make_pair(-1, -1);
    return coord;
}

void print_grid(vector<vector<int>> grid, int width, int height)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cerr << grid[i][j];
        }
        cerr << endl;
    }
}

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    matrix grid(width, vector<int>(height));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            //cerr << "i=" << i << " j=" << j << endl;
            char val;
            cin >> val;
            cerr << "i=" << i << " j=" << j << " val=" << val << endl;
            if (val == '.') {
                cerr << "dot" << endl;
                grid[j][i] = -1;
            }
            else if (val == '0') {
                cerr << "zero" << endl;
                grid[j][i] = 0;
            }
        }
    }

    //print_grid(grid, width, height);

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            if (grid[x][y] != -1) {
                //print node
                cout << x << " " << y << " ";
                
                //find right nbr
                auto coord = find_right_nbr(grid, x, y);
                
                //print right nbr
                cout << coord.first << " " << coord.second << " ";
                
                //find bottom nbr
                coord = find_bot_nbr(grid, x, y);
                
                //print bottom nbr
                cout << coord.first << " " << coord.second << " " << endl;
            }
        }
    }


    // Three coordinates: a node, its right neighbor, its bottom neighbor
    //cout << "0 0 1 0 0 1" << endl;
}