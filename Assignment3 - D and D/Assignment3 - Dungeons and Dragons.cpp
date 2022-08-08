#include <iostream>
#include <time.h>
#include <memory>
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"
using namespace std;


int main()
{
	srand(time(NULL));
	shared_ptr<Warrior> WPTR = make_shared<Warrior>();
	cout << "------------------------------------------------------" << endl;
	shared_ptr<Mage> MPTR = make_shared<Mage>();
	cout << "------------------------------------------------------" << endl;
	WPTR->statDisplay();
	cout << "------------------------------------------------------" << endl;
	MPTR->statDisplay();
	

	while (MPTR->getHealth() > 0 && WPTR->getHealth() > 0)
	{
		cout << "------------------------------------------------------" << endl;
		double WarriorRoll = WPTR->diceRoll();
		cout << "------------------------------------------------------" << endl;
		double MageRoll = MPTR->diceRoll();
		cout << "------------------------------------------------------" << endl;
		if ( WarriorRoll > MageRoll )
		{

			int userInput;
			cout << "Timaeus the Knight of Destiny's Move:" << endl;
			cout << "What will you do?" << endl;
			cout << "1: Attack" << endl;
			cout << "2: Heal" << endl;
			cin >> userInput;
			if (userInput == 1)
			{
				MPTR->takeD(WPTR->attack());
			}
			else if (userInput == 2)
			{
				WPTR->heal();
			}
			if (MPTR->getHealth() <= 0)
			{
				MPTR.reset();
				break;
			}
			else if (WPTR->getHealth() <= 0)
			{
				WPTR.reset();
				break;
			}
			cout << "------------------------------------------------------" << endl;
			cout << "Time Wizard's Move:" << endl;
			WPTR->takeD(MPTR->attack());
		}
		else if (WarriorRoll < MageRoll)
		{
			cout << "Time Wizard's Move:" << endl;
			WPTR->takeD(MPTR->attack());
			cout << "------------------------------------------------------" << endl;
			if (MPTR->getHealth() <= 0)
			{
				MPTR.reset();
				break;
			}
			else if (WPTR->getHealth() <= 0)
			{
				WPTR.reset();
				break;
			}
			int userInput;
			cout << "Timaeus the Knight of Destiny's Move:" << endl;
			cout << "What will you do?" << endl;
			cout << "1: Attack" << endl;
			cout << "2: Heal" << endl;
			cin >> userInput;
			if (userInput == 1)
			{
				MPTR->takeD(WPTR->attack());
			}
			else if (userInput == 2)
			{
				WPTR->heal();
			}
		}
	}
	//this is where the warrior vs rogue starts
	cout << "------------------------------------------------------" << endl;
	WPTR->fullHeal();//heal warrior back to full hp 
	shared_ptr<Rogue> RPTR = make_shared<Rogue>(); //this creates rogue
	cout << "------------------------------------------------------" << endl;
	WPTR->statDisplay();//shows warrior stats
	cout << "------------------------------------------------------" << endl;
	RPTR->statDisplay();//show rogue stats
	cout << "------------------------------------------------------" << endl;

	while (RPTR->getHealth() > 0 && WPTR->getHealth() > 0)
	{
		
		double WarriorRoll = WPTR->diceRoll();
		cout << "------------------------------------------------------" << endl;
		double RogueRoll = RPTR->diceRoll();
		cout << "------------------------------------------------------" << endl;
		if (WarriorRoll > RogueRoll)
		{
			int userInput;
			cout << "Timaeus the Knight of Destiny's Move:" << endl;
			cout << "What will you do?" << endl;
			cout << "1: Attack" << endl;
			cout << "2: Heal" << endl;
			cin >> userInput;
			if (userInput == 1)
			{
				int evade = rand() % 2 + 1;
				if (evade == 1)
				{
					RPTR->takeD(WPTR->attack());
				}
				else if (evade == 2)
				{
					cout << "Jerry Beans Man rolled to evade!" << endl;
				}
			}
			else if (userInput == 2)
			{
				WPTR->heal();
			}
			if (RPTR->getHealth() <= 0)
			{
				RPTR.reset();
				break;
			}
			else if (WPTR->getHealth() <= 0)
			{
				WPTR.reset();
				break;
			}
			cout << "------------------------------------------------------" << endl;
			cout << "Jerry Beans Man's Move:" << endl;
			WPTR->takeD(RPTR->attack());
		}
		else if (WarriorRoll < RogueRoll)
		{
			cout << "Jerry Beans Man's Move:" << endl;
			WPTR->takeD(RPTR->attack());
			cout << "------------------------------------------------------" << endl;
			if (RPTR->getHealth() <= 0)
			{
				RPTR.reset();
				break;
			}
			else if (WPTR->getHealth() <= 0)
			{
				WPTR.reset();
				break;
			}
			int userInput;
			cout << "Timaeus the Knight of Destiny's Move:" << endl;
			cout << "What will you do?" << endl;
			cout << "1: Attack" << endl;
			cout << "2: Heal" << endl;
			cin >> userInput;
			if (userInput == 1)
			{
				RPTR->takeD(WPTR->attack());
			}
			else if (userInput == 2)
			{
				WPTR->heal();
			}
		}
	}
	return 0;
}