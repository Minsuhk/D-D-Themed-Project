#ifndef Rogue_h
#define Rogue_h
#include "CommonStat.h"
#include <time.h>
using namespace std;


class Rogue : public CommonStat
{
private:
	int initiativeMod;
	double dodge;
public:
	Rogue() : CommonStat()
	{
		cout << "Jerry Beans Man Approaches!" << endl;
		health = 10;
		armor = 3;
		attMod = 4;
		initiativeMod = 5;
		dodge = 0.50;
	}
	Rogue(int i, double d, double h, double a, int att) : CommonStat(h, a, att)
	{
		cout << "Jerry Beans Man Approaches!" << endl;
		initiativeMod = i;
		dodge = d;
		health = h;
		armor = a;
		attMod = att;
	}
	~Rogue()
	{
		cout << "Jerry Beans Man has no HP left!" << endl;
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
		int random = rand() % 8 + 1;
		int dmg = random + attMod;
		cout << "Jerry Beans Man stabs with his sword for " << dmg << " damage!" << endl;
		return dmg;
	}
	void takeD(double dmg)
	{
		if (armor > dmg)
		{
			cout << "Jerry Beans Man's armor is just too good" << endl;
		}
		health = health - (dmg - armor);
		if (health <= 0)
		{
			health = 0;
		}
		cout << "Jerry Beans Man has taken " << (dmg - armor) << " and now has " << health << " HP" << endl;
	}
	void heal()
	{
		int random = rand() % 10 + 1;
		cout << "Jerry Beans Man eats jelly beans! He restores " << random << " HP!" << endl;
		health += random;
	}
	void statDisplay()
	{
		cout << "Jerry Beans Man:" << endl;
		cout << "Health: " << getHealth() << endl;
		cout << "Base Attack Die: 2 D4" << endl;
		cout << "Armor: " << armor << endl;
		cout << "Attack Modifier (Agility): " << attMod << endl;
		cout << "Initiative Modifier (Speed): " << initiativeMod << endl;
		cout << "Dodge: " << dodge << " chance to dodge an incoming attack" << endl;
	}
	double diceRoll()
	{
		int random = rand() % 20 + 1;
		int result = random + initiativeMod;
		cout << "Jerry Beans Man rolled one dice (1 to 20): Initiative score of " << random << " + a speed modifier of " << initiativeMod << " for a total of " << result << endl;
		return result;
	}
	void fullHeal()
	{
		health = 10;
	}
};

#endif


