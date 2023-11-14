#include "Commons.h"
#include "Foe.h"
#include "Player.h"
#include "FactoryFoe.h"
#include "Level.h"
#include "Movement.h"

//Function prototypes for the rooms
void FirstRoom(Player* player);
void SecondRoom(Player* player, Foe* enemy);
void ThirdRoom(Player* player);
void FourthRoom(Player* player, Foe* enemy);
void FifthRoom(Player* player, Foe* enemy);
void SixthRoom(Player* player, Foe* enemy);
void SeventhRoom(Player* player, Foe* enemy);
void EighthRoom(Player* player, Foe* enemy);
void NinethRoom(Player* player);
void FinalRoom(Player* player, Foe* enemy);

//Create a player object
string pName; //Player name
Player* Liam = new Player(pName, 150); //Player starts with 150 health points

//Create a factory object for each enemy
LogicFoeFactory enemySentinel;
LogicFoeFactory enemyGuard;
LogicFoeFactory enemyDirector;
LogicFoeFactory enemyMimic;

//Create different objects from the class Enemy
Foe* Mimic = enemyMimic.createEnemy("Me?", 80, 8);
Foe* Sentinel = enemySentinel.createEnemy("City Sentinel", 100, 15);
Foe* Guard = enemyGuard.createEnemy("City Guard", 90, 18);
Foe* Director = enemyDirector.createEnemy("Director", 175, 25);

//Create different objects from the class Items
Items potion("Potion", 75);
//Mision Item:
Items guardKey("Guard's Key", 1);

int main() 
{
  cout << "Ugh... my head. I need to remember." << endl;
  cout << "What is my name?" << endl;
  cin >> pName;
  Liam->setName(pName);

  cout << "My name is " << Liam->getName() << endl;
  cout << "I need to get out of here. For some reason I don't feel safe in this place." << endl;

  FirstRoom(Liam);
  
  delete Liam;

  return 0;
}

void FirstRoom(Player* player) 
{
  //Create a room object
  Level room1("Lonely Cell", "It seems like a prision cell. There doesn't seem to be anyone in this room except for me. The front door is open, is my only way out right now.");
  cout << "------------------------------------------" << endl;
  cout << "Room 1: " << room1.getName() << endl;
  cout << "------------------------------------------" << endl;
  cout << room1.getDescription() << endl;
  cout << "------------------------------------------" << endl;

  //Create a movement object
  Movement movement(true, false, false, false);
  movement.MoveChoice(); //The player chooses where to move
  if (movement.getChoice() == 1) 
  {
    SecondRoom(Liam, Sentinel); //The player moves to the next room
  }
}

void SecondRoom(Player* player, Foe* enemy)
{
  Level room2("Not so lonely hallway", "I can barely see two doors in the end of the hallway. But there seems to be something moving too.");
  cout << "------------------------------------------" << endl;
  cout << "\nRoom 2: " << room2.getName() << endl;
  cout << "------------------------------------------" << endl;
  cout << room2.getDescription() << endl;
  cout << "------------------------------------------" << endl;
  player->combat(enemy);

  Movement movement(false, false, true, true);
  movement.MoveChoice();
  if (movement.getChoice() == 3) 
  {
    ThirdRoom(Liam);
  } 
  else if (movement.getChoice() == 4) 
  {
    FourthRoom(Liam, Sentinel);
  }
}

void ThirdRoom(Player* player) 
{
    Level room3("Nurse Office", "There is nothing much of interest. I can see something glowing in the desk tho. I take it.");
  cout << "------------------------------------------" << endl;
  cout << "\nRoom 3: " << room3.getName() << endl;
  cout << "------------------------------------------" << endl;
  cout << room3.getDescription() << endl;
  cout << "------------------------------------------" << endl;
  Liam->pickUpItem(potion);

  Movement movement(false, false, true, false);
  movement.MoveChoice();
  if (movement.getChoice() == 3) 
  {
    FifthRoom(Liam, Guard);
  }
}

void FourthRoom(Player* player, Foe* enemy) 
{
    Level room4("Cell's room exit", "I can see the exit of the cell's room right in fornt of me! Suddenly an alarm goes off and I can see something approaching me violently!");
  cout << "------------------------------------------" << endl;
  cout << "\nRoom 4: " << room4.getName() << endl;
  cout << "------------------------------------------" << endl;
  cout << room4.getDescription() << endl;
  cout << "------------------------------------------" << endl;
  delete enemy;
  enemy = enemySentinel.createEnemy("City Sentinel", 100, 15);
  player->combat(enemy);

  Movement movement(true, false, false, false);
  movement.MoveChoice();
  if (movement.getChoice() == 1) 
  {
    SeventhRoom(Liam, Mimic);
  }
}

void FifthRoom(Player* player, Foe* enemy) 
{
  Level room5("Observation Tower Entrance", "The door to the observation tower was locked. I hear footsteps right behind me!");
  cout << "------------------------------------------" << endl;
  cout << "\nRoom 5: " << room5.getName() << endl;
  cout << "------------------------------------------" << endl;
  cout << room5.getDescription() << endl;
  cout << "------------------------------------------" << endl;

  delete enemy;
  enemy = enemyGuard.createEnemy("Guard of The Tower", 90, 18);
  player->combat(enemy);
  cout << "I can see two doors, one in front of me leading to the tower and another one to my left." << endl;

  Movement movement(true, false, true, false);
  movement.MoveChoice();
  if (movement.getChoice() == 1) 
  {
    EighthRoom(Liam, Mimic);
  }
  else if (movement.getChoice() == 3)
  {
      SixthRoom(Liam, Guard);
  }
}

void SixthRoom(Player* player, Foe* enemy) 
{
  Level room6("Rainy Patio", "I can see some snacks and a potion in the benches. I take a potion. I can see someone getting near to me and doesn't seem friendly");
  cout << "------------------------------------------" << endl;
  cout << "\nRoom 6: " << room6.getName() << endl;
  cout << "------------------------------------------" << endl;
  cout << room6.getDescription() << endl;
  cout << "------------------------------------------" << endl;
  Liam->pickUpItem(potion);

  delete enemy;
  enemy = enemyGuard.createEnemy("Guard of the Patio", 75, 15);
  player->combat(enemy);
  cout << "The enemy dropped something" << endl;
  Liam->pickUpItem(guardKey);
  cout << "I think that I can enter that tower on my right with this key!" << endl;

  Movement movement(false, false, false, true);
  movement.MoveChoice();
  if (movement.getChoice() == 4) 
  {
     NinethRoom(Liam);
  }
}

void SeventhRoom(Player* player, Foe* enemy) 
{
  Level room7("Confusing Hallway", "It's a long hallway with a lot of mirrors. As I was leaving the hallway a strange figure jumped at me! I dodged its first attack, this foe looks exactly like me!");
  cout << "------------------------------------------" << endl;
  cout << "\nRoom 7: " << room7.getName() << endl;
  cout << "------------------------------------------" << endl;
  cout << room7.getDescription() << endl;
  cout << "------------------------------------------" << endl;
  Liam->pickUpItem(potion);

  delete enemy;
  enemy = enemyMimic.createEnemy("Me?", 40, 5);
  player->combat(enemy);
  cout << "That was a really weird battle. Glad it was over. The exit of this hallway to the patio is in the left side." << endl;

  Movement movement(false, false, true, false);
  movement.MoveChoice();
  if (movement.getChoice() == 3) 
  {
    SixthRoom(Liam, Guard);
  }
}

void EighthRoom(Player* player, Foe* enemy) 
{
  Level room8("Observation Tower - First Floor", "I entered the tower just to be surprised by a giant mirror blocking the stairs. I tried to move it gently but suddenly my reflection jumped out from the mirror!");
  cout << "------------------------------------------" << endl;
  cout << "\nRoom 8: " << room8.getName() << endl;
  cout << "------------------------------------------" << endl;
  cout << room8.getDescription() << endl;
  cout << "------------------------------------------" << endl;
  delete enemy;
  enemy = enemyMimic.createEnemy("Definitely not me", 50, 10);
  player->combat(enemy);

  Movement movement(true, false, false, false);
  movement.MoveChoice();
  if (movement.getChoice() == 1)
  {
    NinethRoom(Liam);
  }
}

void NinethRoom(Player* player) 
{
  Level room9("Observation Tower - Second Floor", "I finally reached the top of the tower, I can see a locked door in front of me. Maybe a guard's key can unlock it?");
  cout << "------------------------------------------" << endl;
  cout << "\nCuarto 9: " << room9.getName() << endl;
  cout << "------------------------------------------" << endl;
  cout << room9.getDescription() << endl;
  cout << "------------------------------------------" << endl;

  if (player->hasItem("Guard's Key")) {
    cout << "I got one from the guard in the patio. Now I can go outside!" << endl;
    Movement movement(true, false, false, false);
    movement.MoveChoice();
    if (movement.getChoice() == 1)
    {
        FinalRoom(Liam, Director);
    }
  }
  else 
  {
    cout << "I should go back and look for a key. Maybe the guard I can see in the patio has one?" << endl;
    Movement movement(false, true, false, false);
    movement.MoveChoice();
    if (movement.getChoice() == 2) 
    {
        SixthRoom(Liam, Guard);
    }
  }
}

void FinalRoom(Player* player, Foe* enemy) 
{
  Level roomF("Outer Walls - The End", "It's heavy raining, I can barely stand my feet. The walls are kinda thin so if I make a wrong move I'm dead. Before I can reach the stairs to the outside a shadow jumps in front of me. I have the feeling that this is not going to be an easy fight...");
  cout << "------------------------------------------" << endl;
  cout << "\nRoom 10: " << roomF.getName() << endl;
  cout << "------------------------------------------" << endl;
  cout << roomF.getDescription() << endl;
  cout << "------------------------------------------" << endl;
  delete enemy;
  enemy = enemyDirector.createEnemy("Jail Director", 175, 25);
  player->combat(enemy);
  cout << "Once defeated the jail director falls from the outer walls to the insides of the jail. I quickly get down using the stairs to the outside and finally I'm out\n";
  cout << "My name is " << pName << " and this is just the start of my new life as the only survivor of this crazy jail...";
}