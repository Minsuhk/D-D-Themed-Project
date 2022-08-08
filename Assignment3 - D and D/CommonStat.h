#ifndef CommonStat_h
#define CommonStat_h

class CommonStat
{
protected:
	double health;
	double armor;
	int attMod;
public:
	CommonStat()
	{
		health = 20;
		armor = 20;
		attMod = 0;
	}
	CommonStat(double h, double a, int att)
	{
		health = h;
		armor = a;
		attMod = att;
	}
	//virtual functions 
	virtual void setHealth(double h) = 0;
	virtual double getHealth() = 0;
	virtual double attack() = 0;
	virtual void takeD(double d) = 0;
	virtual void heal() = 0;
	virtual void statDisplay() = 0;
	virtual double diceRoll() = 0;
	virtual void fullHeal() = 0;

};

#endif