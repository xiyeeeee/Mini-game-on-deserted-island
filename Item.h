#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Collection of ItemType
enum ItemType { itNone, itCure, itAttack, itArmor, itSpeed, itAntitoxic, itInsulates };
class Item
{
private:
	string fName;
	int fValue;
	int fGold;
	ItemType fType;
public:
	//Dsefault Constructor
	Item() : fName(""), fValue(0), fGold(0), fType(itNone) {}

	//Overloaded Constructor 
	Item(string Name, int Value, int Gold, ItemType Type) :
		fName(Name), fValue(Value), fGold(Gold), fType(Type) {}

	//Getters and Setters
	string Get_Name() { return fName; }
	void Set_Name(string Name) { fName = Name; }

	int Get_Value() { return fValue; }
	void Set_Value(int Value) { fValue = Value; }

	int Get_Gold() { return fGold; }
	void Set_Gold(int Gold) { fGold = Gold; }

	ItemType Get_Type() { return fType; }
	void Set_Type(ItemType Type) { fType = Type; }

	//Display item details
	void print() const
	{
		cout << "\t\t-----------------------------\n";
		cout << "\t\t" << fName << ":\n";
		switch (fType)
		{
		case itCure:
			cout << "\t\tHP +" << fValue << endl;
			break;
		case itAttack:
			cout << "\t\tAttack +" << fValue << endl;
			break;
		case itArmor:
			cout << "\t\tArmor +" << fValue << endl;
			break;
		case itSpeed:
			cout << "\t\tSpeed +" << fValue << endl;
			break;
		case itAntitoxic:
			cout << "\t\tPoison Hurt -" << fValue << endl;
			break;
		case itInsulates:
			cout << "\t\Electrical Hurt -" << fValue << endl;
			break;
		}
		cout << "\t\tGold: " << fGold << endl;
		cout << "\t\t-----------------------------\n";
	}

	// Save item details to an output stream
	void save(ofstream& of)
	{
		of << *this;  // Calls the friend operator<<
	}

	// Friend operator overloading for printing item information
	friend ostream& operator<<(ostream& os, Item& item)
	{
		os << item.fName << "\n" << item.fValue << "\t"
			<< item.fGold << "\t" << item.fType << endl;
		return os;
	}
};



