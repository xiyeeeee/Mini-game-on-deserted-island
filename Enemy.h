#pragma once
#include <iostream>
#include "Character.h"
#include "Player.h"

using namespace std;
//Enemy Introduction
const string enemy_introduce = "\t\t---List of Enemies---\n"\
"\t\t1.Piranha\n"\
"\t\t2.Spider\n"\
"\t\t3.Electric Eel\n"\
"\t\t4.Green Anaconda\n"\
"\t\t5.Poison Dart Frog\n"\
"\t\t6.Jaguar\n"\
"\t\t7.Sun Bear\n"\
"\t\t-------------------------------\n";

//Derived from base class Character
class Enemy : public Character
{
private:
	static int enemy_hp;
	static int enemy_attack;
	static int enemy_armor;
	static int enemy_speed;
	static int level_up_value;
	int fLevel;
public:
	//Default Constructor
	Enemy() : Character(), fLevel(0) {}

	//Overloaded Constructor always use in new game
	Enemy(string Name, int Level) :
		Character(Name, enemy_hp, enemy_hp, enemy_attack, enemy_armor, enemy_speed)
	{
		fLevel = Level;
		Level--;
		int up_value = Level * level_up_value;
		Set_MaxHP(enemy_hp + up_value);
		Set_CurrentHP(enemy_hp + up_value);
		Set_Attack(enemy_attack + up_value);
	}

	//Getters and Setters
	int Get_Level() { return fLevel; }
	void Set_Level(int Level) { fLevel = Level; }

	//Enemy For This Level
	void show_intro()
	{
		cout << enemy_introduce << endl;
		cout << "\t\tThere is a " << Get_Name() << " here." << endl;
		cout << "\t\tYou should beat it." << endl;
	}

	//virtual print method to allow polymorphism in derived classes
	virtual void print()
	{
		Character::print();
		cout << "\t\tLevel: " << fLevel << endl;
		cout << "\t\t-----------------------------\n";
	}

	//virtual attack method to allow polymorphism in derived classes
	virtual void attack(Player& character)
	{
		int damage = Get_Attack() - character.Get_Armor();
		if (damage < 0)
			damage = 0;
		cout << "\t\t" << Get_Name() << " dealt " << damage << " damages to " <<
			character.Get_Name() << endl;
		character.Set_CurrentHP(character.Get_CurrentHP() - damage);
	}

	//friend operator overloading for Enemy attacking another character
	friend Enemy& operator>>(Enemy& attacker, Player& character)
	{
		attacker.attack(character);
		if (character.Get_CurrentHP() == 0)
			cout << "\t\t" << character.Get_Name() << " is dead.\n";
		return attacker;
	}

	//friend operator overloading for printing Enemy information
	friend ostream& operator<<(ostream& os, Enemy& e)
	{
		os << e.Get_Name() << "\n" << e.fLevel << "\t" << e.Get_CurrentHP() << "\n";
		return os;
	}
};

//initialize the static variables
int Enemy::enemy_hp = 20;
int Enemy::enemy_attack = 10;
int Enemy::enemy_armor = 5;
int Enemy::enemy_speed = 15;
int Enemy::level_up_value = 10;
