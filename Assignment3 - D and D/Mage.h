#ifndef Mage_h
#define Mage_h
#include "CommonStat.h"
#include <time.h>
using namespace std;

class Mage : public CommonStat
{
private:

public:
	Mage() : CommonStat()
	{
		cout << "Time Wizard Approaches!" << endl;
		health = 15;
		armor = 2;
		attMod = 7;
	}
	Mage(double h, double a, int att) : CommonStat(h, a, att)
	{
		cout << "Time Wizard Approaches!" << endl;
		health = h;
		armor = a;
		attMod = att;
	}
	~Mage()
	{
		cout << "Time Wizard has no HP left!" << endl;
	}
	void setHealth(double h)
	{
		health = h;
	}
	double getHealth()
	{
		return health;
	}
	double attack()
	{
		int random = rand() % 4 + 1;
		int dmg = random + attMod;
		cout << "Time Wizard shakes his staff for " << dmg << " damage!" << endl;
		return dmg;
	}
	void takeD(double dmg)
	{
		if (armor > dmg)
		{
			cout << "Time Wizard's armor is just too good" << endl;
		}
		health = health - (dmg - armor);
		if (health <= 0)
		{
			health = 0;
		}
		cout << "Time Wizard has taken " << (dmg - armor) << " and now has " << health << " HP" << endl;
	}
	void heal()
	{
		int random = rand() % 10 + 1;
		cout << "Time Wizard turns back time! He restores " << random << " HP!" << endl;
		health += random;
	}
	void statDisplay()
	{
		cout << "Time Wizard:" << endl;
		cout << "Health: " << getHealth() << endl;
		cout << "Base Attack Die: 1 D4" << endl;
		cout << "Armor: " << armor << endl;
		cout << "Attack Modifier (Intellect): " << attMod << endl;
	}
	double diceRoll()
	{
		int random = rand() % 20 + 1;
		cout << "Time Wizard rolled one dice (1 to 20): Initiative score of " << random << " but has no speed modifiers." << endl;
		return random;
	}
	void fullHeal()
	{
		health = 15;
	}
};

#endif
