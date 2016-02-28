#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "game.h"

using namespace std;

int main()
{
    game g;
    string input;

    cout << "+---------------------------------+" << endl;
    cout << "|-------Welcome to goblins--------|" << endl;
    cout << "+---------------------------------+" << endl;

    cout << "Enter a character name: ";
    cin >> input;
    cout << "Welcome : " << g.getName() << endl;

    g.setName(input);
    g.setLevel(1);
    g.setHealth(100);
    g.pickupItem();

    while (true)
    g.menu();

    return 0;
}
