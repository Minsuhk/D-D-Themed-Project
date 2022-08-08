#ifndef Warrior_h
#define Warrior_h
#include "CommonStat.h"
#include <time.h>
using namespace std;

class Warrior : public CommonStat
{
private:
	int initiativeMod;
public:
	Warrior() : CommonStat()
	{
		cout << "You are now Timaeus the Knight of Destiny!" << endl;
		health = 20;
		armor = 5;
		attMod = 3;
		initiativeMod = 4;
	}
	Warrior(int i, double h, double a, int att) : CommonStat(h, a, att)
	{
		cout << "You are now Timaeus the Knight of Destiny!" << endl;
		initiativeMod = i;
		health = h;
		armor = a;
		attMod = att;
	}
	~Warrior()
	{
		cout << "The game is now over :3" << endl;
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
		int random = rand() % 10 + 1; 
		int dmg = random + attMod;
		cout << "Timaeus swings for " << dmg << " damage!" << endl;
		return dmg;
	}
	void takeD(double dmg)
	{
		if (armor > dmg)
		{
			cout << "Timaeus's armor is just too good" << endl;
		}
		health = health - (dmg-armor);
		if (health <= 0)
		{
			health = 0;
		}
		cout << "Timaeus has taken " << (dmg-armor) << " and now has " << health << " HP" << endl;
	}
	void heal()
	{
		int random = rand() % 10 + 1;
		cout << "Timaeus drinks a potion! He restores " << random << " HP!" << endl;
		health += random;
		if (health >= 20)
		{
			health = 20;
			cout << "You can't overheal, max HP reached" << endl;
		}
		cout << "Timaeus HP is now at " << health << " HP!" << endl;
	}
	void statDisplay()
	{
		cout << "Timaeus the Knight of Destiny's current stats:" << endl;
		cout << "Health: " << getHealth() << endl;
		cout << "Healing Die: 2 D5" << endl;
		cout << "Base Attack Die: 1 D6" << endl;
		cout << "Armor: " << armor << endl;
		cout << "Attack Modifier (Strength): " << attMod << endl;
		cout << "Initiative Modifier (Speed): " << initiativeMod << endl;
	}
	double diceRoll()
	{
		int random = rand() % 20 + 1;
		int result = random + initiativeMod;
		cout << "You rolled one dice (1 to 20): Initiative score of " << random << " + a speed modifier of " << initiativeMod << " for a total of " << result << endl;
		return result;
	}
	void fullHeal()
	{
		cout << "The Heart of the Cards have blessed you! Health has been reset back to 20!" << endl;
		health = 20;
	}
};

#endif