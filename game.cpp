#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "game.h"

using namespace std;

//---------------------------------------------------------
// Constructor, initializes player stats and inventory
//---------------------------------------------------------
game::game()
{
    name        = "";
    level       = -1;
    health      = -1;
    inventory   = new inventorySystem[5];
    QtyEnd      = 0;
    itemEnd     = 0;
}

//---------------------------------------------------------
// Destructor releases memory allocated by new inventory
//---------------------------------------------------------
game::~game()
{
    delete[] inventory;
}

//---------------------------------------------------------
// Returns character inventory
//---------------------------------------------------------
void game::getInventory()
{
    QtyEnd  = 0;
    itemEnd = 0;

    border(3);
    cout << setfill(' ') << setw(1) << "|" << setw(10)
         << left << "Item"  << setw(1) << "|" << setw(3)
         << "Qty" << setw(1) << "|" << endl;
    border(3);

    for (int i = 0; i < 5; i++)
    {
         cout << setfill(' ') << setw(1) << "|" << setw(10)
              << left << inventory[itemEnd++].item << setw(1)
              << "|" << setw(3) << inventory[QtyEnd++].quantity
              << setw(1) << "|" << endl;
         border(3);
    }

}

//---------------------------------------------------------
// Returns character health
//---------------------------------------------------------
int game::getHealth()
{
    return health;
}

//---------------------------------------------------------
// Returns character level
//---------------------------------------------------------
int game::getLevel()
{
    return level;
}

//---------------------------------------------------------
// Returns character name
//---------------------------------------------------------
string game::getName()
{
    return name;
}

//---------------------------------------------------------
// Sets character name
//---------------------------------------------------------
void game::setName(string input)
{
    name = input;
}

//---------------------------------------------------------
// Sets character health
//---------------------------------------------------------
void game::setHealth(int input)
{
    health = input;
}

//---------------------------------------------------------
// Sets character level
//---------------------------------------------------------
void game::setLevel(int input)
{
    level = input;
}

//---------------------------------------------------------
// Levels up the character
//---------------------------------------------------------
void game::levelUp()
{
    level = level + 1;
}

void game::mine(ore m_ore)
{
  switch (m_ore)
  {
    case tin:
      cout << "Tin" << endl;
      break;

    case copper:
      cout << "Copper" << endl;
      break;

    case iron:
      cout << "Iron" << endl;
      break;

    case coal:
      cout << "Coal" << endl;
      break;

    case gold:
      cout << "Gold" << endl;
      break;

    case mithril:
      cout << "Mithril" << endl;
      break;

    case adamant:
      cout << "adamant" << endl;
      break;

    case rune:
      cout << "Rune" << endl;
      break;
  }
}

//---------------------------------------------------------
// Adds item to the inventory
//---------------------------------------------------------
void game::pickupItem()
{
    QtyEnd  = 0;
    itemEnd = 0;

    inventory[itemEnd++].item       = "potion";
    inventory[QtyEnd++].quantity    = 4;
    inventory[itemEnd++].item       = "Axe";
    inventory[QtyEnd++].quantity    = 1;
    inventory[itemEnd++].item       = "Legs";
    inventory[QtyEnd++].quantity    = 2;
    inventory[itemEnd++].item       = "Chest";
    inventory[QtyEnd++].quantity    = 1;
    inventory[itemEnd++].item       = "Dagger";
    inventory[QtyEnd++].quantity    = 1;
}

//---------------------------------------------------------
// Returns the player stats
//---------------------------------------------------------
void game::getStats( void )
{
  border(2);
  cout << setfill(' ') << setw(1) << "|" << setw(15) 
       << left << "Name" << setw(1) << "|" 
       << setw(15) << left << "Health" << setw(1) 
       << "|"  << setw(5) << left << "Level" << setw(1)
       << "|" << endl;
  border(2);
  cout << setfill(' ') << setw(1) << "|" << setw(15) 
     << left << getName() << setw(1) << "|" 
     << setw(15) << left << getHealth() << setw(1) 
     << "|"  << setw(5) << left << getLevel() << setw(1)
     << "|" << endl;
  border(2);

}

//---------------------------------------------------------
// Damages player health
//---------------------------------------------------------
void game::damage(int damage)
{
    health = health - damage;
}

//---------------------------------------------------------
// Border's
//---------------------------------------------------------
void game::border( int option )
{
  if (option == 1)
  {
    //-----------------------------------------------------
    // Menu
    //-----------------------------------------------------
    cout << setfill('-') << setw(1) << "+" << setw(18)
        << "-" << setw(1) << "+" << endl;
  }
  else if (option == 2)
  {
    //-----------------------------------------------------
    // Stats
    //-----------------------------------------------------
    cout << setfill('-') << setw(1) << "+" << setw(15) 
      << "-" << setw(1) << "+" << setw(15) << "-" 
      << setw(1) << "+" << setw(5) << "-" << setw(1) 
      << "+" << endl;
  }
  else
  {
    //-----------------------------------------------------
    // Inventory
    //-----------------------------------------------------
    cout << setfill('-') << setw(1) << "+" << setw(10)
         << "-" << setw(1) << "+" << setw(3) << "-" 
         << setw(1) << "+" <<endl;
  }
}

//---------------------------------------------------------
// Print 10 blank lines to clear screen
//---------------------------------------------------------
void game::clear( void )
{ 
    for (int i = 0; i < 100; i++)
    {
      cout << endl; 
    }
}

//---------------------------------------------------------
//  Main menu for the game, returns the choice to main
//---------------------------------------------------------
int game::menu()
{
  int choice = 0;

  border(1);
  cout << setfill(' ') << setw(1) << "|" << setfill(' ') 
       << setw(7) << " " << setw(11) << left << "Menu" 
       << setw(7) << "|" << endl;
  border(1);
  cout << setfill(' ') << setw(1) << "|" << setfill(' ') 
       << setw(1) << " " << setw(17) << left << "[1] Show stat's" 
       << setfill(' ') << setw(1) << "|" << endl;
  border(1);
  cout << setfill(' ') << setw(1) << "|" << setfill(' ') 
       << setw(1) << " " << setw(17) << left << "[2] Inventory" 
       << setfill(' ') << setw(1) << "|" << endl;
  border(1);
  cout << setfill(' ') << setw(1) << "|" << setfill(' ') 
       << setw(1) << " " << setw(17) << left << "[3] Mine"
       << setfill(' ') << setw(1) << "|" << endl;
  border(1);
  cout << setfill(' ') << setw(1) << "|" << setfill(' ') 
       << setw(1) << " " << setw(17) << left << "[4] Forge"
       << setfill(' ') << setw(1) << "|" << endl;
  border(1);
  cout << setfill(' ') << setw(1) << "|" << setfill(' ') 
       << setw(1) << " " << setw(17) << left << "[5] Exit"
       << setfill(' ') << setw(1) << "|" << endl;
  border(1);

  cout << "--> ";
  cin >> choice;

  switch (choice)
  {
    case 1:
      getStats();
      break;
    case 2: 
      getInventory();
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      cout << "Thank you for playing" << endl;
      exit(1);
      break;
    default:
      cout << "Invalid option" << endl;
      break;
    }
  return choice;
}