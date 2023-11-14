#pragma once
#include "Commons.h"

class Items {
public:
  Items(const string& _name, int _value); //Constructor with parameters
  ~Items() = default; //Default destructor

  string getName() const; //Returns the name of the item
  int getValue() const; //Returns the value of the item

private:
  string m_name; //The name of the item
  int m_value; //The value of the item
};
