#pragma once
#include <string>
#include "Character.h"
using namespace std;

const string naturaldisaster_introduce =
"\t\t---List of Weathers---\n"\
"\t\t1.Tornado\n"\
"\t\t2.Forest Fires\n"\
"\t\t3.Thunderstorm\n";

class NaturalDisaster
{
private:
	static int natural_damage;
	static int natural_distance;
	static int level_up_value;

	string fName;
	int fLevel;
	int fDistance;
	int fDamage;
public:
	//default Constructor
	NaturalDisaster() : fName(""), fDistance(0), fDamage(0), fLevel(0) {}

	//Overloaded Constructor always use in new game
	NaturalDisaster(string Name, int Level) :
		fName(Name), fDistance(natural_distance), fDamage(natural_damage)
	{
		fLevel = Level;
		Level--;
		int up_value = Level * level_up_value;
		fDistance += up_value;
		fDamage += up_value;
	}

	//Getters and Setters
	int Get_Level() { return fLevel; }
	void Set_Level(int Level) { fLevel = Level; }

	string Get_Name() { return fName; }
	void Set_Name(string Name) { fName = Name; }

	int Get_Distance() { return fDistance; }
	void Set_Distance(int Distance) { Distance = Distance; }

	int Get_Damage() { return fDamage; }
	void Set_Damage(int Damage) { fDamage = Damage; }

	void show_intro()
	{
		cout << naturaldisaster_introduce << endl;
		cout << "\t\tThere is " << fName << " here." << endl;
		cout << "\t\tYou should escape." << endl;
	}

	void print()
	{
		cout << "\t\t-----------------------------\n";
		cout << "\t\t" << fName << ":\n";
		cout << "\t\tDistance: " << fDistance << endl;
		cout << "\t\tDamage: " << fDamage << endl;
		cout << "\t\t-----------------------------\n";
	}

	void attack(Character& character)
	{
		int damage = fDamage - character.Get_Armor();
		if (damage < 0)
			damage = 0;
		cout << "\t\t" << fName << " dealt " << damage << " damages to " <<
			character.Get_Name() << endl;
		character.Set_CurrentHP(character.Get_CurrentHP() - damage);
	}

	friend NaturalDisaster& operator>>(NaturalDisaster& attacker, Character& character) //friend operator overloading
	{
		attacker.attack(character);
		if (character.Get_CurrentHP() == 0)
			cout << "\t\t" << character.Get_Name() << " is dead.\n";
		return attacker;
	}

	friend ostream& operator<<(ostream& os, NaturalDisaster& n) //friend operator overloading
	{
		os << n.Get_Name() << "\n" << n.fLevel << "\n";
		return os;
	}
};

//we can alter the params free
int NaturalDisaster::natural_damage = 10;
int NaturalDisaster::natural_distance = 40;
int NaturalDisaster::level_up_value = 10;