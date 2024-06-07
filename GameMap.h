#pragma once
#include <iostream>
#include <string>
#include "Tree.h"
#include "Player.h"
#include "Enemy.h"
#include "PoisonousCreature.h"
#include "ElectricalCreature.h"
#include "NaturalDisaster.h"
using namespace std;

enum EnemyType { etNone, etNaturalDisaster, etEnemy, etPoisonous, etElectric };

class GameMap
{
private:
	string fName;
	int fIndex;
	int fLevel;
	EnemyType fType;
	Enemy* enemy;
	NaturalDisaster* disaster;
public:
	//default Constructor
	GameMap() : fName(""), fIndex(0), fLevel(0), fType(etNone), enemy(nullptr), disaster(nullptr) {}

	//Overloaded Constructor
	GameMap(string Name, int Index, int Level, EnemyType Type) :
		fName(Name), fIndex(Index), fLevel(Level), fType(Type), enemy(nullptr), disaster(nullptr)
	{
		switch (fType)
		{
		case etNaturalDisaster:
			disaster = new NaturalDisaster(Name, Level);
			break;
		case etEnemy:
			enemy = new Enemy(Name, Level);
			break;
		case etPoisonous:
			enemy = new PoisonousCreature(Name, Level);
			break;
		case etElectric:
			enemy = new ElectricalCreature(Name, Level);
			break;
		}
	}

	//Destructor
	~GameMap()
	{
		if (enemy)
			delete enemy;
		if (disaster)
			delete disaster;
	}

	//Getters and Setters
	string Get_Name() { return fName; }
	void Set_Name(string Name) { fName = Name; }

	int Get_Level() { return fLevel; }
	void Set_Level(int Level) { fLevel = Level; }

	EnemyType Get_Type() { return fType; }
	void Set_Type(EnemyType Type) { fType = Type; }

	Enemy* Get_Enemy() { return enemy; }
	NaturalDisaster* Get_NaturalDisaster() { return disaster; }

	void Map_intro()
	{
		if (fType == etNaturalDisaster)
			disaster->show_intro();
		else
			enemy->show_intro();
	}

	//friend operator overloading
	friend ostream& operator<<(ostream& os, GameMap& map)
	{
		os << map.fName << "\n" << map.fIndex << "\t" << map.fLevel << "\t" << map.fType << endl;
		return os;
	}
};
