#pragma once
#include "Commons.h"
#include <string>
#include <vector>
#include "Enemy.h"

class Room 
{
    public:
      Room(const string& name, const string& description); //Constructor with parameters

      string getDescription() const; //Returns the description of the room

      string getName() const; //Returns the name of the room

    private:
      string m_name; //Name of the room
      string m_descript; //Description of the room
      vector<Enemy*> m_enemies; //Vector of enemies
};
