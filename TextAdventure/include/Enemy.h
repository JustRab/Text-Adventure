#pragma once
#include "Commons.h"
class Player;

class Enemy
{
	public:
		Enemy() = default; //Default constructor
		Enemy(string _name, int _health) : m_name(_name), m_health(_health) {}; //Constructor with parameters
		~Enemy() = default; //Default destructor

		virtual void 
			attack(Player* _p) = 0; //Virtual function for the attack of the enemy

		virtual int 
			getHealth() = 0; //Virtual function for the health of the enemy

		virtual string 
			getName() = 0; //Virtual function for the name of the enemy

		virtual int 
			getDamage() = 0; //Virtual function for the damage of the enemy

		virtual void 
			setHealth(int _h)  
			{
			m_health += _h; //Virtual function for the health of the enemy
			}

	private:
		int m_health; //The health of the enemy
		string m_name = ""; //The name of the enemy
};
