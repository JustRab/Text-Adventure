#pragma once
#include "Commons.h"
class Enemy;


class FactoryEnemy  
{
    public:
      virtual Enemy* createEnemy(const string& name, const int& health, const int& damage) = 0; //Virtual function for the creation of the enemy
};

class ConcreteEnemy : public Enemy 
{
    private:
      int m_health; 
      string m_name; 
      int m_damage; 

      
    public:
      ConcreteEnemy(const string& name, int health, int damage) : 
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

      string getName() override 
      {
        return m_name;
      }

      int getDamage() override 
      {
        return m_damage;
      }

      void setHealth(int _h) override 
      {
        m_health += _h;
      }
};


class ConcreteEnemyFactory : public FactoryEnemy  
{
    public:
      Enemy* createEnemy(const string& name, const int& health, const int& damage) override  
      {
        return new ConcreteEnemy(name, health, damage); //Returns a new enemy
      }
};