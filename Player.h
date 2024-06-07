#pragma once
#include "Character.h"
#include "SinglyLinkedList.h"
#include "SinglyLinkedNodeIterator.h"
#include "Stack.h"
#include "Item.h"

// Derived from base class Character
class Player : public Character
{
private:
    static int player_hp;                // Static variable for player's base health
    static int player_attack;            // Static variable for player's base attack
    static int player_armor;             // Static variable for player's base armor
    static int player_speed;             // Static variable for player's base speed
    static int player_gold;              // Static variable for player's initial gold
    static int player_uplevel_experience; // Static variable for player's experience needed to level up
    static int level_up_value;            // Static variable for the value added when leveling up

    int fGold;                           // Player's current gold
    int fLevel;                          // Player's level
    int fExperience;                     // Player's experience points
    int fAntitoxic_protected;            // Player's protection against toxic effects
    int fInsulator_protected;            // Player's protection against electrical effects
    List<Item>* bag;                      // Player's bag (inventory)
    Stack<Item> armors;                    // Player's equipped items(wearing)

public:
    // Default Constructor
    Player() : Character(), fGold(0), fLevel(0), fExperience(0), fAntitoxic_protected(0), fInsulator_protected(0)
    {
        bag = new SinglyLinkedList<Item>;
    }

    // Overloaded Constructor for a new game
    Player(string Name) :
        Character(Name, player_hp, player_hp, player_attack, player_armor, player_speed),
        fGold(player_gold), fLevel(1), fExperience(0), fAntitoxic_protected(0), fInsulator_protected(0)
    {
        bag = new SinglyLinkedList<Item>;
    }

    // Overloaded Constructor for loading an old game
    Player(string Name, int MaxHP, int CurrentHP, int Attack, int Armor, int Speed,
        int Gold, int Level, int Experience, int Antitoxic_protected, int Insulator_protected) :
        Character(Name, MaxHP, CurrentHP, Attack, Armor, Speed),
        fGold(Gold), fLevel(Level), fExperience(Experience),
        fAntitoxic_protected(Antitoxic_protected), fInsulator_protected(Insulator_protected)
    {
        bag = new SinglyLinkedList<Item>;
    }

    // Destructor
    ~Player()
    {
        delete bag;
    }

    // Getters and Setters
    int Get_Gold() { return fGold; }
    void Set_Gold(int Gold) { fGold = Gold; }

    int Get_Level() { return fLevel; }
    void Set_Level(int Level) { fLevel = Level; }

    int Get_Experience() { return fExperience; }
    void Set_Experience(int Experience)
    {
        fExperience = Experience;
        while (fExperience >= player_uplevel_experience)
        {
            fExperience -= player_uplevel_experience;
            level_up();
        }
    }

    int Get_Antitoxic_protected() { return fAntitoxic_protected; }
    int Set_Antitoxic_protected(int Antitoxic_protected)
    {
        fAntitoxic_protected = Antitoxic_protected;
    }

    int Get_Insulator_protected() { return fInsulator_protected; }
    int Set_Insulator_protected(int Insulator_protected)
    {
        fInsulator_protected = Insulator_protected;
    }

    List<Item>* Get_Bag() { return bag; }
    Stack<Item>& Get_Armors() { return armors; }

    // Level up the player
    void level_up()
    {
        ++fLevel;
        Set_MaxHP(Get_MaxHP() + level_up_value);
        Set_CurrentHP(Get_MaxHP());
    }

    // Buy an item
    bool buy(Item item)
    {
        if (fGold >= item.Get_Gold())
        {
            fGold -= item.Get_Gold();
            bag->push_back(item);
            return true;
        }
        else
            return false;
    }

    // Wear an item
    void wear(Item item)
    {
        if (item.Get_Type() == itArmor)
        {
            armors.push(item);//wearing is pushing into stack
            Set_Armor(Get_Armor() + item.Get_Value()); // +Armor
            int speed = Get_Speed() / 2;
            if (speed == 0)
                ++speed;
            Set_Speed(speed); // -Speed because now player is wearing armor
        }
    }
    // Drop an equipped armor
    bool drop(Item& item)
    {
        if (armors.size() > 0)
        {
            if (armors.pop(item))//drop the armor from player's body
            {
                Set_Armor(Get_Armor() - item.Get_Value()); // -Armor
                Set_Speed(Get_Speed() * 2);                // +Speed
                bag->push_back(item);                       // Put armor back into the bag
                return true;
            }
        }
        return false;
    }

    // Retrieve an item from the bag
    bool uses(int index, Item& item)
    {
        index--;//get to the right index for retrieving item
        if (index >= 0 && index < bag->size())//checks if index is valid
        {
            bag->remove(index, item);//retrieve item
            uses(item);
            return true;
        }
        return false;
    }

    // Use an item (e.g., wear armor, consume medication)
    void uses(Item item)
    {
        switch (item.Get_Type())
        {
        case itArmor:
            wear(item);
            break;
        case itCure:
            Set_CurrentHP(Get_CurrentHP() + item.Get_Value());
            break;
        case itAttack:
            Set_Attack(Get_Attack() + item.Get_Value());
            break;
        case itSpeed:
            Set_Speed(Get_Speed() + item.Get_Value());
            break;
        case itAntitoxic:
            fAntitoxic_protected += item.Get_Value();
            break;
        case itInsulates:
            fInsulator_protected += item.Get_Value();
            break;
        }
    }

    // Print the content of the bag
    void print_bag()
    {
        int index = 0;
        cout << "\t\t-----------------------------\n";
        //Uses iterator to loop through bag
        for (auto it = dynamic_cast<SinglyLinkedList<Item>*>(bag)->begin(); it != it.end(); it++)
        {
            cout << "\t\t" << ++index << "." <<
                it.getCurrent()->getValue().Get_Name() << endl;
        }
        cout << "\t\t-----------------------------\n";
    }

    // Print player information
    void print()
    {
        Character::print();
        cout << "\t\tGold: " << fGold << endl;
        cout << "\t\tLevel: " << fLevel << endl;
        cout << "\t\tExperience: " << fExperience << "/" << player_uplevel_experience << endl;
        cout << "\t\t-----------------------------\n";
    }

    // Player attacks another character
    void attack(Character& character)
    {
        int damage = Get_Attack() - character.Get_Armor();
        if (damage < 0)
            damage = 0;
        cout << "\t\t" << Get_Name() << " dealt " << damage << " damages to " <<
            character.Get_Name() << endl;
        character.Set_CurrentHP(character.Get_CurrentHP() - damage);
    }

    // Friend operator overloading for player attacking another character
    friend Player& operator>>(Player& attacker, Character& character)
    {
        attacker.attack(character);
        if (character.Get_CurrentHP() == 0)
            cout << "\t\t" << character.Get_Name() << " is dead.\n";
        return attacker;
    }

    // Friend operator overloading for printing player information
    friend ostream& operator<<(ostream& os, Player& p)
    {
        os << p.Get_Name() << "\n" << p.Get_MaxHP() << "\t" << p.Get_CurrentHP() << "\t"
            << p.Get_Attack() << "\t" << p.Get_Armor() << "\t" << p.Get_Speed() << "\t"
            << p.fGold << "\t" << p.fLevel << "\t" << p.fExperience << "\t"
            << p.fAntitoxic_protected << "\t" << p.fInsulator_protected << "\n";
        return os;
    }
};

// Initialize the static variables
int Player::player_hp = 100;
int Player::player_attack = 10;
int Player::player_armor = 0;
int Player::player_speed = 40;
int Player::player_gold = 100;
int Player::player_uplevel_experience = 100;
int Player::level_up_value = 10;
