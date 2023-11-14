#include "Enemy.h"
#include "Player.h"

void Enemy::attack(Player* _p)  
{
  if (_p != nullptr) //If the player isnt null
  {
    int damage = -20; //Damage dealt by the enemy
    _p->setHealth(damage); //Health is substracted from the player
    cout << "The " << m_name << " attacks you" << " and hits you for " << damage << endl; //Prints the damage dealt
  }
  else //If the player is null 
  {
    cout << "Nothing to attack" << endl; 
  }
}