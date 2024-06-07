#pragma once
#include <string>
#include "Enemy.h"

//Derived from base class Enemy
class ElectricalCreature : public Enemy
{
private:
	//unique attribute
	static int electrical_hurt;

	int fElectrical_hurt;
public:
	//Default Constructor
	ElectricalCreature() : Enemy(), fElectrical_hurt(0) {}

	//Overloaded Constructor 
	ElectricalCreature(string Name, int Level) :
		fElectrical_hurt(0), Enemy(Name, Level)
	{

		fElectrical_hurt = electrical_hurt + Level;
	}

	//Print out Enemy Status
	void print()
	{
		Character::print();
		cout << "\t\tLevel: " << Get_Level() << endl;
		cout << "\t\tElectrical Hurt: " << fElectrical_hurt << endl;
		cout << "\t\t-----------------------------\n";
	}

	//Attack another character
	void attack(Player& character)
	{
		int damage = Get_Attack() - character.Get_Armor();//Consider player's armor absorbing damage
		//Ensure the damage doesnt becomes nagative, or else set it to 0
		if (damage < 0)
			damage = 0;
		//ElectricalCreature has an additional damage and can only be tackled by Insulator
		int additional_damage = fElectrical_hurt - character.Get_Insulator_protected();
		if (additional_damage < 0)
			additional_damage = 0;
		damage += additional_damage;
		cout << "\t\t" << Get_Name() << " deal " << damage << " damages to " <<
			character.Get_Name() << endl;
		character.Set_CurrentHP(character.Get_CurrentHP() - damage);
	}
};

//initialize the static variable
//unique attribute for ElectricalCreature
int ElectricalCreature::electrical_hurt = 5;
