#pragma once
#include "Commons.h"
#include "Items.h"
class Foe;

class Player
{
	public:
		Player() = default; //Default constructor
		Player(string _name, int _health) : m_name(_name), m_health(_health) {}; //Constructor with parameters
		~Player() = default; //Default destructor

		void attack(Foe*& _e); //Function for the attack of the player

		void setHealth(int _h) //Function for the attack of the player  
		{
			m_health -= _h; 
		}

		int getHealth(); //Returns the health of the player

		string getName() //Returns the name of the player 
		{
			return m_name;
		}

		void setName(string name); //Sets the name of the player

		void  combat(Foe* e_foe); //Function for the combat of the player

		void pickUpItem(const Items& obj); //Function for the player to pick up an item

		bool hasItem(const string& objName) const; //Function for the player to check if he has an item

		void consumePotion(); //Function for the player to consume a potion

	private:
		int m_health = 100; //The health of the player
		string m_name = ""; //The default name of the player
		vector<Items> m_inventory; //The inventory of the player
};

