#pragma once
#include "Commons.h"
#include <string>
#include <vector>
#include "Foe.h"

class Level 
{
    public:
      Level(const string& name, const string& description); //Constructor with parameters

      string getDescription() const; //Returns the description of the room

      string getName() const; //Returns the name of the room

    private:
      string m_name; //Name of the room
      string m_descript; //Description of the room
      vector<Foe*> m_enemies; //Vector of enemies
};
