#pragma once
#include "Commons.h"
#include "Rooms.h"

class Movement
{
	public:
		Movement(bool _moveUp, bool _moveDown, bool _moveLeft, bool _moveRight); //Constructor with parameters
		~Movement(); //Default destructor

		void MoveUp(); //Function for the player to move up

		void MoveDown(); //Function for the player to move down

		void MoveLeft(); //Function for the player to move left

		void MoveRight(); //Function for the player to move right

		void MoveChoice(); //Function for the player to choose where to move

		int getChoice(); //Returns the choice of the player

	private:
		bool m_moveUp; //Boolean for the player to move up
		bool m_moveDown; //Boolean for the player to move down
		bool m_moveLeft; //Boolean for the player to move left
		bool m_moveRight; //Boolean for the player to move right
		int m_choice = 0; //The choice of the player
};

