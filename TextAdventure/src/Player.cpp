#include "Player.h"
#include "Enemy.h"

void Player::attack(Enemy*& _e) 
{
    if (_e != nullptr) //If the enemy isnt null
    {
	    int damage = -20; //Damage dealt by the player
	    _e->setHealth(damage); //Health is substracted from the enemy
	    cout << m_name << " attacks " << _e->getName() << " and hits it for " << damage << endl; //Prints the damage dealt
    }
    else //If the enemy is null
    {
	    cout << "Nothing to attack..." << endl;
	    cout << "I'm glad." << endl;
    }
}

void Player::combat(Enemy* e_foe) {
    cout << "There is a " << e_foe->getName() << " in front of me!" << endl; //Prints the enemy name

    while (m_health > 0 && e_foe->getHealth() > 0) //While the player and the enemy still have health the loop will repeat 
    {
        int choice;
        cout << "What should I do? (1) To attack or (2) To use an item: ";
        cin >> choice;

        if (choice == 1) //If the player attacks 
        {
          attack(e_foe);
          if (e_foe->getHealth() > 0) //If the enemy is still alive, it attacks
          {
            e_foe->attack(this); //The enemy attacks the player
          }
        }
        else if (choice == 2 ) //Else if the player uses an item
        {
          consumePotion(); //The player consumes a potion
        }

        cout << "My health: " << m_health << " & My foe health: " << e_foe->getHealth() << endl;
    }

  if (m_health <= 0) //If the player looses the battle
  {
    cout << "\nI don't feel so good. I guess this is the end..." << endl;
    exit(0);
  }
  else //If the player wins the battle
  {
    m_health += 30; //The player recovers some health
    cout << "\nI won and got some energy from the battle" << endl;
  }
}

int Player::getHealth() //Returns the player health
{
  return m_health;
}

void Player::pickUpItem(const Items& obj) //Function that allows the player to pick up objects 
{
  cout << "I found a " << obj.getName()<< "!" << endl; //Prints the name of the object
  m_inventory.push_back(obj); //Adds the object to the inventory
}

bool Player::hasItem(const string& objName) const //Function that checks if the player has an object
{
  for (const auto& obj : m_inventory) //"auto" is used as an easier way to declare "vector"s 
  { 
    if (obj.getName() == objName) //If the vector has a value named after the object named 
    {
      return true; //Returns true
    }
  }
  return false; //Returns false
}

void Player::consumePotion() {
  for (auto i = m_inventory.begin(); i != m_inventory.end(); ++i) //Searchs for a potion in the inventory
  { 
    if (i->getName() == "Potion") //If the vector has a value named "Potion"
    {
      m_health += i->getValue(); //The player recovers health
      m_inventory.erase(i); //The potion is erased from the inventory

      cout << "I drank a potion. I got some of my health back!" << endl; //Prints that the player drank a potion
    }
  }
  cout << "I don't have any potions left in my inventory..." << endl; //Prints that the player doesnt have any potions left
}

void Player::setName(string name) //Function that sets the player name
{
  m_name = name;
}