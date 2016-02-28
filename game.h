#ifndef GAME_H_
#define GAME_H_

#include <string>

using namespace std;

//-------------------------------------------------
// Struct to hold the item and quantity for the
// players inventory
//-------------------------------------------------
struct inventorySystem
{
    string item;
    int quantity;
};

//---------------------------------------------------------
// Enum to hold the type of ores
//---------------------------------------------------------
enum ore
{
  tin = 0,
  copper,
  iron,
  coal,
  gold,
  mithril,
  adamant,
  rune
};

//---------------------------------------------------------
// Class for the main game logic
//---------------------------------------------------------
class game
{
    //-----------------------------------------------------
    // PUBLIC
    //-----------------------------------------------------
    public:
        //-------------------------------------------------
        // CONSTRUCTOR / DESTRUCTOR
        //-------------------------------------------------
        game();
        ~game();

        //-------------------------------------------------
        // GAME METHODS
        //-------------------------------------------------
        void levelUp( void );
        void pickupItem( void );
        void damage(int damage);
        void attack(int damage);
        void mine(ore m_ore);
        void craft( void );
        int menu( void );

        //-------------------------------------------------
        // GET METHODS
        //-------------------------------------------------
        void getInventory( void );
        void getStats( void );
        int getHealth( void );
        int getLevel( void );
        string getName( void );

        //-------------------------------------------------
        // SET METHODS
        //-------------------------------------------------
        void setName(string input);
        void setHealth(int input);
        void setLevel(int input);

        //-------------------------------------------------
        // DESIGN METHODS
        //-------------------------------------------------
        void border( int option );
        void clear( void );
        
    //-----------------------------------------------------
    // PRIVATE
    //-----------------------------------------------------
    private:
        //-------------------------------------------------
        // Holds character name
        //-------------------------------------------------
        string      name;

        //-------------------------------------------------
        // Inventory array controllers
        //-------------------------------------------------
        inventorySystem  *inventory;
        int              QtyEnd;
        int              itemEnd;

        //-------------------------------------------------
        // Character stats
        //-------------------------------------------------
        int         level;
        int         health;
};

#endif /* GAME_H_ */
