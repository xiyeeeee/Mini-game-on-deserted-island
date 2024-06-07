#pragma once
#include <string>
#include "Enemy.h"

//Derived from base class Enemy
class PoisonousCreature : public Enemy
{
private:
	//unique attribute
	static int poison_hurt;

	int fPoison_hurt;
public:
	//Default Constructor
	PoisonousCreature() : Enemy(), fPoison_hurt(0) {}

	//Overloaded Constructor 
	PoisonousCreature(string Name, int Level) :
		fPoison_hurt(0), Enemy(Name, Level)
	{
		fPoison_hurt = poison_hurt + Level;
	}

	//Print out Enemy Status
	void print()
	{
		Character::print();
		cout << "\t\tLevel: " << Get_Level() << endl;
		cout << "\t\tPoison Hurt: " << fPoison_hurt << endl;
		cout << "\t\t-----------------------------\n";
	}

	//Attack another character
	void attack(Player& character)
	{
		int damage = Get_Attack() - character.Get_Armor();
		//Ensures the damage doesnt becomes negative, or else set it to 0
		if (damage < 0)
			damage = 0;
		//PoisonousCreature has an additional damage and should be tackled by Antitoxic items
		int additional_damage = fPoison_hurt - character.Get_Antitoxic_protected();
		if (additional_damage < 0)
			additional_damage = 0;
		damage += additional_damage;
		cout << "\t\t" << Get_Name() << " deal " << damage << " damages to " <<
			character.Get_Name() << endl;
		character.Set_CurrentHP(character.Get_CurrentHP() - damage);
	}
};

//initialize the static variable
//unique attribute for PoisonousCreature
int PoisonousCreature::poison_hurt = 5;

