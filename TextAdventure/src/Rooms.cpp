#include "Rooms.h"

Room::Room(const string& _name, const string& _description)
  : m_name(_name), m_descript(_description) {} //Constructor with parameters

string Room::getDescription() const //Returns the description of the room
{
  return m_descript;
}

string Room::getName() const //Returns the name of the room
{
  return m_name;
}