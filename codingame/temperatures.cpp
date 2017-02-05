#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    vector<int> temps, abstemps;
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    for(int i = 0; i < n; i++) {
        int tempo;
        cin >> tempo;
        temps.push_back(tempo);
        abstemps.push_back(abs(tempo));
    }

    if(temps.size() == 0) {
        cout << 0 << endl;
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    auto closer = min_element(begin(abstemps), end(abstemps));
    if(temps[closer - abstemps.begin()] >= 0) {
        cout << *closer << endl;
    }
    else {
        if(find(temps.begin(), temps.end(), *closer) != temps.end()) {
            cout << *closer << endl;
        }
        else {
            cout << -1 * *closer << endl;
        }
    }
}