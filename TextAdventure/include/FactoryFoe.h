#pragma once
#include "Commons.h"
class Foe;


class FactoryFoe  
{
    public:
      virtual Foe* createEnemy(const string& name, const int& health, const int& damage) = 0; //Virtual function for the creation of the enemy
};

class LogicFoe : public Foe 
{
    private:
      int m_health; 
      string m_name; 
      int m_damage; 

      
    public:
      LogicFoe(const string& name, int health, int damage) : 
        m_name(name), m_health(health), m_damage(damage) {} //Constructor with parameters

      void attack(Player* _p) override 
      {
        if (_p != nullptr) {
          int damage = 20; //Damage dealt by the enemy
          _p->setHealth(m_damage); //Health is substracted from the player
          cout << "The " << m_name << " attacks you" << " and hits you for " << damage << endl; //Prints the damage dealt
        }
      }

      int getHealth() override 
      {
        return m_health;
      }
      void setHealth(int _h) override
      {
          m_health += _h;
      }

      int getDamage() override
      {
          return m_damage;
      }

      string getName() override 
      {
        return m_name;
      }
};


class LogicFoeFactory : public FactoryFoe 
{
    public:
      Foe* createEnemy(const string& name, const int& health, const int& damage) override  
      {
        return new LogicFoe(name, health, damage); //Returns a new enemy
      }
};