#include "Items.h"

Items::Items(const string& _name, int _value) : m_name(_name), m_value(_value) {} //Constructor with parameters

int Items::getValue() const 
{
  return m_value;
}

string Items::getName() const
{
	return m_name;
}