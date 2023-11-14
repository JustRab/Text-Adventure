#include "Level.h"

Level::Level(const string& _name, const string& _description)
  : m_name(_name), m_descript(_description) {} //Constructor with parameters

string Level::getDescription() const //Returns the description of the room
{
  return m_descript;
}

string Level::getName() const //Returns the name of the room
{
  return m_name;
}