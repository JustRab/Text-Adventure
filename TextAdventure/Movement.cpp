#include "Movement.h"

Movement::Movement(bool _moveUp, bool _moveDown, bool _moveLeft, bool _moveRight) :
  m_moveUp(_moveUp), m_moveDown(_moveDown), m_moveLeft(_moveLeft), m_moveRight(_moveRight)  //Constructor with parameters
{
}

Movement::~Movement() //Destructor
{
}

void Movement::MoveChoice() //Function to move
{
  cout << "Where do you go now? " << endl;
  cout << "(1) Up\n";
  cout << "(2) Down\n";
  cout << "(3) Left\n";
  cout << "(4) Right\n";
  cin >> m_choice;

  switch (m_choice)
  {
  case 1:
    MoveUp();
    break;

  case 2:
    MoveDown();
    break;

  case 3:
    MoveLeft();
    break;

  case 4:
    MoveRight();
    break;

  default:
    cout << "Sadly, that is not an option\n" << endl;
    break;
  }
}

void Movement::MoveUp() //Function to move up
{
  if (m_moveUp) 
  {
    cout << "I moved directly to the front just to find another room.\n";
  }
  else 
  {
    cout << "There is nothing in the front. I should try another way.\n";
    MoveChoice();
  }
}

void Movement::MoveDown() //Function to move down
{
    if (m_moveDown) 
    {
        cout << "I try going behind me. Looks like the room from before changed.\n";
    }
    else 
    {
        cout << "Going backwards doesn't seem right. I need to find an exit.\n";
        MoveChoice();
    }
}

void Movement::MoveLeft() //Function to move left
{
  if (m_moveLeft) 
  {
    cout << "I moved to the left. There seems to be another room.\n";
  }
  else 
  {
    cout << "There is nothing in the left. I should try looking in another direction.\n";
    MoveChoice();
  }
}

void Movement::MoveRight() //Function to move right
{
  if (m_moveRight) 
  {
    cout << "I moved to the right with high hopes. Seems like another room.\n";
  }
  else 
  {
    cout << "There is no use, since there is nothing in the right. I should find another way.\n";
    MoveChoice();
  }
}



int Movement::getChoice() //Function to get the choice
{
  return m_choice;
}