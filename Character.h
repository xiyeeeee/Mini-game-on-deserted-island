#pragma once
#include <iostream>
#include <string>
using namespace std;

class Character
{
private:
    int fID;          // Unique identifier for the character
    string fName;     // Name of the character
    int fMaxHP;       // Maximum health points of the character
    int fCurrentHP;   // Current health points of the character
    int fAttack;      // Attack power of the character
    int fArmor;       // Armor rating of the character
    int fSpeed;       // Speed attribute of the character
    static int count; // Static variable to keep track of the total number of characters

public:
    // Default Constructor
    Character() : fID(count), fName(""), fMaxHP(0), fCurrentHP(0), fAttack(0), fArmor(0), fSpeed(0)
    {
        count++;
    }

    // Overloaded Constructor
    Character(string Name, int MaxHP, int CurrentHP, int Attack, int Armor, int Speed) :
        fID(count), fName(Name), fMaxHP(MaxHP), fCurrentHP(CurrentHP),
        fAttack(Attack), fArmor(Armor), fSpeed(Speed)
    {
        count++;
    }

    // Destructor
    ~Character() {}

    // Getters and Setters for private member variables
    int Get_ID() { return fID; }
    void Set_Id(int ID) { fID = ID; }

    string Get_Name() { return fName; }
    void Set_Name(string Name) { fName = Name; }

    int Get_MaxHP() { return fMaxHP; }
    void Set_MaxHP(int MaxHP) { fMaxHP = MaxHP; }

    int Get_CurrentHP() { return fCurrentHP; }
    void Set_CurrentHP(int CurrentHP)
    {
        // Ensure that CurrentHP does not exceed MaxHP or go below 0
        fCurrentHP = CurrentHP > fMaxHP ? fMaxHP : (CurrentHP < 0 ? 0 : CurrentHP);
    }

    int Get_Attack() { return fAttack; }
    void Set_Attack(int Attack) { fAttack = Attack; }

    int Get_Armor() { return fArmor; }
    void Set_Armor(int Armor) { fArmor = Armor; }

    int Get_Speed() { return fSpeed; }
    void Set_Speed(int Speed) { fSpeed = Speed; }

    // Check if the character is alive based on current health
    bool Is_Alive()
    {
        return fCurrentHP > 0;
    }

    // Print character information
    void print()
    {
        cout << "\t\t-----------------------------\n";
        cout << "\t\t" << fName << ":\n";
        cout << "\t\tHP: " << fCurrentHP << "/" << fMaxHP << endl;
        cout << "\t\tAttack: " << fAttack << endl;
        cout << "\t\tArmor: " << fArmor << endl;
        cout << "\t\tSpeed: " << fSpeed << endl;
    }
};

// Initialize the static variable count
int Character::count = 0;
